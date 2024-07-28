/*
 * Author : Bassam Mahmoud
 * Layer  : HAL
 * SWC    : IR
 * Version: 1.0
 * Created: DEC/2/2023
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "GPIO_interface.h"
#include "EXTI_interface.h"

#include "IR_interface.h"
#include "IR_private.h"
#include "IR_config.h"


static void (*NotFunc)(void);
static u32 FrameBit[50] = {NULL};
static u8* Pu8ReceivedData = NULL;
static u8 u8Counter = 0;



void IR_voidInit(void)
{
	/* SET IR RECIEVER PIN AS INPUT PULLED UP TO RECEIVE SIGNAL ON THE FALLING EDGE */
	GPIO_u8SetPinMode(IR_RECEIVER_PORT, IR_RECEIVER_PIN, GPIO_PIN_INPUT_PULL_UP_DOWN);

	/* MAKE PIN PULLED UP TO SENCE FALLING EDGE */
	GPIO_u8SetPinValue(IR_RECEIVER_PORT, IR_RECEIVER_PIN, GPIO_PIN_HIGH);

	/* SET EXTI FOR PIN */
	EXTI_u8SetInit(IR_RECEIVER_PIN,EXTI_FALLING_EDGE);

}

void IR_voidStartReceivingAsync(u8* Copy_Pu8ReceivedData, void(*Copy_PvoidNotFunc)(void))
{
	/* SET NOTIFICATION CALLBACK NOTIFICATION FUNCTION */
	NotFunc = Copy_PvoidNotFunc;

	/* SET PASSED REFERANCE OF DATA BUFFER AS GLOBAL VAR TO STORE DATA TO IT */
	Pu8ReceivedData = Copy_Pu8ReceivedData;

	/* ENABLE EXTI & SET EXTI CALLBACK FUNC WHICH WILL START COUNT AT THE MOMENT OF RECEIVING SIGNAL */
	EXTI_u8EnableInit(IR_RECEIVER_PIN, IR_voidReceiveFrame);
}

void IR_voidReceiveFrame(void)
{

	if(u8Counter == 0)
	{
		/* SET SYSTICK TO START COUNT */
		STK_voidStartCountASynch(100000,IR_voidEndFrame);
	}
	else
	{
		/* GET STK TIMER AND KEEP INCRIMENTING COUNTER */
		FrameBit[u8Counter-1] = STK_u32GetElapsedTime();

		/* RESET SYSTICK TO START COUNT */
		STK_voidStartCountASynch(100000,IR_voidEndFrame);
	}
	u8Counter++;

}

void IR_voidEndFrame(void)
{
	u8Counter = 17;
	u8 Local_u8Iterator;
	for(Local_u8Iterator=0; Local_u8Iterator<8; Local_u8Iterator++)
	{
		if	((FrameBit[u8Counter]) < 1250)
		{
			CLR_BIT(*Pu8ReceivedData,Local_u8Iterator);
		}
		else if ((FrameBit[u8Counter]) < 2500)
		{
			SET_BIT(*Pu8ReceivedData,Local_u8Iterator);
		}
		u8Counter++;
	}
	u8Counter = 0;
	NotFunc();

}
