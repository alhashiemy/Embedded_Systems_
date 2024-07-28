/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : HAL
 * SWC    : KPD
 * Version: 1.0
 * Created: JUN/11/2024
 */

#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "KPD_config.h"
#include "KPD_private.h"

u8 KPD_u8GetNum(u8* Copy_Pu8KPD)
{
	u8 Local_u8ErrorState = KPD_NO_PRESSED_KEY;
	u8 Local_u8RowInx,Local_u8ColumnInx;
	static u8 Local_u8ReturnNum[ROWS_NUM][COLS_NUM] = {KPD_ARR_VAL};
	
	if(Copy_Pu8KPD!=NULL)
	{
		for (Local_u8ColumnInx=0;Local_u8ColumnInx<COLS_NUM;Local_u8ColumnInx++)
		{
			GPIO_u8SetPinValue(Local_u8Col[Local_u8ColumnInx][PORT],Local_u8Col[Local_u8ColumnInx][PIN],GPIO_u8PIN_LOW);
			for (Local_u8RowInx=0;Local_u8RowInx<ROWS_NUM;Local_u8RowInx++)
			{
				GPIO_u8GetPinValue(Local_u8Row[Local_u8RowInx][PORT],Local_u8Row[Local_u8RowInx][PIN],Copy_Pu8KPD);
				if(GPIO_u8PIN_LOW == *Copy_Pu8KPD)
				{
					/*BUSY WAITING WHILE THE KEY IS UNPRESSED*/
					while(GPIO_u8PIN_LOW == *Copy_Pu8KPD)
					{
						GPIO_u8GetPinValue(Local_u8Row[Local_u8RowInx][PORT],Local_u8Row[Local_u8RowInx][PIN],Copy_Pu8KPD);
					}
					/*RETURN VALUE TO PASSED REFERANCE*/
					*Copy_Pu8KPD = Local_u8ReturnNum[Local_u8RowInx][Local_u8ColumnInx];
					GPIO_u8SetPinValue(Local_u8Col[Local_u8ColumnInx][PORT],Local_u8Col[Local_u8ColumnInx][PIN],GPIO_u8PIN_HIGH);
					Local_u8ErrorState = CLEAR;
					goto Stat1;
				}
			}
			GPIO_u8SetPinValue(Local_u8Col[Local_u8ColumnInx][PORT],Local_u8Col[Local_u8ColumnInx][PIN],GPIO_u8PIN_HIGH);
		}
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	
Stat1:
	return Local_u8ErrorState;
}

u8 KPD_u8ConcNum(u8* Copy_Pu8NumArr, u32* Copy_Pu32Return)
{
	u8 Local_u8ErrorState = CLEAR, Local_u8Iterator = 0;
	if ((Copy_Pu8NumArr!=NULL) && (Copy_Pu32Return!=NULL))
	{
		Copy_Pu32Return = 0;
		do
		{
			*Copy_Pu32Return = ((*Copy_Pu32Return)*10)+(Copy_Pu8NumArr[Local_u8Iterator]-'0');
			Local_u8Iterator++;
		}while(Copy_Pu8NumArr[Local_u8Iterator]!='\0');
	} 
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	
	return Local_u8ErrorState;
}