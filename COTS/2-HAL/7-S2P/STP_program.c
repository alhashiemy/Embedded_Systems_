/*
 * Author : Bassam_Mahmoud_
 * Layer  : HAL
 * SWC    : STP
 * Version: 1.0
 * Created: DEC/7/2023
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"
#include "STP_config.h"
#include "STP_private.h"


void STP_voidInit(void)
{
	GPIO_u8SetPinMode(STP_DATA_PIN,  GPIO_PIN_OUTPUT_PP_10MHZ);
	GPIO_u8SetPinMode(STP_SHIFT_PIN, GPIO_PIN_OUTPUT_PP_10MHZ); 
	GPIO_u8SetPinMode(STP_STORE_PIN, GPIO_PIN_OUTPUT_PP_10MHZ); 
}

void STP_voidSendData(u8 Copy_u8Data)
{
	s8 Local_s8Iterator;
	for(Local_s8Iterator = 7; Local_s8Iterator >= 0; Local_s8Iterator--)
	{
		/* SEND SERIAL DATA */
		GPIO_u8SetPinValue(STP_DATA_PIN, GET_BIT(Copy_u8Data,Local_s8Iterator));

		/* SEND PULSE ON SHIFT PIN */
		GPIO_u8SetPinValue(STP_SHIFT_PIN, GPIO_PIN_HIGH);
		STK_voidStartCountSynch(1);
		GPIO_u8SetPinValue(STP_SHIFT_PIN, GPIO_PIN_LOW );
		STK_voidStartCountSynch(1);
	}

}

void STP_voidEnable(void)
{
	/* SEND PULSE ON STORAGE PIN */
	GPIO_u8SetPinValue(STP_STORE_PIN, GPIO_PIN_HIGH);
	STK_voidStartCountSynch(1);
	GPIO_u8SetPinValue(STP_STORE_PIN, GPIO_PIN_LOW );
	STK_voidStartCountSynch(1);
}
