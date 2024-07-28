/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAL
 * SWC    : UART
 * Version: 1.0
 * Created: DEC/9/2023
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define UART_SR_TXE			7
#define UART_SR_TC			6
#define UART_SR_RXNE		5


#define UART_CR1_UE			13
#define UART_CR1_TXEIE		7
#define UART_CR1_TCIE		6
#define UART_CR1_RXNEIE		5
#define UART_CR1_TE			3
#define UART_CR1_RE			2

static u8* u8TData = NULL;
static u8* u8RData = NULL;

static void (*voidTxNotFunc)(void) = NULL;
static void (*voidRxNotFunc)(void) = NULL;

static void (*USART1_IRQTx)(void) = NULL;
static void (*USART1_IRQRx)(void) = NULL;

static u8 u8TxState = IDL;
static u8 u8RxState = IDL;

static void USART1_voidTransmitIRQ(void);
static void USART1_voidReceiveIRQ(void);



#endif
