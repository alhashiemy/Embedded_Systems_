/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAl
 * SWC    : STK
 * Version: 1.0
 * Created: JULY/15/2024
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_config.h"
#include "STK_private.h"
#include "STK_interface.h"

static u8 STK_BusyState = IDL;

void (*STK_voidCallBack)(void) = NULL;

void STK_voidInit(void)
{
#if STK_CLKSOURCE_MODE == PROCESSOR_CLOCK_AHB
	SET_BIT(STK->CTRL,STK_CLKSOURCE);

#elif STK_CLKSOURCE_MODE == AHB_BY_EIGHT
	CLR_BIT(STK->CTRL,STK_CLKSOURCE);

#endif
}

u8 STK_u8StartCountSynch(u32 Copy_u8TimerValue)
{
	u8 Local_u8ErrorState = CLR;

	if(STK_BusyState == IDL){

		STK_BusyState = BUSY;

		/* DISABLE SYSTICK PREPHIRAL*/
		CLR_BIT(STK->CTRL,STK_ENABLE);

		/* DISABLE INERRUPT */
		CLR_BIT(STK->CTRL,STK_INTERRUPT);

		/* CLR VALUE REGISTER */
		STK->VAL = 0;

		/* SET TIMER VALUE TO SYSTICK LOAD REGISTER */
		STK->LOAD = Copy_u8TimerValue;

		/* CLR FLAG */
		CLR_BIT(STK->CTRL,STK_COUNTFLAG);

		/* DISABLE INTERRUPT  */
		CLR_BIT(STK->CTRL,STK_INTERRUPT);

		/* ENABLE SYSTICK PREPHIRAL */
		SET_BIT(STK->CTRL,STK_ENABLE);

		/* SET BUSY WAITING UNTIL UNDERFLOW AND COUNTFLAG IS RAISED */
		while(GET_BIT(STK->CTRL,STK_COUNTFLAG)==0);

		/* DISABLE SYSTICK PREPHIRAL*/
		CLR_BIT(STK->CTRL,STK_ENABLE);

		/* RETURN BUSY STATE VAR TO IDL */
		STK_BusyState = IDL;
	}
	else
	{
		Local_u8ErrorState = BUSY;
	}

	return Local_u8ErrorState;
}

u8 STK_u8StartCountASynch(u32 Copy_u8TimerValue, void (*Copy_voidNotFunc)(void))
{
	u8 Local_u8ErrorState = CLR;

	if(STK_BusyState == IDL) {

		/* SET STK_BusyState VAR TO BUSY */
		STK_BusyState = BUSY;

		/* SET CALLBACK ARGUMENTS */
		STK_voidCallBack = Copy_voidNotFunc;

		/* DISABLE SYSTICK PREPHIRAL*/
		CLR_BIT(STK->CTRL,STK_ENABLE);

		/* DISABLE INERRUPT */
		CLR_BIT(STK->CTRL,STK_INTERRUPT);

		/* CLR VALUE REGISTER */
		STK->VAL = 0;

		/* SET TIMER VALUE TO SYSTICK LOAD REGISTER */
		STK->LOAD = Copy_u8TimerValue;

		/* CLR FLAG */
		CLR_BIT(STK->CTRL,STK_COUNTFLAG);

		/* ENABLE INTERRUPT */
		SET_BIT(STK->CTRL,STK_INTERRUPT);

		/* ENABLE STK PREPHIRAL */
		SET_BIT(STK->CTRL,STK_ENABLE);
	}
	else
	{
		Local_u8ErrorState = BUSY;
	}

	return Local_u8ErrorState;
}

u32 STK_u32GetElapsedTime(void)
{
	return ((STK->LOAD)-(STK->VAL));
}

u32 STK_u32GetRemainingTime(void)
{
	return (STK->VAL);
}


void SysTick_Handler(void)
{
	/* SET STK_BusyState VAR TO IDL */
	STK_BusyState = IDL;

	/* DISABLE SYSTICK PREPHIRAL*/
	CLR_BIT(STK->CTRL,STK_ENABLE);

	/* DISABLE INERRUPT */
	CLR_BIT(STK->CTRL,STK_INTERRUPT);

	/* CALL BACK NOTIFICATION FUNC*/
	STK_voidCallBack();
}
