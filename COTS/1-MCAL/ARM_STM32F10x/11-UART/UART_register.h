/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAL
 * SWC    : UART
 * Version: 1.0
 * Created: DEC/9/2023
 */

#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_

#define UART1_BASE		0x40013800
#define UART2_BASE		0x40004400
#define UART3_BASE		0x40004800


typedef struct {

	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;

}UART_t;

#define		UART1		((UART_t*)UART1_BASE)
#define		UART2		((UART_t*)UART2_BASE)
#define		UART3		((UART_t*)UART3_BASE)

#endif
