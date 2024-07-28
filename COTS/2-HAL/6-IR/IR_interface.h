/*
 * Author : Bassam Mahmoud
 * Layer  : HAL
 * SWC    : IR
 * Version: 1.0
 * Created: DEC/2/2023
 */

#ifndef IR_INTERFACE_H_
#define	IR_INTERFACE_H_

/* NOTE: INTIATE SYSTICK & ENABLE RCC FOR GPIO FOR THE USED PORT BEFOR USING THIES FUNCTIONS */

void IR_voidInit(void);

void IR_voidStartReceivingAsync(u8* Copy_Pu8ReceivedData, void(*Copy_PvoidNotFunc)(void));


#endif
