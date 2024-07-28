/*
 * Author : Bassam Mahmoud
 * Layer  : MCAl
 * SWC    : EXTI
 * Version: 1.0
 * Created: NOV/23/2023
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI_RISING_EDGE		0
#define EXTI_FALLING_EDGE		1

/* OPTIONS, FOR   Copy_u8Line:	USE LINE NUMBER
 *
 * 				  Copy_u8Mode:	EXTI_RISING_EDGE
 * 				  				EXTI_FALLING_EDGE
 */

u8 EXTI_u8SetInit(u8 Copy_u8Line, u8 Copy_u8Mode);

u8 EXTI_u8EnableInit(u8 Copy_u8Line,  void (*Copy_u8NotFunc)(void));

u8 EXTI_u8DisableInit(u8 Copy_u8Line);

u8 EXTI_u8SWInt(u8 Copy_u8Line);

#endif
