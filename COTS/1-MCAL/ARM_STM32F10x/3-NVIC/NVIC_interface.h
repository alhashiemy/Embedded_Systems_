/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAl
 * SWC    : NVIC
 * Version: 1.0
 * Created: JULY/6/2024
 */
 
#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

u8 NVIC_u8EnableInterrupt(u8 Copy_u8IntNumber);

u8 NVIC_u8DisableInterrupt(u8 Copy_u8IntNumber);

u8 NVIC_u8SetPendingFlag(u8 Copy_u8IntNumber);

u8 NVIC_u8ClaerPendingFlag(u8 Copy_u8IntNumber);

u8 NVIC_u8GetActiveFlag(u8 Copy_u8IntNumber, u8* Copy_u8FlagState);

u8 NVIC_u8SetPriority(u8 Copy_u8IntPriorityNum, u8 Copy_u8GroupPriority, u8 Copy_u8SupPriority);

#endif
