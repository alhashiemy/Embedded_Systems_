/*
 * Author : Bassam_Mahmoud_
 * Layer  : SRVC
 * Version: 1.0
 * Created: JULY/18/2024
 */

#include "STD_TYPES.h"
#include "SRVC_private.h"

SRVC_config_t SRVC_config = {

	.GPIOA_ClockState	= SRVC_GPIO_CLOCK_ON	,
	.GPIOB_ClockState	= SRVC_GPIO_CLOCK_OFF	,
	.GPIOC_ClockState	= SRVC_GPIO_CLOCK_OFF	,

	.LED_PIN			={{SRVC_PIN1, SRVC_GPIOA},
						  {SRVC_PIN2, SRVC_GPIOA},
						  {SRVC_PIN3, SRVC_GPIOA},
						  {SRVC_PIN4, SRVC_GPIOA},
						  {SRVC_PIN5, SRVC_GPIOA},
						  {SRVC_PIN6, SRVC_GPIOA},
						  {SRVC_PIN7, SRVC_GPIOA},
						  {SRVC_PIN8, SRVC_GPIOA}}

};
