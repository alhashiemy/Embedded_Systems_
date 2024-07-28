/*
 * Author : Bassam_Mahmoud_
 * Layer  : PORT
 * Version: 1.0
 * Created: JULY/18/2024
 */

#ifndef SRVC_PRIVATE_H_
#define SRVC_PRIVATE_H_


typedef enum {

	PIN,
	PORT

}Pin_t;

typedef enum {

	SRVC_GPIO_CLOCK_OFF,
	SRVC_GPIO_CLOCK_ON

}GPIO_ClockState_t;

typedef enum {

	SRVC_GPIOA,
	SRVC_GPIOB,
	SRVC_GPIOC

}SRVC_port_t;

typedef enum {

	SRVC_PIN0,
	SRVC_PIN1,
	SRVC_PIN2,
	SRVC_PIN3,
	SRVC_PIN4,
	SRVC_PIN5,
	SRVC_PIN6,
	SRVC_PIN7,
	SRVC_PIN8,
	SRVC_PIN9,
	SRVC_PIN10,
	SRVC_PIN11,
	SRVC_PIN12,
	SRVC_PIN13,
	SRVC_PIN14,
	SRVC_PIN15

}SRVC_pin_t;

typedef struct {

	u8 GPIOA_ClockState 	;
	u8 GPIOB_ClockState 	;
	u8 GPIOC_ClockState 	;
	u8 LED_PIN [8][2]		;

}SRVC_config_t;

#endif
