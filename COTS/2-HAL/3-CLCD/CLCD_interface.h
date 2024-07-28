/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : HAL
 * SWC    : CLCD
 * Version: 1.0
 * Created: JUN/10/2024
 */

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

void CLCD_voidInit(void);

void CLCD_voidClr();

void CLCD_voidWriteNUM(u32 Copy_u32NUM);

u8 CLCD_u8SendString(const char* CLCD_Pu8String);

u8 CLCD_u8WriteNewChar(u8* Copy_Pu8Data, u8 Copy_u8BlockNum);

u8 CLCD_u8GoToXY(u8 Copy_u8Row, u8 Copy_u8Colom);

#endif