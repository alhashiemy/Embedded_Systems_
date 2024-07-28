/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : HAL
 * SWC    : LED
 * Version: 1.0
 * Created: JUN/7/2024
 */

#include "STD_TYPES.h"
#include "GPIO_interface.h"

#include "LED_config.h"
#include "LED_private.h"



void LED_voidLedON(u8 Copy_u8Port, u8 Copy_u8Pin)
{
#if LED_MODE == LED_PIN_SOURCE
	GPIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,LED_PIN_HIGH);
#elif LED_MODE == LED_PIN_SINK
	GPIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,LED_PIN_LOW);
#endif
}

void LED_voidLedOFF(u8 Copy_u8Port, u8 Copy_u8Pin)
{
#if LED_MODE == LED_PIN_SOURCE
	GPIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,LED_PIN_LOW);
#elif LED_MODE == LED_PIN_SINK
	GPIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,LED_PIN_HIGH);
#endif
}