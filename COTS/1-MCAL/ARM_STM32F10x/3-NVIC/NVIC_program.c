/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAl
 * SWC    : NVIC
 * Version: 1.0
 * Created: JULY/6/2024
 */
 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_private.h"
#include "NVIC_config.h"
#include "NVIC_interface.h"


u8 NVIC_u8EnableInterrupt(u8 Copy_u8IntNumber)
{
	u8 Local_u8ErrorState = CLR;
	if(Copy_u8IntNumber <= NVIC_MAX_NUM)
	{
		NVIC->ISER[Copy_u8IntNumber/32] = (1<<Copy_u8IntNumber%32);
	}
	else 
	{
		Local_u8ErrorState = ERR;
	}
	
	return Local_u8ErrorState;
}

u8 NVIC_u8DisableInterrupt(u8 Copy_u8IntNumber)
{
	u8 Local_u8ErrorState = CLR;
	if(Copy_u8IntNumber <= NVIC_MAX_NUM)
	{
		NVIC->ICER[Copy_u8IntNumber/32] = (1<<Copy_u8IntNumber%32);
	}
	else 
	{
		Local_u8ErrorState = ERR;
	}
	
	return Local_u8ErrorState;
}


u8 NVIC_u8SetPendingFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8ErrorState = CLR;
	if(Copy_u8IntNumber <= NVIC_MAX_NUM)
	{
		NVIC->ISPR[Copy_u8IntNumber/32] = (1<<Copy_u8IntNumber%32);
	}
	else 
	{
		Local_u8ErrorState = ERR;
	}
	
	return Local_u8ErrorState;
}

u8 NVIC_u8ClaerPendingFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8ErrorState = CLR;
	if(Copy_u8IntNumber <= NVIC_MAX_NUM)
	{
		NVIC->ICPR[Copy_u8IntNumber/32] = (1<<Copy_u8IntNumber%32);
	}
	else 
	{
		Local_u8ErrorState = ERR;
	}
	
	return Local_u8ErrorState;
}

u8 NVIC_u8GetActiveFlag(u8 Copy_u8IntNumber, u8* Copy_u8FlagState)
{
	u8 Local_u8ErrorState = CLR;
	if(Copy_u8IntNumber <= NVIC_MAX_NUM)
	{
		*Copy_u8FlagState = GET_BIT(NVIC->IABR[Copy_u8IntNumber/32],(Copy_u8IntNumber%32));
	}
	else 
	{
		Local_u8ErrorState = ERR;
	}
	
	return Local_u8ErrorState;
}

u8 NVIC_u8SetPriority(u8 Copy_u8IntPriorityNum, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority)
{
	u8 Local_u8ErrorState = CLR;
	u8 Local_u8Priority;
	
	/* FOR INTERNAL INTERRUPT */
	Local_u8Priority = Copy_u8GroupPriority<<(NVIC_GROUPING_MODE)|Copy_u8SubPriority;

	if(( Copy_u8IntPriorityNum <= NVIC_MAX_NUM ) && (NVIC_GROUPING_MODE <= 4))
	{
		/* FOR EXTERNAL INTERRUPT */
		SCB->AIRCR = NVIC_FIRST_GROUPING+(NVIC_GROUPING_MODE*265);

		NVIC->IPR[Copy_u8IntPriorityNum] &= NVIC_PRIORITY_MASK;

		NVIC->IPR[Copy_u8IntPriorityNum]  = (u32)(Local_u8Priority&(~NVIC_PRIORITY_MASK)) << 4;
	}
	else
	{
		Local_u8ErrorState = ERR;
	}
	
	return Local_u8ErrorState;
}
