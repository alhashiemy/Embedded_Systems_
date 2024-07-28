/*
 * Author : Bassam Mahmoud
 * Layer  : HAL
 * SWC    : LEDMRX
 * Version: 1.0
 * Created: NOV/23/2023
 */

#ifndef LEDMRX_INTERFACE_H_
#define LEDMRX_INTERFACE_H_


/* NOTE: THIES FUNCTIONS DEPENDS ON SYSTICK SO INTIATE SYSTICK BEFORE USING IT */

void LEDMRX_voidInit(void);

void LEDMRX_voidSendChar(u8* Copy_Pu8CharArr);

void LEDMRX_voidSendString(u8* Copy_u8Data, u8 Copy_u8SizeOfData);

#endif
