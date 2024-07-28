/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAl
 * SWC    : GPIO
 * Version: 1.0
 * Created: JULY/6/2024
 */
 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


void GPIO_voidInitPortA(void)
{

	GPIOA->CRL = GPIOA_CRL_MODE;

	GPIOA->CRH = GPIOA_CRH_MODE;

	GPIOA->ODR = GPIOA_INIT_VAL;

	/* Locking sequence of portA
	GPIOA->LCKR &= ~(0x00FF);
	GPIOA->LCKR &= ~(0x01FF);
	GPIOA->LCKR &= ~(0x00FF);
	GPIOA->LCKR &= ~(0x01FF);

	SET_BIT(GPIOA->LCKR, LCKR_LCKK);*/

}

void GPIO_voidInitPortB(void)
{
	GPIOB->CRL = GPIOB_CRL_MODE;

	GPIOB->CRH = GPIOB_CRH_MODE;

	GPIOB->BSRR= GPIOB_INIT_VAL;

	/* Locking sequence of portB */
	GPIOB->LCKR &= ~(0x00FF);
	GPIOB->LCKR &= ~(0x01FF);
	GPIOB->LCKR &= ~(0x00FF);
	GPIOB->LCKR &= ~(0x01FF);

	SET_BIT(GPIOB->LCKR, LCKR_LCKK);
}

void GPIO_voidInitPortC(void)
{
	GPIOC->CRH = GPIOC_CRH_MODE;

	GPIOC->BSRR= GPIOC_INIT_VAL;

	/* Locking sequence of portC */
	GPIOC->LCKR &= ~(0x00FF);
	GPIOC->LCKR &= ~(0x01FF);
	GPIOC->LCKR &= ~(0x00FF);
	GPIOC->LCKR &= ~(0x01FF);

	SET_BIT(GPIOC->LCKR, LCKR_LCKK);
}

u8 GPIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	u8 Local_u8ErrorState = CLR;
	if((Copy_u8Pin<16) && (Copy_u8Value==GPIO_PIN_LOW))
	{
		switch(Copy_u8Port)
		{
		case GPIO_PORTA: GPIOA->BRR = (1<<Copy_u8Pin); break;
		case GPIO_PORTB: GPIOB->BRR = (1<<Copy_u8Pin); break;
		default: Local_u8ErrorState = ERR;
		}
	}
	else if((Copy_u8Pin<16) && (Copy_u8Value==GPIO_PIN_HIGH))
	{
		switch(Copy_u8Port)
		{
		case GPIO_PORTA: GPIOA->BSRR = (1<<Copy_u8Pin); break;
		case GPIO_PORTB: GPIOB->BSRR = (1<<Copy_u8Pin); break;
		default: Local_u8ErrorState = ERR;
		}
	}
	else
	{
		Local_u8ErrorState = ERR;
	}

	return Local_u8ErrorState;
}

u8 GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_u8Value)
{
	u8 Local_u8ErrorState = CLR;
	if(Copy_u8Pin<16)
	{
		switch(Copy_u8Port)
		{
		case GPIO_PORTA: *Copy_u8Value = GET_BIT(GPIOA->IDR, Copy_u8Pin); break;
		case GPIO_PORTB: *Copy_u8Value = GET_BIT(GPIOB->IDR, Copy_u8Pin); break;
		case GPIO_PORTC: *Copy_u8Value = GET_BIT(GPIOC->IDR, Copy_u8Pin); break;
		default: Local_u8ErrorState = ERR;
		}
	}
	else
	{
		Local_u8ErrorState = ERR;
	}

	return Local_u8ErrorState;
}


u8 GPIO_u8TogglePin(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Local_u8ErrorState = CLR;
	if(Copy_u8Pin<16)
	{
		switch(Copy_u8Port)
		{
		case GPIO_PORTA: TGL_BIT(GPIOA->ODR, Copy_u8Pin); break;
		case GPIO_PORTB: TGL_BIT(GPIOA->ODR, Copy_u8Pin); break;
		default: Local_u8ErrorState = ERR;
		}
	}
	else
	{
		Local_u8ErrorState = ERR;
	}

	return Local_u8ErrorState;
}

u8 GPIO_u8SetPortValue(u8 Copy_u8Port, u16 Copy_u8Value)
{
	u8 Local_u8ErrorState = CLR;
	switch(Copy_u8Port)
	{
	case GPIO_PORTA: GPIOA->ODR = Copy_u8Value; break;
	case GPIO_PORTB: GPIOB->ODR = Copy_u8Value; break;
	default: Local_u8ErrorState = ERR;
	}

	return Local_u8ErrorState;
}
