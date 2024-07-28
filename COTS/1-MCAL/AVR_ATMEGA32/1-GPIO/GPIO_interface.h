/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : MCAl
 * SWC    : GPIO
 * Version: 1.0
 * Created: JUN/6/2024
 */


#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

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

/*OPTIONS FOR Copy_u8Value (OR ANY OTHER VALUE TO CHANGE PORT VALUE)*/
#define GPIO_u8PIN_HIGH			1
#define GPIO_u8PIN_LOW			0
#define GPIO_u8PORT_HIGH		0xFF
#define GPIO_u8PORT_LOW			0

/*OPTIONS FOR Copy_Pu8Value PASS ANY REFERANCE TO RETURN PIN/PORT VALUE*/

u8 GPIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

u8 GPIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);

u8 GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_Pu8Value);

u8 GPIO_u8GetPortValue(u8 Copy_u8Port, u8* Copy_Pu8Value);

u8 GPIO_u8TogglePin(u8 Copy_u8Port, u8 Copy_u8Pin);


#endif