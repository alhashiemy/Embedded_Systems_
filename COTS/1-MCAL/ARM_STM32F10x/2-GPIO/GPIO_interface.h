/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAl
 * SWC    : GPIO
 * Version: 1.0
 * Created: JULY/6/2024
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#define GPIO_PORTA			0
#define GPIO_PORTB			1
#define GPIO_PORTC			2

#define GPIO_PIN_LOW		0
#define GPIO_PIN_HIGH		1

#define GPIO_PORT_LOW		0x0000
#define GPIO_PORT_HIGH		0xFFFF

void GPIO_voidInitPortA(void);
void GPIO_voidInitPortB(void);
void GPIO_voidInitPortC(void);

u8 GPIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

u8 GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_u8Value);

u8 GPIO_u8TogglePin(u8 Copy_u8Port, u8 Copy_u8Pin);

u8 GPIO_u8SetPortValue(u8 Copy_u8Port, u16  Copy_u8Value);

u8 GPIO_u8GetPortValue(u8 Copy_u8Port, u16* Copy_u8Value);

#endif
