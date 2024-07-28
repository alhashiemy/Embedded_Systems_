/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAl
 * SWC    : STK
 * Version: 1.0
 * Created: JULY/15/2024
 */

#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_

void STK_voidInit(void);

u8 STK_u8StartCountSynch(u32 Copy_u8TimerValue);

u8 STK_u8StartCountASynch(u32 Copy_u8TimerValue, void (*Copy_voidNotFunc)(void));

u32 STK_u32GetElapsedTime(void);

u32 STK_u32GetRemainingTime(void);

#endif
