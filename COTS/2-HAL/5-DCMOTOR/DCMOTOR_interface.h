/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : HAL
 * SWC    : DCMOTOR
 * Version: 1.0
 * Created: JUN/14/2024
 */

#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_

#define	DCMOTOR_u8CHANNEL0			0 //OUTPUT ON PORTB_PIN3
#define	DCMOTOR_u8CHANNEL1			1 //OUTPUT ON PORTD_PIN7

void DCMOTOR_voidRotateCW();
void DCMOTOR_voidRotateCCW();

u8 DCMOTOR_u8RotateCW(u8 Copy_u8Pin0, u8 Copy_u8Pin1);
u8 DCMOTOR_u8RotateCCW(u8 Copy_u8Pin0, u8 Copy_u8Pin1);

u8 DCMOTOR_u8SetSpeed(u8 Copy_u8Speed, u8 Copy_u8TimerCannel);

#endif