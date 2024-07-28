/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAl
 * SWC    : USART
 * Version: 1.0
 * Created: OCT/27/2023
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_private.h"
#include "USART_config.h"
#include "USART_register.h"
#include "USART_interface.h"

u8 USART_u8CallBack(u8 Copy_u8Interrupt, void (*CallBackFunc)(void));
void USART_voidSendCharISR();
void USART_voidReceiveCharISR();
void USART_voidSendStringISR();
void USART_voidReceiveStringISR();

static u8 USART_u8BusyStat=IDL;
static u8* CharSendReceive=NULL;

static void (*Notification)(void)=NULL;
static void (*USART_voidRXCISR)(void)=NULL;
static void (*USART_voidUDREISR)(void)=NULL;
static void (*USART_voidTXCISR)(void)=NULL;		  

void USART_voidInit(void)
{
	u8 Local_u8RegSet=0;
	u16 Local_u16BaudRate=0;
	
	/*INITIAL VALUE TO SET DATA TO ONE TO ACCESS UCSRC REGISTER AND NOT UBRRH*/
	SET_BIT(Local_u8RegSet,UCSRC_URSEL);

	/*SET STOP BIT AS ONE STOP BIT*/
	Local_u8RegSet|=(GET_BIT(STOP_BIT,0)<<UCSRC_USBS);

	/*NO PARITY*/
	Local_u8RegSet|=(GET_BIT(PARITY_MODE,0)<<UCSRC_UPM0);
	Local_u8RegSet|=(GET_BIT(PARITY_MODE,1)<<UCSRC_UPM1);

	/*8 DATABITS*/
	Local_u8RegSet|=(GET_BIT(CHAR_SIZE,0)<<UCSRC_UCSZ0);
	Local_u8RegSet|=(GET_BIT(CHAR_SIZE,1)<<UCSRC_UCSZ1);
	UCSRB|=(GET_BIT(CHAR_SIZE,2)<<UCSRB_UCSZ2);
	
	/*NO INTERRUPT*/

	/*ASYNCHRONOUS*/
	Local_u8RegSet|=(GET_BIT(USART_MODE_SELECT,0)<<UCSRC_UMSEL);
	
	/*SET DATA TO UCSRC REG*/
	UCSRC=Local_u8RegSet;
	
	/*CHECK U2X BIT (DOUBLE SPEED MODE)*/
	if ((GET_BIT(UCSRA,UCSRA_U2X)==0) && (USART_MODE_SELECT == USART_ASYNCHRONOUS))
	{
		Local_u16BaudRate=(8000000/(16*(u16)USART_BAUD_RATE))-1;
	}
	else if ((GET_BIT(UCSRA,UCSRA_U2X)==1) && (USART_MODE_SELECT == USART_ASYNCHRONOUS))
	{
		Local_u16BaudRate=(8000000/(8*(u16)USART_BAUD_RATE))-1;
	}
	else if (USART_MODE_SELECT == USART_SYNCHRONOUS)
	{
		Local_u16BaudRate=(8000000/(2*(u16)USART_BAUD_RATE))-1;
	}
	UBRRL=(u8)Local_u16BaudRate;
	UBRRH=Local_u16BaudRate>>8;
	
	/*ENABEL TXB*/
	SET_BIT(UCSRB,UCSRB_TXEN);
	/*ENABLE RXB*/
	SET_BIT(UCSRB,UCSRB_RXEN);
}

u8 USART_u8SendCharSynch(u8* Copy_u8Data)
{
	u8 Local_u8TimeOut=0;
	if (Copy_u8Data!=NULL)
	{
		if (USART_u8BusyStat==IDL)
		{
			USART_u8BusyStat=BUSY;
			
			/*WAIT UNTIL THE DATA BUFFER IS EMPTY WITH TIMEOUT CONCEPT*/
			while((GET_BIT(UCSRA,UCSRA_UDRE)==0) && (Local_u8TimeOut!=USART_TimeOut_Iteraton_num))
			{
				Local_u8TimeOut++;
			}
			
			if (Local_u8TimeOut==USART_TimeOut_Iteraton_num)
			{
				USART_u8BusyStat=IDL;
				return TimeOut;
			} 
			else
			{
				/*SENDING DATA(WRITE TO UDR REGISTER TO ACCESS TXB)*/
				UDR=*Copy_u8Data;
				
				USART_u8BusyStat=IDL;
				return CLEAR;
			}
		} 
		else
		{
			return BUSY;
		}
	} 
	else
	{
		return NULL_POINTER;
	}
}

u8 USART_u8ReceiveCharSynch(u8* Copy_u8Data)
{
	u8 Local_u8TimeOut=0;
	if (Copy_u8Data!=NULL)
	{
		if (USART_u8BusyStat==IDL)
		{
			USART_u8BusyStat=BUSY;
			
			/*WAIT UNTIL THE DATA IS RECEIVED WITH TIMEOUT CONCEPT*/
			while((GET_BIT(UCSRA,UCSRA_RXC)==0) && (Local_u8TimeOut!=USART_TimeOut_Iteraton_num))
			{
				Local_u8TimeOut++;
			}
			
			if (Local_u8TimeOut==USART_TimeOut_Iteraton_num)
			{
				USART_u8BusyStat=IDL;
				return TimeOut;
			} 
			else
			{
				/*RECEIVING DATA(READ UDR REGISTER TO ACCESS RXB)*/
				*Copy_u8Data=UDR;
				
				USART_u8BusyStat=IDL;
				return CLEAR;
			}
	
		} 
		else
		{
			return BUSY;
		}
	} 
	else
	{
		return NULL_POINTER;
	}
}

u8 USART_u8SendStringSynch(u8* Copy_u8String)
{
	u8 Local_u8Iterator=0, Local_u8ReturnCheck;
	if (Copy_u8String!=NULL)
	{
		/*SEND FIRST CHARACTER*/
		Local_u8ReturnCheck=USART_u8SendCharSynch(&Copy_u8String[Local_u8Iterator]);
		
		/*CHECK IF THE SENDING FUNCTION DIDN'T RETURN WITH AN ERROR*/
		if (Local_u8ReturnCheck==BUSY)
		{
			return BUSY;
		}
		else if (Local_u8ReturnCheck==TimeOut)
		{
			return TimeOut;
		}
		else
		{
			/*CHECK IF THE SENT CHARACTER ISN'T EQUAL NULL*/
			while (Copy_u8String[Local_u8Iterator]!='\0')
			{
				/*GO TO NEXT CHARACTER*/
				Local_u8Iterator++;
				
				/*KEEP SENDING*/	
				USART_u8SendCharSynch(&Copy_u8String[Local_u8Iterator]);
			}
			return CLEAR;
		}
		
	}
	else
	{
		return NULL_POINTER;
	}
}

u8 USART_u8ReceiveStringSynch(u8* Copy_u8String)
{
	u8 Local_u8Iterator=0, Local_u8ReturnCheck;
	if (Copy_u8String!=NULL)
	{
		/*RECEIVE FIRST CHARACTER*/
		Local_u8ReturnCheck=USART_u8ReceiveCharSynch(&Copy_u8String[Local_u8Iterator]);
		
		/*CHECK IF THE RECEIVING FUNCTION DIDN'T RETURN WITH AN ERROR*/
		if (Local_u8ReturnCheck==BUSY)
		{
			return BUSY;
		}
		else if (Local_u8ReturnCheck==TimeOut)
		{
			return TimeOut;
		}
		else
		{
			/*CHECK IF THE RECEIVED CHARACTER ISN'T EQUAL NULL*/
			while (Copy_u8String[Local_u8Iterator]!='\0')
			{
				/*GO TO NEXT CHARACTER*/
				Local_u8Iterator++;
				
				/*KEEP RECEIVING*/
				USART_u8ReceiveCharSynch(&Copy_u8String[Local_u8Iterator]);
			}
			return CLEAR;
		}
		
	}
	else
	{
		return NULL_POINTER;
	}
}


u8 USART_u8SendCharASynch(u8* Copy_u8Char, void (*NotificationFunc)(void))
{
	if ((NotificationFunc!=0) && (Copy_u8Char!=0))
	{
		if (USART_u8BusyStat==IDL)
		{
			USART_u8BusyStat=BUSY;
			
			/*SET PASSED REFERANCES TO GLOBAL POINTRES SO THE ISR FUNCTION COULD US IT*/
			CharSendReceive = Copy_u8Char;
			Notification=NotificationFunc;
			USART_u8CallBack(USART_UDRE,&USART_voidSendCharISR);
			return CLEAR;
		}
		else
		{
			return BUSY;
		}
	} 
	else
	{
		return NULL_POINTER;
	}
}

void USART_voidSendCharISR()
{
	/*SET BUSY STATE IDL*/
	USART_u8BusyStat=IDL;
	
	/*SET DATA TO UDR TO BE SEND*/
	UDR=*CharSendReceive;
	
	/*CLEAR INTERRUPT BIT*/
	CLR_BIT(UCSRB, UCSRB_UDRIE);
	
	/*CALL NOTIFICATION FUNCTION*/
	Notification();
	
}

u8 USART_u8ReceiveCharASynch(u8* Copy_u8Char, void (*NotificationFunc)(void))
{
	if ((NotificationFunc!=0) && (Copy_u8Char!=0))
	{
		if (USART_u8BusyStat==IDL)
		{
			USART_u8BusyStat=BUSY;
			/*SET PASSED REFERANCES TO GLOBAL POINTRES SO THE ISR FUNCTION COULD US IT*/
			CharSendReceive = Copy_u8Char;
			Notification=NotificationFunc;
			USART_u8CallBack(USART_RXC,&USART_voidReceiveCharISR);
			return CLEAR;
		} 
		else
		{
			return BUSY;
		}
	}
	else
	{
		return NULL_POINTER;
	}
}

void USART_voidReceiveCharISR()
{
	/*SET BUSY STATE IDL*/
	USART_u8BusyStat=IDL;
	
	/*READ UDR REGISTER(CHARACTER RECEIVED)*/
	*CharSendReceive=UDR;
	
	/*CLEAR INTERRUPT BIT*/
	CLR_BIT(UCSRB,UCSRB_RXCIE);
	
	/*CALL NOTIFICATION FUNCTION*/
	Notification();
}

u8 USART_u8SendStringASynch(u8* Copy_u8String, void (*NotificationFunc)(void))
{
	if ((Copy_u8String!=NULL) && (NotificationFunc!=NULL))
	{
		if (USART_u8BusyStat==IDL)
		{
			USART_u8BusyStat=BUSY;	
			
			/*SET PASSED REFERANCES TO GLOBAL POINTRES SO THE ISR FUNCTION COULD US IT*/
			CharSendReceive=Copy_u8String;
			Notification=NotificationFunc;
			USART_u8CallBack(USART_UDRE,&USART_voidSendStringISR);
			return CLEAR;
		} 
		else
		{
			return BUSY;
		}
	} 
	else
	{
		return NULL_POINTER;
	}
}

void USART_voidSendStringISR()
{
	static u8 Local_u8Iterator=0;
	
	if (CharSendReceive[Local_u8Iterator]!='\0')
	{
		/*SET DATA TO UDR TO BE SEND*/
		UDR=CharSendReceive[Local_u8Iterator];
		Local_u8Iterator++;
	}
	else
	{
		USART_u8BusyStat=IDL;
		
		/*SEND LAST CHARACTAR(NULL CHAR) WHICH IS '\0'*/
		UDR=CharSendReceive[Local_u8Iterator];
		
		Local_u8Iterator=0;
		
		/*CLEAR INTERRUPT BIT*/
		CLR_BIT(UCSRB, UCSRB_UDRIE);
		
		/*CALL NOTIFICATION FUNCTION*/
		Notification();
	}
}

u8 USART_u8ReceiveStringASynch(u8* Copy_u8String, void (*NotificationFunc)(void))
{
	if ((Copy_u8String!=NULL) && (NotificationFunc!=NULL))
	{
		if (USART_u8BusyStat==IDL)
		{
			USART_u8BusyStat=BUSY;
			
			/*SET PASSED REFERANCES TO GLOBAL POINTRES SO THE ISR FUNCTION COULD US IT*/
			CharSendReceive = Copy_u8String;
			Notification=NotificationFunc;
			USART_u8CallBack(USART_RXC, &USART_voidReceiveStringISR);
			return CLEAR;
		} 
		else
		{
			return BUSY;
		}
	}
	else
	{
		return NULL_POINTER;
	}
}

void USART_voidReceiveStringISR()
{
	static u8 Local_u8ReceiveIterator=0;
	/*READ UDR REGISTER(CHARACTER RECEIVED)*/
	CharSendReceive[Local_u8ReceiveIterator]=UDR;
	
	if (CharSendReceive[Local_u8ReceiveIterator]!='\0')
	{
		Local_u8ReceiveIterator++;
	}
	else
	{
		/*SET BUSY STATE IDL*/
		USART_u8BusyStat=IDL;
		
		Local_u8ReceiveIterator=0;
		
		/*CLEAR INTERRUPT BIT*/
		CLR_BIT(UCSRB,UCSRB_RXCIE);
		
		/*CALL NOTIFICATION FUNCTION*/
		Notification();
	}
	
}

/*FUNCTION TO ENABLE INTERRUPT AND SET FUNCTION TO USART ISR*/
u8 USART_u8CallBack(u8 Copy_u8Interrupt, void (*CallBackFunc)(void))
{
	if (CallBackFunc!=NULL)
	{
		switch(Copy_u8Interrupt)
		{
			case USART_RXC	:  USART_voidRXCISR = CallBackFunc; SET_BIT(UCSRB,UCSRB_RXCIE); return CLEAR; break;
			case USART_UDRE	:  USART_voidUDREISR= CallBackFunc; SET_BIT(UCSRB,UCSRB_UDRIE); return CLEAR; break;
			case USART_TXC	:  USART_voidTXCISR = CallBackFunc; SET_BIT(UCSRB,UCSRB_TXCIE); return CLEAR; break;
			default: return ERROR;
		}
	} 
	else
	{
		return NULL_POINTER;
	}
}

void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	USART_voidRXCISR();
}

void __vector_14(void) __attribute__((signal));
void __vector_14(void)
{
	USART_voidUDREISR();
}

void __vector_15(void) __attribute__((signal));
void __vector_15(void)
{
	USART_voidTXCISR();
}