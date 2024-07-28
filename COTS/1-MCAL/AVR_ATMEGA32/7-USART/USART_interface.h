/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAl
 * SWC    : USART
 * Version: 1.0
 * Created: OCT/27/2023
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_voidInit(void);

u8 USART_u8SendCharSynch(u8* Copy_u8Char);

u8 USART_u8ReceiveCharSynch(u8* Copy_u8Char);

u8 USART_u8SendStringSynch(u8* Copy_u8String);

u8 USART_u8ReceiveStringSynch(u8* Copy_u8String);


u8 USART_u8SendCharASynch(u8* Copy_u8Data, void (*NotificationFunc)(void));

u8 USART_u8ReceiveCharASynch(u8* Copy_u8Data, void (*NotificationFunc)(void));

u8 USART_u8SendStringASynch(u8* Copy_u8String, void (*NotificationFunc)(void));

u8 USART_u8ReceiveStringASynch(u8* Copy_u8String, void (*NotificationFunc)(void));

#endif