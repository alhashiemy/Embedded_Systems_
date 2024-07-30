/*
 * Author : Bassam_Mahmoud_
 * Layer  : HAL
 * SWC	  : LEDMRX
 * Version: 1.1
 * Created: JULY/31/2024
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_config.h"
#include "LEDMRX_private.h"

static u8 LEDMRX_ROWS[LEDMRX_ROWS_NUM][2] = LEDMRX_ROWS_PINS;
static u8 LEDMRX_COLS[LEDMRX_COLS_NUM][2] = LEDMRX_COLS_PINS;

void LEDMRX_voidSendChar(char* Copy_Pu8Char)
{
	u8 Local_u8Iterator;

	for(Local_u8Iterator = 0; Local_u8Iterator < LEDMRX_COLS_NUM; Local_u8Iterator++)
	{
		LEDMRX_voidClear();

		/* SEND COLUMN VALUE FOR EACH ROW */
		LEDMRX_voidSendRow(Copy_Pu8Char[Local_u8Iterator]);

		/* SET THE REQUIRED COLUMN */
		GPIO_u8SetPinValue(LEDMRX_ROWS[Local_u8Iterator][PORT], LEDMRX_ROWS[Local_u8Iterator][PIN], GPIO_PIN_LOW);

		/* SET DELAY FOR 2.5MS USING SYSTICK */
		STK_u8StartCountSynch(1000000/( LEDMRX_COLS_NUM * LEDMRX_FRAM_FRQ ));

	}
}

void LEDMRX_voidSendString(const char* Copy_Pu8String)
{
	u8 Local_u8CharIndex, Local_u8RowIndex, Local_u8BitIndex, Local_u8BusyWait;

	char Local_u8CharToSend[8] = {0};

	for(Local_u8CharIndex = 0; Copy_Pu8String[Local_u8CharIndex] != '\0'; Local_u8CharIndex++)
	{
		for(Local_u8BitIndex = 0; Local_u8BitIndex < 8; Local_u8BitIndex++)
		{
			/* GET Character */
			for(Local_u8RowIndex = 0; Local_u8RowIndex < 8; Local_u8RowIndex++)
			{
				Local_u8CharToSend[Local_u8RowIndex] = (Local_u8CharToSend[Local_u8RowIndex]>>1) & 0b01111111;
				Local_u8CharToSend[Local_u8RowIndex]|= (GET_BIT(LEDMRX_Alpha[Copy_Pu8String[Local_u8CharIndex]-0x20][Local_u8RowIndex],Local_u8BitIndex)<<7);
			}

			for(Local_u8BusyWait = 0; Local_u8BusyWait <= LEDMRX_SPEED; Local_u8BusyWait++) {

				LEDMRX_voidSendChar(Local_u8CharToSend);
			}
		}
	}
}

void LEDMRX_voidClear()
{
	u8 Local_u8Iterator;

	/* SET EVERY COLOMN BIN TO LOW */
	for(Local_u8Iterator = 0; Local_u8Iterator < LEDMRX_ROWS_NUM; Local_u8Iterator++)
	{
		GPIO_u8SetPinValue(LEDMRX_ROWS[Local_u8Iterator][PORT], LEDMRX_ROWS[Local_u8Iterator][PIN], GPIO_PIN_HIGH);
	}
}

void LEDMRX_voidSendRow(u8 Copy_u8Column)
{
	u8 Local_u8Iterator;

	for(Local_u8Iterator = 0; Local_u8Iterator < LEDMRX_COLS_NUM; Local_u8Iterator++)
	{
		GPIO_u8SetPinValue(LEDMRX_COLS[Local_u8Iterator][PORT], LEDMRX_COLS[Local_u8Iterator][PIN], GET_BIT(Copy_u8Column,Local_u8Iterator));
	}
}
