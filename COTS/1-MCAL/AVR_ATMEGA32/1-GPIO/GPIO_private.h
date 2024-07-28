/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : MCAl
 * SWC    : GPIO
 * Version: 1.0
 * Created: JUN/6/2024
 */
 

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#define GPIO_PIN_HIGH		1
#define GPIO_PIN_LOW		0

#define GPIO_PORT_HIGH		0xFF
#define GPIO_PORT_LOW		0

#define GPIO_PORTA			0
#define GPIO_PORTB			1
#define GPIO_PORTC			2
#define GPIO_PORTD			3

#define GPIO_PIN0			0
#define GPIO_PIN1			1
#define GPIO_PIN2			2
#define GPIO_PIN3			3
#define GPIO_PIN4			4
#define GPIO_PIN5			5
#define GPIO_PIN6			6
#define GPIO_PIN7			7


#define GPIOA_BASE_ADDRESS	0x39
#define GPIOB_BASE_ADDRESS	0x36
#define GPIOC_BASE_ADDRESS	0x33
#define GPIOD_BASE_ADDRESS	0x30

typedef struct {
	
	u8 PIN;
	u8 DDR;
	u8 PORT;

}GPIO_t;

#define GPIOA	((volatile GPIO_t*)GPIOA_BASE_ADDRESS)
#define GPIOB	((volatile GPIO_t*)GPIOB_BASE_ADDRESS)
#define GPIOC	((volatile GPIO_t*)GPIOC_BASE_ADDRESS)
#define GPIOD	((volatile GPIO_t*)GPIOD_BASE_ADDRESS)


#endif