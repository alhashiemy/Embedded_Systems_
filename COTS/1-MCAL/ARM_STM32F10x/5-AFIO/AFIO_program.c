/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAl
 * SWC    : AFIO
 * Version: 1.0
 * Created: JULY/15/2024
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_private.h"
#include "AFIO_config.h"
#include "AFIO_interface.h"


/* ARGUMENT FOR Copy_u8LinePort PARAMITER */
#define AFIO_EXTI_PORTA		0
#define AFIO_EXTI_PORTB		1
#define AFIO_EXTI_PORTC		2

u8 AFIO_u8SetExtIntLinePort(u8 Copy_u8Line, u8 Copy_u8LinePort)
{
	u8 Local_u8ErrorState = CLR;
	
	u8 Local_u8RegIndex  = Copy_u8Line/4;  /* TO REATCH THE REQUIRED EXTICR REGISTER */
	u8 Local_u8LineIndex = Copy_u8Line%4; /* TO REATCH THE REQUIRED LINE AT EXTICR PORT */
	
	if((Copy_u8Line<16) && (Copy_u8LinePort<=2))
	{
		/* Using bit mask to clear bits */
		AFIO->EXTICR[Local_u8RegIndex] &= ~(0b1111<<Local_u8LineIndex*4);
		AFIO->EXTICR[Local_u8RegIndex] |=  (Copy_u8LinePort<<Local_u8LineIndex*4);
	}
	else
	{
		Local_u8ErrorState = ERR;
	}
	
	return Local_u8ErrorState;
}
