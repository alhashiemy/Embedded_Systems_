/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : HAL
 * SWC    : LED
 * Version: 1.0
 * Created: JUN/7/2024
 */
 
#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

/*OPTIONS FOR Copy_u8Port*/
#define GPIO_u8PORTA			0
#define GPIO_u8PORTB			1
#define GPIO_u8PORTC			2
#define GPIO_u8PORTD			3

/*OPTIONS FOR Copy_u8Pin*/
#define GPIO_u8PIN0				0
#define GPIO_u8PIN1				1
#define GPIO_u8PIN2				2
#define GPIO_u8PIN3				3
#define GPIO_u8PIN4				4
#define GPIO_u8PIN5				5
#define GPIO_u8PIN6				6
#define GPIO_u8PIN7				7


void LED_voidLedON(u8 Copy_u8Port, u8 Copy_u8Pin);

void LED_voidLedOFF(u8 Copy_u8Port, u8 Copy_u8Pin);


#endif