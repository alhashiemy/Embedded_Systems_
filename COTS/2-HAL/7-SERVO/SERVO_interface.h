/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : HAL
 * SWC	  : SERVO
 * Version: 1.0
 * Created: JULY/2/2024
 */
#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

#define SERVO_u8CANNEL0				0
#define SERVO_u8CANNEL1				1

/*FUNCTION TO SET SERVO ROTATION DEGREE 
 *OPTIONS,	 Copy_u8Degree:		Set degree from 0 to 180.
 *	
 *			 Copy_u8Channel:	SERVO_u8CANNEL0  (OUTPUT SIGNAL ON OC1A)
 *								SERVO_u8CANNEL1  (OUTPUT SIGNAL ON OC1B)
 *								
 *NOTE: TO USE THIS FUNCTION YOU MUST CONNECT THE MOTOR ON PORTD PIN5 (CHANNEL A OF TIMER1).
 */
u8 SERVO_u8SetDegree(u8 Copy_u8Degree, u8 Copy_u8Channel);

#endif