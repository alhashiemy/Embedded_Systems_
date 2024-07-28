/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAl
 * SWC    : USART
 * Version: 1.0
 * Created: OCT/27/2023
 */

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

/*SET BAUD RATE*/
#define USART_BAUD_RATE					28800

/*OPTIONS,								USART_ASYNCHRONOUS
 *										USART_SYNCHRONOUS
 */
#define USART_MODE_SELECT				USART_ASYNCHRONOUS

/*OPTIONS,								USART_FIVE_BITS	
 *										USART_SIX_BITS	
 *										USART_SEVEN_BITS
 *										USART_EIGHT_BITS
 *										USART_NINE_BITS	
 */
#define CHAR_SIZE						USART_EIGHT_BITS

/*OPTIONS,								DISABLED
 *										EVEN_PARITY
 *										ODD_PARITY
 */
#define PARITY_MODE						USART_PARITY_DISABLED

/*OPTIONS,								ONE_STOP_BIT
 *										TWO_STOP_BITS
 */
#define STOP_BIT						USART_ONE_STOP_BIT

/*TIMEOUT ITERATION IS USED SO THAT THE PROGRAM DOES NOT STUCK 
 *AT SYNCHRONOUS FUNCTIONS
 *OPTIONS, SET THE NUMBER OF ITERATION YOU WANT
 */
#define USART_TimeOut_Iteraton_num		1000

#endif