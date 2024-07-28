/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : HAL
 * SWC	  : SERVO
 * Version: 1.0
 * Created: JULY/2/2024
 */

#ifndef SERVO_PRIVATE_H_
#define SERVO_PRIVATE_H_

#define SERVO_CHANNEL0				0
#define SERVO_CHANNEL1				1

#define SERVO_OUTPUT_MODE		TIMER_OPM_CLR_ON_COMP		/*CHOOSING OUTPUT(SET ON TOP CLEAR ON COMPARE) MODE*/

#define SERVO_WAVEFORM_MODE		TIMER1_FAST_PWM_TOP_ICR1	/*CHOOSING PWM TOP ICR1 WGMODE FOR FUNCITON TIMER1_u8SetTimer()*/

#endif