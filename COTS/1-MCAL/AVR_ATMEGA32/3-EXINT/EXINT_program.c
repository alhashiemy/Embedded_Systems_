/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : MCAL
 * SWC    : EXINT
 * Version: 1.0
 * Created: JUN/15/2024
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXINT_config.h"
#include "EXINT_private.h"

void EXINT_voidInt0Init()
{
	/*MASK INT0 SENCE CONTROL BITS*/
	MCUCR&=0b11111100;
	
	/*SET SENCE CONTROL OF INT0*/
	MCUCR|=(EXINT0_SENSE<<0);
	
	/*SET SPISIFIC INTERRPUT ENABLE BIT OF INT0*/
	SET_BIT(GICR,GICR_INT0);

}

void EXINT_voidInt1Init()
{
	/*MASK INT1 SENCE CONTROL BITS*/
	MCUCR&=0b11110011;
	
	/*SET SENCE CONTROL OF INT1*/
	MCUCR|=(EXINT1_SENSE<<2);
	
	/*SET SPISIFIC INTERRPUT ENABLE BIT OF INT1*/
	SET_BIT(GICR,GICR_INT1);
	 
}

void EXINT_voidInt2Init()
{
	/*SET SENCE CONTROL OF INT2*/
	#if (EXINT2_SENSE==FALLING_EDGE)
	CLR_BIT(MCUCSR,MCUCSR_ISC2);

	#elif (EXINT2_SENSE==RISING_EDGE)
	SET_BIT(MCUCSR,MCUCSR_ISC2);
	#endif

	/*SET SPISIFIC INTERRPUT ENABLE BIT OF INT2*/
	SET_BIT(GICR,GICR_INT2);
}

u8 EXINT_u8SetEnableState(u8 Copy_u8IntNumber, u8 Copy_u8EnableState)
{
	u8 Local_u8ErrorState = CLEAR;
	switch(Copy_u8IntNumber)
	{
		case INT0: GICR &= INT0_ENABLE_BIT_MASK; GICR |= (Copy_u8EnableState<<GICR_INT0); break; 
		case INT1: GICR &= INT1_ENABLE_BIT_MASK; GICR |= (Copy_u8EnableState<<GICR_INT1); break; 
		case INT2: GICR &= INT2_ENABLE_BIT_MASK; GICR |= (Copy_u8EnableState<<GICR_INT2); break; 
		default: Local_u8ErrorState = ERROR;
	}
	
	return Local_u8ErrorState;
}

u8 EXINT_u8SetSenseState(u8 Copy_u8IntNumber, u8 Copy_u8SenseState)
{
	u8 Local_u8ErrorState = CLEAR;
	
	if (Copy_u8IntNumber == INT2)
	{
		switch(Copy_u8SenseState)
		{
			case FALLING_EDGE	: CLR_BIT(MCUCSR,MCUCSR_ISC2); break;
			case RISING_EDGE	: SET_BIT(MCUCSR,MCUCSR_ISC2); break;
			default: Local_u8ErrorState = ERROR;
		}
	}
	else
	{
		switch(Copy_u8IntNumber)
		{
			case INT0: MCUCR  &= 0b11111100; MCUCR  |= (Copy_u8SenseState<<0); break;
			case INT1: MCUCR  &= 0b11110011; MCUCR  |= (Copy_u8SenseState<<2); break;
			default: Local_u8ErrorState = ERROR;
		}
	}
	
	return Local_u8ErrorState;
}


u8 EXINT_u8SetCallBack(u8 Copy_u8ExInterrupt, void (*Copy_PNotFunc)(void))
{
	u8 Local_u8ErrorState = CLEAR;
	
	if (Copy_PNotFunc!=NULL)
	{
		if(Copy_u8ExInterrupt >= 2)
		{
			NotFunc[Copy_u8ExInterrupt] = Copy_PNotFunc;
		}
		else
		{
			Local_u8ErrorState = ERROR;
		}
	}
	else
		Local_u8ErrorState = NULL_POINTER;
	
	return Local_u8ErrorState;
}


void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if (NotFunc[0] != NULL)
	{
		NotFunc[0]();
	}
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if (NotFunc[1] != NULL)
	{
		NotFunc[1]();
	}
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if (NotFunc[2] != NULL)
	{
		NotFunc[2]();
	}
}