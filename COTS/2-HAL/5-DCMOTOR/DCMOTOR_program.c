/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : HAL
 * SWC    : DCMOTOR
 * Version: 1.0
 * Created: JUN/14/2024
 */
 
#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "TIMER_interface.h"

#include "DCMOTOR_config.h"
#include "DCMOTOR_private.h"

void DCMOTOR_voidRotateCW(void)
{
	GPIO_u8SetPinValue(DCMOTOR_PIN0,GPIO_u8PIN_HIGH);
	GPIO_u8SetPinValue(DCMOTOR_PIN1,GPIO_u8PIN_LOW);
}

void DCMOTOR_voidRotateCCW(void)
{
	GPIO_u8SetPinValue(DCMOTOR_PIN0,GPIO_u8PIN_LOW);
	GPIO_u8SetPinValue(DCMOTOR_PIN1,GPIO_u8PIN_HIGH);
}

u8 DCMOTOR_u8RotateCW(u8 Copy_u8Pin0, u8 Copy_u8Pin1)
{
	u8 Local_u8ErrorState = CLEAR;
	
	if ((Copy_u8Pin0<8)&&(Copy_u8Pin1<8))
	{
		GPIO_u8SetPinValue(DCMOTOR_PIN0,GPIO_u8PIN_HIGH);
		GPIO_u8SetPinValue(DCMOTOR_PIN1,GPIO_u8PIN_LOW);
	} 
	else
	{
		Local_u8ErrorState = ERROR;
	}
	
	return Local_u8ErrorState;
}

u8 DCMOTOR_u8RotateCCW(u8 Copy_u8Pin0, u8 Copy_u8Pin1)
{
	u8 Local_u8ErrorState = CLEAR;
	
	if ((Copy_u8Pin0<8)&&(Copy_u8Pin1<8))
	{
		GPIO_u8SetPinValue(DCMOTOR_PIN0,GPIO_u8PIN_LOW);
		GPIO_u8SetPinValue(DCMOTOR_PIN1,GPIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState = ERROR;
	}
	
	return Local_u8ErrorState;
}

u8 DCMOTOR_u8SetSpeed(u8 Copy_u8Speed, u8 Copy_u8Channel)
{
	u8 Local_u8ErrorState = CLEAR;
	f32 Local_u8MapValue;
	
	Local_u8MapValue = (f32)Copy_u8Speed*((f32)255/(f32)100);
	
	if ((Copy_u8Speed<=100) && (Copy_u8Channel<2))
	{
		 TIMER_u8SetTimerMode(Copy_u8Channel, TIMER_u8PWM_PHASE_CORRECET);
		 TIMER_u8SetCompMatchValue(Copy_u8Channel, TIMER_OPM_CLR_ON_COMP_UP, (u8)Local_u8MapValue);
		 TIMER_u8Start(Copy_u8Channel, NO_PRESCALER, 0);
	}
	else
	{
		Local_u8ErrorState = ERROR;
	}
	
	return Local_u8ErrorState;
}