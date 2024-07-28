/*
 * Author : Bassam Mahmoud
 * Layer  : MCAl
 * SWC    : EXTI
 * Version: 1.0
 * Created: NOV/23/2023
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_register.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

u8 EXTI_u8SetInit(u8 Copy_u8Line, u8 Copy_u8Mode)
{
	u8 Local_u8ErrorState = CLEAR;
	if(Copy_u8Line<16)
	{
		switch(Copy_u8Mode)
		{
			case EXTI_RISING_EDGE	: SET_BIT(EXTI->RTSR,Copy_u8Line); break;
			case EXTI_FALLING_EDGE	: SET_BIT(EXTI->FTSR,Copy_u8Line); break;
			default: Local_u8ErrorState = ERROR;
		}
	}
	else
	{
		Local_u8ErrorState = ERROR;
	}
	
	return Local_u8ErrorState;
}

u8 EXTI_u8EnableInit(u8 Copy_u8Line, void (*Copy_voidNotFunc)(void))
{
	u8 Local_u8ErrorState = CLEAR;
	if(Copy_u8Line<16)
	{
		/* SET NOTIFICATION FUNCTION */
		NotFunc[Copy_u8Line] = Copy_voidNotFunc ;

		/* ENABLE EXTI */
		SET_BIT(EXTI->EMR,Copy_u8Line);
		SET_BIT(EXTI->IMR,Copy_u8Line);
	}
	else
	{
		Local_u8ErrorState = ERROR;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8DisableInit(u8 Copy_u8Line)
{
	u8 Local_u8ErrorState = CLEAR;
	if(Copy_u8Line<16)
	{
		/* DISABLE EXTI */
		CLR_BIT(EXTI->EMR,Copy_u8Line);
		CLR_BIT(EXTI->IMR,Copy_u8Line);
	}
	else
	{
		Local_u8ErrorState = ERROR;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8SWInt(u8 Copy_u8Line)
{
	u8 Local_u8ErrorState = CLEAR;
	if(Copy_u8Line<16)
	{
		SET_BIT(EXTI->SWIER,Copy_u8Line);
	}
	else
	{
		Local_u8ErrorState = ERROR;
	}
	return Local_u8ErrorState;
}

/* THIS FUNCTION ALSO CAN BE USED TO CLEAR SOFTWARE INT */
u8 EXTI_u8ClearIntFlag(u8 Copy_u8Line)
{
	u8 Local_u8ErrorState = CLEAR;
	if(Copy_u8Line<16)
	{
		SET_BIT(EXTI->PR,Copy_u8Line);
	}
	else
	{
		Local_u8ErrorState = ERROR;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8SetCallBack(u8 Copy_u8Line, void(*Copy_voidNotFunc)(void))
{
	u8 Local_u8ErrorState = CLEAR;
	if(Copy_voidNotFunc != NULL)
	{
		if (Copy_u8Line < 16)
		{
			NotFunc[Copy_u8Line] = Copy_voidNotFunc;
		}
		else
		{
			Local_u8ErrorState = ERROR;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;
}

void EXTI0_IRQHandler(void)
{
	NotFunc[0]();
	EXTI_u8ClearIntFlag(0);
}

void EXTI1_IRQHandler(void)
{
	NotFunc[1]();
	EXTI_u8ClearIntFlag(1);
}

void EXTI2_IRQHandler(void)
{
	NotFunc[2]();
	EXTI_u8ClearIntFlag(2);
}

void EXTI3_IRQHandler(void)
{
	NotFunc[3]();
	EXTI_u8ClearIntFlag(3);
}

void EXTI4_IRQHandler(void)
{
	NotFunc[4]();
	EXTI_u8ClearIntFlag(4);
}

void EXTI5_IRQHandler(void)
{
	NotFunc[5]();
	EXTI_u8ClearIntFlag(5);
}

void EXTI6_IRQHandler(void)
{
	NotFunc[6]();
	EXTI_u8ClearIntFlag(6);
}

void EXTI7_IRQHandler(void)
{
	NotFunc[7]();
	EXTI_u8ClearIntFlag(7);
}

void EXTI8_IRQHandler(void)
{
	NotFunc[8]();
	EXTI_u8ClearIntFlag(8);
}

void EXTI9_IRQHandler(void)
{
	NotFunc[9]();
	EXTI_u8ClearIntFlag(9);
}

void EXTI10_IRQHandler(void)
{
	NotFunc[10]();
	EXTI_u8ClearIntFlag(10);
}

void EXTI11_IRQHandler(void)
{
	NotFunc[11]();
	EXTI_u8ClearIntFlag(11);
}

void EXTI12_IRQHandler(void)
{
	NotFunc[12]();
	EXTI_u8ClearIntFlag(12);
}

void EXTI13_IRQHandler(void)
{
	NotFunc[13]();
	EXTI_u8ClearIntFlag(13);
}

void EXTI14_IRQHandler(void)
{
	NotFunc[14]();
	EXTI_u8ClearIntFlag(14);
}

void EXTI15_IRQHandler(void)
{
	NotFunc[15]();
	EXTI_u8ClearIntFlag(15);
}
