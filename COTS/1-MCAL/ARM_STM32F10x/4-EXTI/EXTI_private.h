/*
 * Author : Bassam Mahmoud
 * Layer  : MCAl
 * SWC    : EXTI
 * Version: 1.0
 * Created: NOV/23/2023
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_


#define EXTI_BASE		0x40010400UL

typedef struct
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
	
}EXTI_t;

#define EXTI			((EXTI_t*) EXTI_BASE)

void (*NotFunc[16])(void);

u8 EXTI_u8SetCallBack(u8 Copy_u8Line, void(*Copy_voidNotFunc)(void));

u8 EXTI_u8ClearIntFlag(u8 Copy_u8Line);

#endif
