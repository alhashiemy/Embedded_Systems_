/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : HAL
 * SWC	  : SERVO
 * Version: 1.0
 * Created: JULY/2/2024
 */

#include "STD_TYPES.h"
#include "TIMER_interface.h"
#include "SERVO_config.h"
#include "SERVO_private.h"

u8 SERVO_u8SetDegree(u8 Copy_u8Degree, u8 Copy_u8Cannel)
{
	u8 Local_u8ErrorState = CLEAR;
	
	f32 Local_u8MapValue;
	
	if ((Copy_u8Degree<=180) && (Copy_u8Cannel<=1))
	{
		/*MAPPING DEGREE FROM (0-180) TO (1000-2000) THE COMPAR VALUE THAT WILL CONTROL SERVO DEGREE*/
		/*(MAX_OUTPUT-MIN_OUTPUT)/(MAX_INPUT-MIN_INPUT)+MIN_OUTPUT*/
		Local_u8MapValue =(f32)Copy_u8Degree*((f32)1000/(f32)180)+1000;			
		
		/*SET CHANNEL TO GET REQUIRED PWM SIGNAL TO MAKE SERVO ROTATE AT A SERTEN DEGREE*/
		/*SET COMPARE MATCH VALUE TO CONTROL SERVO DEGREE*/
		switch(Copy_u8Cannel)
		{
			case SERVO_CHANNEL0:TIMER_u8SetCompMatchValue(TIMER1A_u8COMPARE, SERVO_OUTPUT_MODE, (u16)Local_u8MapValue); break;
			case SERVO_CHANNEL1:TIMER_u8SetCompMatchValue(TIMER1B_u8COMPARE, SERVO_OUTPUT_MODE, (u16)Local_u8MapValue); break;
		}
		
		/*SET TIMER WAVEFORM GENERATION MODE AND PRESCALER*/
		/*Set TIMER1 MODE TO FAST PWM ICR1 TOP*/
		/*SET PRESCALER TO DEVIDE BY 8*/
		TIMER_u8SetTimerMode(TIMER1_u8TIMER, SERVO_WAVEFORM_MODE);
		
		/*SET TOP VALUE TO CAPTURE REGISTER*/
		TIMER1_voidSetCaptureValue(20000);
		
		TIMER_u8Start(TIMER1_u8TIMER, NO_PRESCALER, 0);

	} 
	else
		Local_u8ErrorState = ERROR;
		
	return Local_u8ErrorState;
}