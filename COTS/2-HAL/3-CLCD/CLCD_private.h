/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : HAL
 * SWC    : CLCD
 * Version: 1.0
 * Created: JUN/10/2024
 */

#ifndef CLCD_PRIVATE_H_
#define CLCD_PRIVATE_H_

#define CLCD_DISBLAY_CLEAR					0x01
#define CLCD_RETURN_HOME					0x02
#define CLCD_INCREMENT_DDRAM				0x06
#define CLCD_DISBLAY_ON						0x0c
#define CLCD_FOUR_BIT						0x28
#define CLCD_EIGHT_BIT						0x38
#define	CLCD_SET_CGRAM						0x40
#define CLCD_LINE_ADDRESSES					{0x80,0xc0,0x94,0xD4}

#define CGRAM_FIRST_ADDRISS					0x40

static void CLCD_voidSendData(u8 Copy_u8Data);
static void CLCD_voidSendCommand(u8 Copy_u8Command);

#endif