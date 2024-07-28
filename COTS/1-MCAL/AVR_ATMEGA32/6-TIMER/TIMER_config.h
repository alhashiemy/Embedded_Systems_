/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : MCAL
 * SWC	  : TIMER
 * Version: 1.0
 * Created: JULY/2/2024
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/*	OPTIONS,						NORMAL
 *									PWM_PHASE_CORRECT
 *									CTC
 *									FAST_PWM 
 */
#define TIMER0_MODE					FAST_PWM   		

/*	OPTIONS,						NORMAL
 *									PWM_PHASE_CORRECT
 *									CTC
 *									FAST_PWM 
 */
#define TIMER2_MODE					NORMAL   		
			

/*	OPTIONS,						NORMAL
 *									PWM_PHASE_CORRECET_8BIT
 *									PWM_PHASE_CORRECET_9BIT
 *									PWM_PHASE_CORRECET_10BIT		
 * 									CTC_TOP_OCR1A					
 *									FAST_PWM_8BIT					
 *									FAST_PWM_9BIT					
 *									FAST_PWM_10BIT					
 *									PWM_PHASE_FREQ_CORRECT_TOP_ICR1	
 *									PWM_PHASE_FREQ_CORRECT_TOP_OCR1A
 *									PWM_PHASE_CORRECT_TOP_ICR1		
 *									PWM_PHASE_CORRECT_TOP_OCR1A		
 *									CTC_TOP_ICR1					
 *									FAST_PWM_TOP_ICR1				
 *									FAST_PWM_TOP_OCR1A				
 */
#define TIMER1_MODE					FAST_PWM_TOP_ICR1   		

	
#endif