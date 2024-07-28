/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : MCAl
 * SWC    : GPIO
 * Version: 1.0
 * Created: JUN/6/2024
 */
 
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "GPIO_private.h"


u8 GPIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	u8 Local_u8ErrorState = CLEAR;
	
	if(Copy_u8Pin<=GPIO_PIN7)
	{
		if (Copy_u8Value==GPIO_PIN_HIGH)
		{
			switch(Copy_u8Port)
			{
				case GPIO_PORTA: SET_BIT(GPIOA->PORT,Copy_u8Pin); break;
				case GPIO_PORTB: SET_BIT(GPIOB->PORT,Copy_u8Pin); break;
				case GPIO_PORTC: SET_BIT(GPIOC->PORT,Copy_u8Pin); break;
				case GPIO_PORTD: SET_BIT(GPIOD->PORT,Copy_u8Pin); break;
				default: Local_u8ErrorState = ERROR;
			}
		}
		else if (Copy_u8Value==GPIO_PIN_LOW)
		{
			switch(Copy_u8Port)
			{
				case GPIO_PORTA: CLR_BIT(GPIOA->PORT,Copy_u8Pin); break;
				case GPIO_PORTB: CLR_BIT(GPIOB->PORT,Copy_u8Pin); break;
				case GPIO_PORTC: CLR_BIT(GPIOC->PORT,Copy_u8Pin); break;
				case GPIO_PORTD: CLR_BIT(GPIOD->PORT,Copy_u8Pin); break;
				default: Local_u8ErrorState = ERROR;
			}
		}
		else
		Local_u8ErrorState = ERROR;
	}
	else
	{
		Local_u8ErrorState = ERROR;
	}
	
	return Local_u8ErrorState;
}


u8 GPIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
	u8 Local_u8ErrorState = CLEAR;
	switch(Copy_u8Port)
	{
		case GPIO_PORTA: GPIOA->PORT = Copy_u8Value; break;
		case GPIO_PORTB: GPIOB->PORT = Copy_u8Value; break;
		case GPIO_PORTC: GPIOC->PORT = Copy_u8Value; break;
		case GPIO_PORTD: GPIOD->PORT = Copy_u8Value; break;
		default: Local_u8ErrorState = ERROR;
	}
}

u8 GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_Pu8Value)
{
	u8 Local_u8ErrorState = CLEAR;
	if ((Copy_Pu8Value!=NULL) && (Copy_u8Pin<=GPIO_PIN7))
	{
		switch(Copy_u8Port)
		{
			case GPIO_PORTA: *Copy_Pu8Value = GET_BIT(GPIOA->PIN,Copy_u8Pin); break;
			case GPIO_PORTB: *Copy_Pu8Value = GET_BIT(GPIOB->PIN,Copy_u8Pin); break;
			case GPIO_PORTC: *Copy_Pu8Value = GET_BIT(GPIOC->PIN,Copy_u8Pin); break;
			case GPIO_PORTD: *Copy_Pu8Value = GET_BIT(GPIOD->PIN,Copy_u8Pin); break;
			default: Local_u8ErrorState = ERROR;
		}
	}
	else
	{
		Local_u8ErrorState = ERROR;
	}
	
	return Local_u8ErrorState;
}

u8 GPIO_u8GetPortValue(u8 Copy_u8Port, u8* Copy_Pu8Value)
{
	u8 Local_u8ErrorState = CLEAR;
	if (Copy_Pu8Value!=NULL)
	{
		switch(Copy_u8Port)
		{
			case GPIO_PORTA: *Copy_Pu8Value = GPIOD->PIN; break;
			case GPIO_PORTB: *Copy_Pu8Value = GPIOC->PIN; break;
			case GPIO_PORTC: *Copy_Pu8Value = GPIOB->PIN; break;
			case GPIO_PORTD: *Copy_Pu8Value = GPIOA->PIN; break;
			default: Local_u8ErrorState = ERROR;
		}
	}
	else
		Local_u8ErrorState = ERROR;
	
	return Local_u8ErrorState;
}

u8 GPIO_u8TogglePin(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Local_u8ErrorState = CLEAR;
	
	if (Copy_u8Pin<=7)
	{
		switch(Copy_u8Port)
		{
			case GPIO_PORTA: TGL_BIT(GPIOA->PORT, Copy_u8Pin); break;
			case GPIO_PORTB: TGL_BIT(GPIOB->PORT, Copy_u8Pin); break;
			case GPIO_PORTC: TGL_BIT(GPIOC->PORT, Copy_u8Pin); break;
			case GPIO_PORTD: TGL_BIT(GPIOD->PORT, Copy_u8Pin); break;
			default: Local_u8ErrorState = ERROR;
		}
	} 
	else
	{
		Local_u8ErrorState = ERROR;
	}
	
	return Local_u8ErrorState;
}