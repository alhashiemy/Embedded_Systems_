/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAl
 * SWC    : SPI
 * Version: 1.0
 * Created: NOV/5/2023
 */
#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "SPI_config.h"
#include "SPI_private.h"
#include "SPI_register.h"
#include "SPI_interface.h"


static u8 SPI_u8BusyState=IDL;
static u8* SPI_Pu8SendData;
static u8* SPI_Pu8ReceiveData;
void (*SPI_voidNotFunc)(void)=NULL;


void SPI_voidInit(void)
{
	/*SET AS MASTER OR SLAVE*/
	#if SPI_MODE == SPI_SLAVE
	CLR_BIT(SPCR,SPCR_MSTR);
	
	#elif SPI_MODE == SPI_MASTER
	SET_BIT(SPCR,SPCR_MSTR);
	
	/*SET SPEED TO MASTER*/
	SPCR&=0b11111100;
	SPCR|=SPI_CLOCK_RATE;
	
	#endif

	/*SET DATA ORDER MODE*/
	#if SPI_DATA_ORDER == SPI_MSB
	CLR_BIT(SPCR,SPCR_DORD);
	
	#elif SPI_DATA_ORDER == SPI_LSB
	SET_BIT(SPCR,SPCR_DORD);
	
	#endif

	/*SET CLOCK POLARITY*/
	#if SPI_CLOCK_POLARITY == SPI_RISING_FIRST
	CLR_BIT(SPCR,SPCR_CPOL);

	#elif SPI_CLOCK_POLARITY == SPI_FALLING_FIRST
	SET_BIT(SPCR,SPCR_CPOL);

	#endif

	/*SET CLOCK PHASE*/
	#if SPI_CLOCK_PHASE == SPI_SAMPLE_FIRST
	CLR_BIT(SPCR,SPCR_CPHA);

	#elif SPI_CLOCK_PHASE == SPI_SETUP_FIRST
	SET_BIT(SPCR,SPCR_CPHA);

	#endif

	/*SET DOUBLE SPEED MODE*/
	#if SPI_DOUBLE_SPEED == SPI_DOUBLE_SPEED_OFF
	CLR_BIT(SPSR,SPSR_SPI2X);
	
	#elif SPI_DOUBLE_SPEED == SPI_DOUBLE_SPEED_ON
	SET_BIT(SPSR,SPSR_SPI2X);
	
	#endif

	/*ENABLE SPI*/
	SET_BIT(SPCR,SPCR_SPE);

}

u8 SPI_u8TranceiveSynch(u8* Copy_Pu8SendData, u8* Copy_Pu8ReceiveData)
{
	u8 Local_u8TimeOut;
	if ((Copy_Pu8SendData!=NULL) && (Copy_Pu8ReceiveData!=NULL))
	{
		/*CHECK SPI BUSY STATE*/
		if (SPI_u8BusyState==IDL)
		{
			/*SET BUSY STATE OF TRANCEIVE FUNCTION AS BUSY*/
			SPI_u8BusyState=BUSY;
			
			/*CLEAR INTERRUPT BIT TO START TRANCEIVE SYNCHRONOUS*/
			CLR_BIT(SPCR,SPCR_SPIE);
			
			/*SET DATA IN SPI DATA REGISTER TO BE SEND*/
			SPDR=*Copy_Pu8SendData;

STATE1:
			/*SET TIME OUT VARIABLE TO*/
			Local_u8TimeOut=0;
			
			/*WAIT (BUSY WAITING) UNTIL SERIAL TRANSFER IS COMPLET*/
			while((GET_BIT(SPSR,SPSR_SPIF)!=1) && (SPI_TIMEOUT!=Local_u8TimeOut))
			Local_u8TimeOut++;
			
			/*CHECK IF TRANSRER IS COMPLET*/
			if(GET_BIT(SPSR,SPSR_SPIF)!=1)
			{
				SPI_u8BusyState=IDL;
				return TimeOut;
			}
			else
			{
				/*GET TRANSFERED DATA*/
				*Copy_Pu8ReceiveData=SPDR;
				
				/*CHECK IF I DIDN'T RECEIVE OR SEND NULL TO CONTINUE*/
				if ((*Copy_Pu8ReceiveData!='\0') && (*Copy_Pu8SendData!='\0'))
				{
					/*GO TO NEXT ELEMENT TO RECEIVE*/
					Copy_Pu8ReceiveData++;
					
					/*GO TO NEXT CHARACTER AND SEND*/
					Copy_Pu8SendData++;
					SPDR=*Copy_Pu8SendData;
					goto STATE1;
					
				}/*KEEP SENDING IF RECEVED DATA IS EQUAL TO NULL AND SENT DATA IS NOT*/
				else if ((*Copy_Pu8ReceiveData=='\0') && (*Copy_Pu8SendData!='\0'))
				{
					/*GO TO NEXT CHARACTER AND SEND*/
					Copy_Pu8SendData++;
					SPDR=*Copy_Pu8SendData;
					goto STATE1;
					
				}/*KEEP RECEIVING IF RECEVED DATA IS EQUAL TO NULL AND SENT DATA IS NOT*/
				else if ((*Copy_Pu8ReceiveData!='\0') && (*Copy_Pu8SendData=='\0'))
				{
					/*GO TO NEXT ELEMENT TO RECEIVE DATA*/
					Copy_Pu8ReceiveData++;
					
					/*SEND NULL*/
					SPDR=*Copy_Pu8SendData;
					goto STATE1;
					
				}/*CHECK IF I'VE SENT AND RECEIVED NULL*/					
				else if ((*Copy_Pu8ReceiveData=='\0') && (*Copy_Pu8SendData=='\0'))
				{
					/*SET BUSY STATE OF TRANCEIVE FUNCTION AS IDL*/
					SPI_u8BusyState=IDL;
					
					return CLEAR;
				}
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

u8 SPI_u8TranceiveASynch(u8* Copy_Pu8SendData, u8* Copy_Pu8ReceiveData, void(*Copy_PvoidNotFunc)(void))
{
	if ((Copy_Pu8SendData!=NULL) && (Copy_Pu8ReceiveData!=NULL))
	{
		if (SPI_u8BusyState==IDL)
		{
			
			/*SET BUSY STATE OF TRANCEIVE FUNCTION AS BUSY*/
			SPI_u8BusyState=BUSY;
			
			/*SET INTERRUPT BIT TO START TRANCEIVE ASYNCHRONOUS*/
			SET_BIT(SPCR,SPCR_SPIE);
			
			/*SET PASSED REFERANCES OF RECEIVED DATA TO GLOBLE VARIABLES SO THE ISR USE IT*/
			SPI_Pu8SendData=Copy_Pu8SendData;
			SPI_Pu8ReceiveData=Copy_Pu8ReceiveData;
			
			/*SET NOTIFICATION FUNCTION*/
			SPI_voidNotFunc=Copy_PvoidNotFunc;
			
			/*SET DATA IN SPI DATA REGISTER TO BE SEND*/
			SPDR=*Copy_Pu8SendData;
			
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

void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{	
	/*READ RECEIVED DATA*/
	*SPI_Pu8ReceiveData=SPDR;
	
	/*CHECK IF I DIDN'T RECEIVE OR SEND NULL TO CONTINUE*/
	if ((*SPI_Pu8ReceiveData!='\0') && (*SPI_Pu8SendData!='\0'))
	{
		/*GO TO NEXT ELEMENT TO RECEIVE*/
		SPI_Pu8ReceiveData++;
		
		/*GO TO NEXT CHARACTER AND SEND*/
		SPI_Pu8SendData++;
		SPDR=*SPI_Pu8SendData;
	
	}/*KEEP SENDING IF RECEVED DATA IS EQUAL TO NULL AND SENT DATA IS NOT*/
	else if ((*SPI_Pu8ReceiveData=='\0') && (*SPI_Pu8SendData!='\0'))
	{
		/*GO TO NEXT CHARACTER AND SEND*/
		SPI_Pu8SendData++;
		SPDR=*SPI_Pu8SendData;
	
	}/*KEEP RECEIVING IF RECEVED DATA IS EQUAL TO NULL AND SENT DATA IS NOT*/
	else if ((*SPI_Pu8ReceiveData!='\0') && (*SPI_Pu8SendData=='\0'))
	{
		/*GO TO NEXT ELEMENT TO RECEIVE DATA*/
		SPI_Pu8ReceiveData++;
		
		/*SEND NULL*/
		SPDR=*SPI_Pu8SendData;
		
	} /*CHECK IF I'VE SENT AND RECEIVED NULL*/
	else if ((*SPI_Pu8ReceiveData=='\0') && (*SPI_Pu8SendData=='\0'))
	{	
		/*SET BUSY STATE OF TRANCEIVE FUNCTION AS IDL*/
		SPI_u8BusyState=IDL;
		
		/*CLEAR INTERRUPT BIT*/
		CLR_BIT(SPCR,SPCR_SPIE);
		
		/*CALL NOTIFICATION FUNC*/
		SPI_voidNotFunc();
	}
	
}