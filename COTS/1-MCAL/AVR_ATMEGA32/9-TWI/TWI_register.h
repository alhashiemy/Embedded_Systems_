/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAl
 * SWC    : TWI
 * Version: 1.0
 * Created: NOV/5/2023
 */

#ifndef TWI_REGISTER_H_
#define TWI_REGISTER_H_

#define TWBR						*((volatile u8*)0x20)
#define TWSR						*((volatile u8*)0x21)
#define TWAR						*((volatile u8*)0x22)
#define TWDR						*((volatile u8*)0x23)
#define TWCR						*((volatile u8*)0x56)
#define TWCR_TWINT					7
#define TWCR_TWEA					6
#define TWCR_TWSTA					5
#define TWCR_TWSTO					4
#define TWCR_TWWC					3
#define TWCR_TWEN					2
#define TWCR_TWIE					0

#endif