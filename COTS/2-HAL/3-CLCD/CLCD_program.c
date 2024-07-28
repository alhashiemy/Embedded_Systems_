/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : HAL
 * SWC    : CLCD
 * Version: 1.0
 * Created: JUN/10/2024
 */

#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"


static u8 RowIndex=0;
static u8 ColumIndex=1;
static u16 LineAddress[]=CLCD_LINE_ADDRESSES;
static u8 GoToXYBusyState=IDL;

void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/*SET RS PIN LOW FOR COMMAND*/
	GPIO_u8SetPinValue(CLCD_RS_PIN, GPIO_u8PIN_LOW);
	
	/*SET RW PIN LOW FOR WRITE*/
	GPIO_u8SetPinValue(CLCD_RW_PIN, GPIO_u8PIN_LOW);
	
	#if (BUS_MODE==CLCD_EIGHT_BIT)
		
	/*SEND DATA*/
	GPIO_u8SetPinValue(CLCD_DATA_PIN0, GET_BIT(Copy_u8Command,0));
	GPIO_u8SetPinValue(CLCD_DATA_PIN1, GET_BIT(Copy_u8Command,1));
	GPIO_u8SetPinValue(CLCD_DATA_PIN2, GET_BIT(Copy_u8Command,2));
	GPIO_u8SetPinValue(CLCD_DATA_PIN3, GET_BIT(Copy_u8Command,3));
	GPIO_u8SetPinValue(CLCD_DATA_PIN4, GET_BIT(Copy_u8Command,4));
	GPIO_u8SetPinValue(CLCD_DATA_PIN5, GET_BIT(Copy_u8Command,5));
	GPIO_u8SetPinValue(CLCD_DATA_PIN6, GET_BIT(Copy_u8Command,6));
	GPIO_u8SetPinValue(CLCD_DATA_PIN7, GET_BIT(Copy_u8Command,7));
	
	/*SET ENABLE PULSE*/
	GPIO_u8SetPinValue(CLCD_E_PIN, GPIO_u8PIN_HIGH);
	_delay_ms(2);
	GPIO_u8SetPinValue(CLCD_E_PIN, GPIO_u8PIN_LOW);
	
	#elif (BUS_MODE==CLCD_FOUR_BIT)
		
	/*SEND FIRST 4 BITS OF DATA*/
	GPIO_u8SetPinValue(CLCD_DATA_PIN4, GET_BIT(Copy_u8Command,4));
	GPIO_u8SetPinValue(CLCD_DATA_PIN5, GET_BIT(Copy_u8Command,5));
	GPIO_u8SetPinValue(CLCD_DATA_PIN6, GET_BIT(Copy_u8Command,6));
	GPIO_u8SetPinValue(CLCD_DATA_PIN7, GET_BIT(Copy_u8Command,7));
	
	/*SET ENABLE PULSE*/
	GPIO_u8SetPinValue(CLCD_E_PIN, GPIO_u8PIN_HIGH);
	_delay_ms(2);
	GPIO_u8SetPinValue(CLCD_E_PIN, GPIO_u8PIN_LOW);
	
	Copy_u8Command = (Copy_u8Command<<4);
	
	/*SEND LAST 4 BITS OF DATA*/
	GPIO_u8SetPinValue(CLCD_DATA_PIN4, GET_BIT(Copy_u8Command,4));
	GPIO_u8SetPinValue(CLCD_DATA_PIN5, GET_BIT(Copy_u8Command,5));
	GPIO_u8SetPinValue(CLCD_DATA_PIN6, GET_BIT(Copy_u8Command,6));
	GPIO_u8SetPinValue(CLCD_DATA_PIN7, GET_BIT(Copy_u8Command,7));
	
	/*SET ENABLE PULSE*/
	GPIO_u8SetPinValue(CLCD_E_PIN, GPIO_u8PIN_HIGH);
	_delay_ms(2);
	GPIO_u8SetPinValue(CLCD_E_PIN, GPIO_u8PIN_LOW);
	
	#endif
}


void CLCD_voidSendData(u8 Copy_u8Data)
{
	
	/*SET RS PIN HIGH FOR DATA*/
	GPIO_u8SetPinValue(CLCD_RS_PIN, GPIO_u8PIN_HIGH);
	
	/*SET RW PIN LOW FOR WRITE*/
	GPIO_u8SetPinValue(CLCD_RW_PIN, GPIO_u8PIN_LOW);
	
	#if	(BUS_MODE==CLCD_EIGHT_BIT)
	
	/*SEND DATA*/
	GPIO_u8SetPinValue(CLCD_DATA_PIN0, GET_BIT(Copy_u8Data,0));
	GPIO_u8SetPinValue(CLCD_DATA_PIN1, GET_BIT(Copy_u8Data,1));
	GPIO_u8SetPinValue(CLCD_DATA_PIN2, GET_BIT(Copy_u8Data,2));
	GPIO_u8SetPinValue(CLCD_DATA_PIN3, GET_BIT(Copy_u8Data,3));
	GPIO_u8SetPinValue(CLCD_DATA_PIN4, GET_BIT(Copy_u8Data,4));
	GPIO_u8SetPinValue(CLCD_DATA_PIN5, GET_BIT(Copy_u8Data,5));
	GPIO_u8SetPinValue(CLCD_DATA_PIN6, GET_BIT(Copy_u8Data,6));
	GPIO_u8SetPinValue(CLCD_DATA_PIN7, GET_BIT(Copy_u8Data,7));
	
	/*SET ENABLE PULSE*/
	GPIO_u8SetPinValue(CLCD_E_PIN, GPIO_u8PIN_HIGH);_delay_ms(2);
	GPIO_u8SetPinValue(CLCD_E_PIN, GPIO_u8PIN_LOW);
	
	#elif (BUS_MODE==CLCD_FOUR_BIT)
	
	/*SEND FIRST 4 BITS OF DATA*/
	GPIO_u8SetPinValue(CLCD_DATA_PIN4, GET_BIT(Copy_u8Data,4));
	GPIO_u8SetPinValue(CLCD_DATA_PIN5, GET_BIT(Copy_u8Data,5));
	GPIO_u8SetPinValue(CLCD_DATA_PIN6, GET_BIT(Copy_u8Data,6));
	GPIO_u8SetPinValue(CLCD_DATA_PIN7, GET_BIT(Copy_u8Data,7));
	
	/*SET ENABLE PULSE*/
	GPIO_u8SetPinValue(CLCD_E_PIN, GPIO_u8PIN_HIGH);_delay_ms(2);
	GPIO_u8SetPinValue(CLCD_E_PIN, GPIO_u8PIN_LOW);
	
	/*SHIFT THE LOWER FOUR BITS OF DATA*/
	Copy_u8Data = (Copy_u8Data<<4);
	
	/*SEND LAST 4 BITS OF DATA*/
	GPIO_u8SetPinValue(CLCD_DATA_PIN4, GET_BIT(Copy_u8Data,4));
	GPIO_u8SetPinValue(CLCD_DATA_PIN5, GET_BIT(Copy_u8Data,5));
	GPIO_u8SetPinValue(CLCD_DATA_PIN6, GET_BIT(Copy_u8Data,6));
	GPIO_u8SetPinValue(CLCD_DATA_PIN7, GET_BIT(Copy_u8Data,7));
	
	/*SET ENABLE PULSE*/
	GPIO_u8SetPinValue(CLCD_E_PIN, GPIO_u8PIN_HIGH);_delay_ms(2);
	GPIO_u8SetPinValue(CLCD_E_PIN, GPIO_u8PIN_LOW);

	#endif
	/*GO TO NEXT ADDRESS IN LCD*/
	CLCD_u8GoToXY(RowIndex,ColumIndex);
}


void CLCD_voidInit(void)
{
	
	/*SET DELAY FOR 40Ms SO CLCD BOOTUP*/
	_delay_ms(40);
	
	#if (BUS_MODE==CLCD_EIGHT_BIT)
	/*SEND COMMAND OF EIGHT BIT MODE*/
	CLCD_voidSendCommand(CLCD_EIGHT_BIT);
	
	#elif (BUS_MODE==CLCD_FOUR_BIT)
	/*SEND COMMAND OF FOUR BIT MODE*/
	CLCD_voidSendCommand(CLCD_RETURN_HOME);
	CLCD_voidSendCommand(CLCD_FOUR_BIT);

	#endif
	
	CLCD_voidSendCommand(CLCD_DISBLAY_ON);
	CLCD_voidSendCommand(CLCD_INCREMENT_DDRAM);
	CLCD_voidSendCommand(CLCD_DISBLAY_CLEAR);
	
}

void CLCD_voidClr(void)
{
	CLCD_voidSendCommand(CLCD_DISBLAY_CLEAR);
}

u8 CLCD_u8SendString(const char* CLCD_Pu8String)
{
	u8 Local_u8ErrorState = CLEAR, Local_u8Counter = 0;
	if (CLCD_Pu8String!=NULL)
	{
		while(CLCD_Pu8String[Local_u8Counter]!='\0')
		{
			CLCD_voidSendData(CLCD_Pu8String[Local_u8Counter]);
			Local_u8Counter++;
		}
	} 
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}

u8 CLCD_u8GoToXY(u8 Copy_u8Row, u8 Copy_u8Colom)
{
	u8 Local_u8ErrorState = CLEAR;
	if (GoToXYBusyState==IDL)
	{
		GoToXYBusyState=BUSY;
		if ((Copy_u8Row<=(CLCD_LINES_NUM-1)) && (Copy_u8Colom<=CLCD_COLUMS_NUM))
		{
			RowIndex=Copy_u8Row;
			ColumIndex=Copy_u8Colom;
			CLCD_voidSendCommand(LineAddress[RowIndex]+ColumIndex);
			ColumIndex++;
			if ((ColumIndex==CLCD_COLUMS_NUM) && (RowIndex<(CLCD_LINES_NUM-1)))
			{
				RowIndex++;
				ColumIndex=0;
			} 
			else if((ColumIndex==CLCD_COLUMS_NUM) && (RowIndex==(CLCD_LINES_NUM-1)))
			{
				RowIndex=0;
				ColumIndex=0;
			}
			GoToXYBusyState=IDL;
		}
		else
		Local_u8ErrorState= ERROR;
	} 
	else
	{
		Local_u8ErrorState= BUSY;
	}
	
	return Local_u8ErrorState;
}


u8 CLCD_u8WriteNewChar(u8* Copy_Pu8Data, u8 Copy_u8BlockNum)
{
	u8 Local_u8ErorrState = CLEAR, Local_u8Counter;
	if (Copy_Pu8Data!=NULL)
	{
		if(Copy_u8BlockNum<=7)
		{
			CLCD_voidSendCommand(CGRAM_FIRST_ADDRISS+(Copy_u8BlockNum*8));
			GoToXYBusyState=BUSY;
			for(Local_u8Counter=0;Local_u8Counter<=7;Local_u8Counter++)
			{
				CLCD_voidSendData(Copy_Pu8Data[Local_u8Counter]);
			}
			GoToXYBusyState=IDL;
			CLCD_u8GoToXY(RowIndex,ColumIndex);
			CLCD_voidSendData(Copy_u8BlockNum);
			
		}
		else
		{
			Local_u8ErorrState = ERROR;
		}
	} 
	else
	{
		Local_u8ErorrState = NULL_POINTER;
	}
		
	return Local_u8ErorrState;

}


void CLCD_voidWriteNUM(u32 Copy_u32NUM)
{
	u8 Local_u8Temp, Local_u8Iterator, Local_u8NUM[10], Local_u8NUM_ASCII[] = "0123456789";
	Local_u8Iterator = 0;
	do
	{
		Local_u8Temp = Copy_u32NUM%10;
		Copy_u32NUM = (Copy_u32NUM-Local_u8Temp)/10;
		Local_u8NUM[Local_u8Iterator] = Local_u8Temp;
		Local_u8Iterator++;
		}while(Copy_u32NUM!=0);
		
	do 
	{
		Local_u8Iterator--;
		CLCD_voidSendData(Local_u8NUM_ASCII[Local_u8NUM[Local_u8Iterator]]);
		}while (Local_u8Iterator!=0);
	
	
}