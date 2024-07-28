/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : HAL
 * SWC    : KPD
 * Version: 1.0
 * Created: JUN/11/2024
 */


#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

/*NOTE, RETURN OF KPD_u8GetNum FUNCIONS IS: 0x00(CLEAR)					WHILE ANY KEY PRESSED
 *											0xFE(KPD_NO_PRESSED_KEY)	WHILE NO KEY IS PRESSED
 *											0xFF(NULL_POINTER)			WHILE PASSING NULL POINER
 */
u8 KPD_u8GetNum(u8* Copy_Pu8KPD);

u8 KPD_u8ConcNum(u8* Copy_u8NumArr,u32* Copy_u32NumPtr);

#endif