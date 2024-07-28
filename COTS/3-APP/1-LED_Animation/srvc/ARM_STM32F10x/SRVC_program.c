/*
 * Author : Bassam_Mahmoud_
 * Layer  : SRVC
 * Version: 1.0
 * Created: JULY/18/2024
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "STK_interface.h"
#include "GPIO_interface.h"

#include "SRVC_interface.h"
#include "SRVC_private.h"

extern SRVC_config_t SRVC_config;

void SRVC_voidInit()
{
	/* Initiate SYSTICK & RCC */
	STK_voidInit();
	RCC_voidInit();

	if(SRVC_config.GPIOA_ClockState == SRVC_GPIO_CLOCK_ON) {

		/* SET CLOCK FOR SRVCA AND INTIALISE IT */
		RCC_u8EnableClock(RCC_APB2,RCC_GPIO_PORTA);
		GPIO_voidInitPortA();
	}

	if(SRVC_config.GPIOA_ClockState == SRVC_GPIO_CLOCK_ON) {

		/* SET CLOCK FOR SRVCA AND INTIALISE IT */
		RCC_u8EnableClock(RCC_APB2,RCC_GPIO_PORTB);
		GPIO_voidInitPortB();
	}

	if(SRVC_config.GPIOA_ClockState == SRVC_GPIO_CLOCK_ON) {

		/* SET CLOCK FOR SRVCA AND INTIALISE IT */
		RCC_u8EnableClock(RCC_APB2,RCC_GPIO_PORTC);
		GPIO_voidInitPortC();
	}

}

void SRVC_voidShiftLeftRight(u32 Copy_u32Delay){

	u8 Local_u8Iterator;

	for(Local_u8Iterator=0; Local_u8Iterator<8 ; Local_u8Iterator++)
	{
		/* Set pin high */
		GPIO_u8SetPinValue(SRVC_config.LED_PIN[Local_u8Iterator][PORT], SRVC_config.LED_PIN[Local_u8Iterator][PIN], GPIO_PIN_HIGH);

		/* Set delay as required */
		STK_u8StartCountSynch(Copy_u32Delay*1000);

		/* Set pin low */
		GPIO_u8SetPinValue(SRVC_config.LED_PIN[Local_u8Iterator][PORT], SRVC_config.LED_PIN[Local_u8Iterator][PIN], GPIO_PIN_LOW);

	}

	do
	{
		Local_u8Iterator--;

		/* Set pin high */
		GPIO_u8SetPinValue(SRVC_config.LED_PIN[Local_u8Iterator][PORT], SRVC_config.LED_PIN[Local_u8Iterator][PIN], GPIO_PIN_HIGH);

		/* Set delay as required */
		STK_u8StartCountSynch(Copy_u32Delay*1000);

		/* Set pin low */
		GPIO_u8SetPinValue(SRVC_config.LED_PIN[Local_u8Iterator][PORT], SRVC_config.LED_PIN[Local_u8Iterator][PIN], GPIO_PIN_LOW);

	}while(Local_u8Iterator != 0);

}


void SRVC_voidInOut(u32 Copy_u32Delay) {

	u8 Local_u8Iterator;

	for(Local_u8Iterator=0; Local_u8Iterator<4 ; Local_u8Iterator++) {

		/* Set pin high */
		GPIO_u8SetPinValue(SRVC_config.LED_PIN[Local_u8Iterator][PORT],   SRVC_config.LED_PIN[Local_u8Iterator][PIN],   GPIO_PIN_HIGH);

		/* Set pin high */
		GPIO_u8SetPinValue(SRVC_config.LED_PIN[7-Local_u8Iterator][PORT], SRVC_config.LED_PIN[7-Local_u8Iterator][PIN], GPIO_PIN_HIGH);

		/* Set delay as required */
		STK_u8StartCountSynch(Copy_u32Delay*1000);

	}

	do {
		Local_u8Iterator--;

		/* Set pin low */
		GPIO_u8SetPinValue(SRVC_config.LED_PIN[Local_u8Iterator][PORT],   SRVC_config.LED_PIN[Local_u8Iterator][PIN],   GPIO_PIN_LOW);

		/* Set pin low */
		GPIO_u8SetPinValue(SRVC_config.LED_PIN[7-Local_u8Iterator][PORT], SRVC_config.LED_PIN[7-Local_u8Iterator][PIN], GPIO_PIN_LOW);

		/* Set delay as required */
		STK_u8StartCountSynch(Copy_u32Delay*1000);

	}while(Local_u8Iterator!=0);


}

void SRVC_voidFlashing(u32 Copy_u32Delay) {

	u8 Local_u8Iterator;

	for(Local_u8Iterator=0; Local_u8Iterator<8 ; Local_u8Iterator++) {

		/* Set pin high */
		GPIO_u8SetPinValue(SRVC_config.LED_PIN[Local_u8Iterator][PORT],   SRVC_config.LED_PIN[Local_u8Iterator][PIN],   GPIO_PIN_HIGH);

	}
	/* Set delay as required */
	STK_u8StartCountSynch(Copy_u32Delay*1000);

	for(Local_u8Iterator=0; Local_u8Iterator<8 ; Local_u8Iterator++) {

		/* Set pin low */
		GPIO_u8SetPinValue(SRVC_config.LED_PIN[Local_u8Iterator][PORT],   SRVC_config.LED_PIN[Local_u8Iterator][PIN],   GPIO_PIN_LOW);

	}
	/* Set delay as required */
	STK_u8StartCountSynch(Copy_u32Delay*1000);
}
