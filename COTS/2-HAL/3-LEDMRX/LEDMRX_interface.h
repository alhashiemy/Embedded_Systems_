/*
 * Author : Bassam_Mahmoud_
 * Layer  : HAL
 * SWC	  : LEDMRX
 * Version: 1.1
 * Created: JULY/31/2024
 */

#ifndef LEDMRX_INTERFACE_H_
#define LEDMRX_INTERFACE_H_


/* NOTE: THIES FUNCTIONS DEPENDS ON SYSTICK SO INTIATE SYSTICK BEFORE USING IT */

void LEDMRX_voidInit(void);

void LEDMRX_voidSendChar(char* Copy_Pu8Char);

void LEDMRX_voidSendString(const char* Copy_Pu8String);

#endif
