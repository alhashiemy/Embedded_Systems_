/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : MCAl
 * SWC    : PORT
 * Version: 1.0
 * Created: JUN/18/2024
 */
 
#include "STD_TYPES.h"

#include "PORT_config.h"
#include "PORT_private.h"

void Port_voidInit(void)
{
	DDRA = PORTA_DIR;
	DDRB = PORTB_DIR;
	DDRC = PORTC_DIR;
	DDRD = PORTD_DIR;
	
	PORTA = PORTA_VALUE;
	PORTB = PORTB_VALUE;
	PORTC = PORTC_VALUE;
	PORTD = PORTD_VALUE;
}