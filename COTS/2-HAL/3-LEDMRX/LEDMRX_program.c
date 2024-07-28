/*
 * Author : Bassam Mahmoud
 * Layer  : HAL
 * SWC    : LEDMRX
 * Version: 1.0
 * Created: NOV/23/2023
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_config.h"
#include "LEDMRX_private.h"

PIN_t LEDMRX_ROWS[] = LEDMRX_ROWS_PINS;
PIN_t LEDMRX_COLS[] = LEDMRX_COLS_PINS;

void LEDMRX_voidInit(void)
{
	u8 Local_u8Iterator;

	/* INITIATE LED MATRIX ROWS PINS MODE */
	for(Local_u8Iterator = 0; Local_u8Iterator < LEDMRX_ROWS_NUM; Local_u8Iterator++)
	{
		GPIO_u8SetPinMode(LEDMRX_ROWS[Local_u8Iterator].Port, LEDMRX_ROWS[Local_u8Iterator].Pin,GPIO_PIN_OUTPUT_PP_10MHZ);
	}

	/* INITIATE LED MATRIX COLUMNS PINS MODE */
	for(Local_u8Iterator = 0; Local_u8Iterator < LEDMRX_COLS_NUM; Local_u8Iterator++)
	{
		GPIO_u8SetPinMode(LEDMRX_COLS[Local_u8Iterator].Port, LEDMRX_COLS[Local_u8Iterator].Pin,GPIO_PIN_OUTPUT_PP_10MHZ);
	}
}

void LEDMRX_voidSendChar(u8* Copy_Pu8CharArr)
{
	u8 Local_u8Iterator;

	for(Local_u8Iterator = 0; Local_u8Iterator < LEDMRX_COLS_NUM; Local_u8Iterator++)
	{
		LEDMRX_voidClear();

		/* SEND ROWS VALUE FOR ONE COLUMN */
		LEDMRX_voidSendColumn(~Copy_Pu8CharArr[Local_u8Iterator]);

		/* SET THE REQUIRED COLUMN */
		GPIO_u8SetPinValue(LEDMRX_COLS[Local_u8Iterator].Port, LEDMRX_COLS[Local_u8Iterator].Pin, GPIO_PIN_HIGH);

		/* SET DELAY FOR 2.5MS USING SYSTICK */
		STK_voidStartCountSynch(1000000/( LEDMRX_COLS_NUM * LEDMRX_FRAM_FRQ ));
	}
}

void LEDMRX_voidSendString(u8* Copy_u8Data, u8 Copy_u8SizeOfData)
{
	u8 Local_u8Iterator, Local_u8BusyWait;

	for(Local_u8Iterator=0; Local_u8Iterator<(Copy_u8SizeOfData-7); Local_u8Iterator++)
	{
		for(Local_u8BusyWait=0; Local_u8BusyWait<= LEDMRX_SPEED; Local_u8BusyWait++)
		{
			LEDMRX_voidSendChar(&Copy_u8Data[Local_u8Iterator]);
		}
	}
}

void LEDMRX_voidClear()
{
	u8 Local_u8Iterator;

	/* SET EVERY COLOMN BIN TO LOW */
	for(Local_u8Iterator = 0; Local_u8Iterator < LEDMRX_COLS_NUM; Local_u8Iterator++)
	{
		GPIO_u8SetPinValue(LEDMRX_COLS[Local_u8Iterator].Port, LEDMRX_COLS[Local_u8Iterator].Pin, GPIO_PIN_LOW);
	}
}

void LEDMRX_voidSendColumn(u8 Copy_u8Column)
{
	u8 Local_u8Iterator;

	for(Local_u8Iterator = 0; Local_u8Iterator < LEDMRX_ROWS_NUM; Local_u8Iterator++)
	{
		GPIO_u8SetPinValue(LEDMRX_ROWS[Local_u8Iterator].Port, LEDMRX_ROWS[Local_u8Iterator].Pin, GET_BIT(Copy_u8Column,Local_u8Iterator));
	}
}
