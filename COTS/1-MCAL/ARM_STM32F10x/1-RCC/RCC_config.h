/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAl
 * SWC    : RCC
 * Version: 1.0
 * Created: JULY/6/2024
 */
 
#ifndef	RCC_CONFIG_H_
#define RCC_CONFIG_H_

/* OPTIONS,							HSI
 *									HSE
 */
#define RCC_CLOCK_SOURCE			HSI

/* OPTIONS, IF RCC_HSE	IS USED:	CRYSTAL
 *									RC
 */
#define RCC_XTAL_OSCI				CRYSTAL

/* OPTIONS,							PLL_HSI_DIV_BY_2
 *									PLL_HSE_DIV_BY_2
 *									PLL_HSE
 */
#define RCC_PLL_SOURCE				PLL_HSE

/* OPTIONS, IF PLL IS ON:			PLL_input_clock_x_FACTOR (from 2 to 16)
 */		
#define RCC_PLL_MUL					PLL_input_clock_x_2

/*OPTIONS,							HSI
 * 									HSE
 * 									PLL
 */

#define RCC_OUTPUT_CLOCK			HSI


#endif
