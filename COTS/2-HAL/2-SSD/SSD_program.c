/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : HAL
 * SWC	  : SSD
 * Version: 1.0
 * Created: JUN/6/2024
 */

#include "util\delay.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SSD_config.h"
#include "SSD_private.h"

void SSD_voidSetNumber(u16 Copy_u16Number)
{
	u8 Local_u8Iterator, Local_u8Port, Local_u8Pin, Local_u8SingleNumber[6];

#if	SSD_COM_TYPE == SSD_COM_CATH
	u8 Local_u8Number[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	
#elif SSD_COM_TYPE == SSD_COM_ANOD
	u8 Local_u8Number[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
#endif
	
	/* GET NUMBER DIVIDED INTO DECIMAL NUMBERS */
	Local_u8Iterator = 0;
	do
	{
		Local_u8SingleNumber[Local_u8Iterator] = Copy_u16Number%10;
		Copy_u16Number = (Copy_u16Number - (Local_u8SingleNumber[Local_u8Iterator]))/10;
		Local_u8Iterator++;
		}while(Copy_u16Number!=0);
	
	do
	{
		Local_u8Iterator--;
			
		/*SET VALUE OF EACH PIN*/
		GPIO_u8SetPinValue(SSD_DATA_PIN0, GET_BIT(Local_u8Number[Local_u8SingleNumber[Local_u8Iterator]], 0));
		GPIO_u8SetPinValue(SSD_DATA_PIN1, GET_BIT(Local_u8Number[Local_u8SingleNumber[Local_u8Iterator]], 1));
		GPIO_u8SetPinValue(SSD_DATA_PIN2, GET_BIT(Local_u8Number[Local_u8SingleNumber[Local_u8Iterator]], 2));
		GPIO_u8SetPinValue(SSD_DATA_PIN3, GET_BIT(Local_u8Number[Local_u8SingleNumber[Local_u8Iterator]], 3));
		GPIO_u8SetPinValue(SSD_DATA_PIN4, GET_BIT(Local_u8Number[Local_u8SingleNumber[Local_u8Iterator]], 4));
		GPIO_u8SetPinValue(SSD_DATA_PIN5, GET_BIT(Local_u8Number[Local_u8SingleNumber[Local_u8Iterator]], 5));
		GPIO_u8SetPinValue(SSD_DATA_PIN6, GET_BIT(Local_u8Number[Local_u8SingleNumber[Local_u8Iterator]], 6));
			 

		/*SET ENABLE PIN*/
		Local_u8Port = EnablePin[Local_u8Iterator][SSD_EN_PORT];
		Local_u8Pin  = EnablePin[Local_u8Iterator][SSD_EN_PIN] ;
		
		#if	SSD_COM_TYPE == SSD_COM_CATH
		GPIO_u8SetPinValue(Local_u8Port, Local_u8Pin, GPIO_u8PIN_LOW);
		/* SET DELAY (EACH DISPLAY WITH FRQ 50Hz) */
		_delay_ms(50/SSD_DISPLAYS_NUM);
		GPIO_u8SetPinValue(Local_u8Port, Local_u8Pin, GPIO_u8PIN_HIGH);

		#elif SSD_COM_TYPE == SSD_COM_ANOD
		GPIO_u8SetPinValue(Local_u8Port, Local_u8Pin, GPIO_u8PIN_HIGH);
		/* SET DELAY (EACH DISPLAY WITH FRQ 50Hz) */
		_delay_ms(50/SSD_DISPLAYS_NUM);
		GPIO_u8SetPinValue(Local_u8Port, Local_u8Pin, GPIO_u8PIN_LOW);
		#endif
		}while (Local_u8Iterator!=0);
		
}