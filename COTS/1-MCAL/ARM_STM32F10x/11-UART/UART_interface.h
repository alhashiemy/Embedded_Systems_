/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAL
 * SWC    : UART
 * Version: 1.0
 * Created: DEC/9/2023
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART1_voidInit(void);

u8 UART1_u8TransmitSynch(u8* Copy_u8TData);

u8 UART1_u8TransmitAsynch(u8* Copy_Pu8TData, void (*Copy_voidNotFunc)(void));

u8 UART1_u8ReceiveSynch(u8* Copy_Pu8RData);

u8 UART1_u8ReceiveAsync(u8* Copy_Pu8RData, void (*Copy_voidNotFunc)(void));


#endif
