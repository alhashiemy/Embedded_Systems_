/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : MCAL
 * SWC	  : TIMER
 * Version: 1.0
 * Created: JULY/2/2024
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define NORMAL										0x00
#define PWM_PHASE_CORRECT							0x08
#define CTC											0x40
#define FAST_PWM									0x48

#define PWM_PHASE_CORRECT							0x08
#define CTC											0x40
#define FAST_PWM									0x48

#define PWM_PHASE_CORRECET_8BIT						0x0100
#define PWM_PHASE_CORRECET_9BIT						0x0200
#define PWM_PHASE_CORRECET_10BIT					0x0300
#define CTC_TOP_OCR1A								0x0008
#define FAST_PWM_8BIT								0x0108
#define FAST_PWM_9BIT								0x0208
#define FAST_PWM_10BIT								0x0308
#define PWM_PHASE_FREQ_CORRECT_TOP_ICR1				0x0010
#define PWM_PHASE_FREQ_CORRECT_TOP_OCR1A			0x0110
#define PWM_PHASE_CORRECT_TOP_ICR1					0x0210
#define PWM_PHASE_CORRECT_TOP_OCR1A					0x0310
#define CTC_TOP_ICR1								0x0118
#define FAST_PWM_TOP_ICR1							0x0218
#define FAST_PWM_TOP_OCR1A							0x0318

#define TIMER0_WGMODE_MASK							0xB7
#define TIMER2_WGMODE_MASK							0xB7
#define TIMER1_WGMODE_MASK							0xFCE7


#define TIMER0_COMODE_MASK							0b11001111
#define TIMER2_COMODE_MASK							0b11001111
#define TIMERA_COMODE_MASK							0b00111111
#define TIMERB_COMODE_MASK							0b11001111

#define TIMER_CLOCK_MASK							0b11111000
#define CAPTUR_TRIGGER_MASK							0b10111111

#define TIMER0_TIMER								0
#define TIMER2_TIMER								1
#define TIMER1_TIMER								2

#define TIMER0_COMPARE								0
#define TIMER2_COMPARE								1
#define TIMER1A_COMPARE								2
#define TIMER1B_COMPARE								3

#define TCCR0					*((volatile u8*)0x53)		/*Timer/Counter0 Control Register*/
#define TCCR0_WGM00				6							/*Timer/Counter0 Waveform Generation Mode Bit 0*/
#define TCCR0_WGM01				3							/*Timer/Counter0 Waveform Generation Mode Bit 1*/
#define TCCR0_CS00				0							/*Timer/Counter0 PRESCALER Bit 0*/
#define TCCR0_CS01				1							/*Timer/Counter0 PRESCALER Bit 1*/
#define TCCR0_CS02				2							/*Timer/Counter0 PRESCALER Bit 2*/
#define TCCR0_COM00				4							/*Timer/Counter0 Compare Match Output Mode Bit0*/
#define TCCR0_COM01				5							/*Timer/Counter0 Compare Match Output Mode Bit2*/

#define TCNT0					*((volatile u8*)0x52)		/*Timer/Counter0 Register*/
#define OCR0					*((volatile u8*)0x5c)		/*Output Compare Register 0*/

#define TCCR1A					*((volatile u8*)0x4f)		/*Timer/Counter1 Control Register A*/
#define TCCR1A_WGM10			0							/*Timer/Counter1 Waveform Generation Mode Bit 0*/
#define TCCR1A_WGM11			1							/*Timer/Counter1 Waveform Generation Mode Bit 1*/
#define TCCR1A_COM1B0			4							/* Compare Output Mode for Channel B BIT0*/
#define TCCR1A_COM1B1			5							/* Compare Output Mode for Channel B BIT1*/
#define TCCR1A_COM1A0			6							/* Compare Output Mode for Channel A BIT0*/
#define TCCR1A_COM1A1			7							/* Compare Output Mode for Channel A BIT1*/

#define TCCR1B					*((volatile u8*)0x4e)		/*Timer/Counter1 Control Register B*/
#define TCCR1B_CS10				0							/*Timer/Counter1 PRESCALER Bit 0*/
#define TCCR1B_CS11				1							/*Timer/Counter1 PRESCALER Bit 1*/
#define TCCR1B_CS12				2							/*Timer/Counter1 PRESCALER Bit 2*/
#define TCCR1B_WGM12			3							/*Timer/Counter1 Waveform Generation Mode Bit 2*/
#define TCCR1B_WGM13			4							/*Timer/Counter1 Waveform Generation Mode Bit 3*/

#define TCCR1					*((volatile u16*)0x4e)		/*Timer/Counter1 Control Register*/

#define TCNT1L					*((volatile u8*)0x4c)		/*Timer/Counter1 LOW REGISTER*/
#define TCNT1H					*((volatile u8*)0x4d)		/*Timer/Counter1 HIGH REGISTER*/
#define TCNT1					*((volatile u16*)0x4c)		/*Timer/Counter1*/

#define OCR1AL					*((volatile u8*)0x4a)		/*Output Compare Register 1 A Low Register*/
#define OCR1AH					*((volatile u8*)0x4b)		/*Output Compare Register 1 A High Register*/
#define OCR1A					*((volatile u16*)0x4a)		/*Output Compare Register 1 A*/

#define OCR1BL					*((volatile u8*)0x48)		/*Output Compare Register 1 A Low Register*/
#define OCR1BH					*((volatile u8*)0x49)		/*Output Compare Register 1 A High Register*/
#define OCR1B					*((volatile u16*)0x48)		/*Output Compare Register 1 B*/

#define ICR1L					*((volatile u8*)0x46)		/*Input Capture Register 1 Low Register*/
#define ICR1H					*((volatile u8*)0x47)		/*Input Capture Register 1 High Register*/
#define ICR1					*((volatile u16*)0x46)		/*Input Capture Register 1*/

#define TCCR2					*((volatile u8*)0x45)		/*Timer/Counter0 Control Register*/
#define TCCR2_WGM20				6							/*Timer/Counter0 Waveform Generation Mode Bit 0*/
#define TCCR2_WGM21				3							/*Timer/Counter0 Waveform Generation Mode Bit 1*/
#define TCCR2_CS20				0							/*Timer/Counter0 PRESCALER Bit 0*/
#define TCCR2_CS21				1							/*Timer/Counter0 PRESCALER Bit 1*/
#define TCCR2_CS22				2							/*Timer/Counter0 PRESCALER Bit 2*/
#define TCCR2_COM20				4							/*Timer/Counter0 Compare Match Output Mode Bit0*/
#define TCCR2_COM21				5							/*Timer/Counter0 Compare Match Output Mode Bit2*/

#define TCNT2					*((volatile u8*)0x44)		/*Timer/Counter0 Register*/
#define OCR2					*((volatile u8*)0x43)		/*Output Compare Register 0*/

#define TIMSK					*((volatile u8*)0x59)		/*Timer/Counter Interrupt Mask Register*/
#define TIMSK_TOIE0				0							/*Timer/Counter0 Overflow Interrupt Enable Bit*/
#define TIMSK_OCIE0				1							/*Timer/Counter0 Compare Match Interrupt Enable Bit*/
#define TIMSK_TOIE1				2							/*Timer/Counter1, Overflow Interrupt Enable*/
#define TIMSK_OCIE1B			3							/*Timer/Counter1, Output Compare B Match Interrupt Enable*/
#define TIMSK_OCIE1A			4							/*Timer/Counter1, Output Compare A Match Interrupt Enable*/
#define TIMSK_TICIE1			5							/*Timer/Counter1, Input Capture Interrupt Enable*/
#define TIMSK_TOIE2				6							/*Timer/Counter0 Overflow Interrupt Enable Bit*/
#define TIMSK_OCIE2				7							/*Timer/Counter0 Compare Match Interrupt Enable Bit*/

#define TIFR					*((volatile u8*)0x58)		/*Timer/Counter Interrupt Flag Register*/
#define TIFR_TOV0				0							/*Timer/Counter0 Overflow Flag*/
#define TIFR_OCF0				1							/*Timer/Counter0 Compare Flag*/
#define TIFR_TOV1				2							/*Timer/Counter1 Overflow Flag*/
#define TIFR_OCF1B				3							/*Timer/Counter1 Output Compare B Match Flag*/
#define TIFR_OCF1A				4							/*Timer/Counter1 Output Compare A Match Flag*/
#define TIFR_ICF1				5							/*Timer/Counter1 Input Capture Flag*/
#define TIFR_TOV2				6							/*Timer/Counter0 Overflow Flag*/
#define TIFR_OCF2				7							/*Timer/Counter0 Compare Flag*/


#endif