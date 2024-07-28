/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAl
 * SWC    : GPIO
 * Version: 1.0
 * Created: JULY/6/2024
 */

#ifndef GPIO_CONFIG_H_
#define GPIO_CONFIG_H_

/*OPTIONS,TO CONFIG GPIO PINS MODE:
 *
 *								INPUT_ANALOG
 *                      		INPUT_FLOATING
 *                      		INPUT_PULL_UP_DOWN
 *
 *                      		OUTPUT_PP_10MHZ
 *                      		OUTPUT_OD_10MHZ
 *                      		OUTPUT_AFPP_10MHZ
 *                      		OUTPUT_AFOD_10MHZ
 *
 *                      		OUTPUT_PP_2MHZ
 *                      		OUTPUT_OD_2MHZ
 *                      		OUTPUT_AFPP_2MHZ
 *                      		OUTPUT_AFOD_2MHZ
 *
 *                      		OUTPUT_PP_50MHZ
 *                      		OUTPUT_OD_50MHZ
 *                      		OUTPUT_AFPP_50MHZ
 *                      		OUTPUT_AFOD_50MHZ
 *
 */

#define GPIOA_PIN0__MODE        INPUT_ANALOG
#define GPIOA_PIN1__MODE        INPUT_ANALOG
#define GPIOA_PIN2__MODE        INPUT_ANALOG
#define GPIOA_PIN3__MODE        OUTPUT_PP_2MHZ
#define GPIOA_PIN4__MODE        INPUT_ANALOG
#define GPIOA_PIN5__MODE        INPUT_ANALOG
#define GPIOA_PIN6__MODE        INPUT_ANALOG
#define GPIOA_PIN7__MODE        INPUT_ANALOG
#define GPIOA_PIN8__MODE        INPUT_ANALOG
#define GPIOA_PIN9__MODE        INPUT_ANALOG
#define GPIOA_PIN10_MODE        INPUT_ANALOG
#define GPIOA_PIN11_MODE        INPUT_ANALOG
#define GPIOA_PIN12_MODE        INPUT_ANALOG
#define GPIOA_PIN13_MODE        INPUT_ANALOG
#define GPIOA_PIN14_MODE        INPUT_ANALOG
#define GPIOA_PIN15_MODE        INPUT_ANALOG

#define GPIOB_PIN0__MODE        INPUT_ANALOG
#define GPIOB_PIN1__MODE        INPUT_ANALOG
#define GPIOB_PIN2__MODE        INPUT_ANALOG
#define GPIOB_PIN3__MODE        INPUT_ANALOG
#define GPIOB_PIN4__MODE        INPUT_ANALOG
#define GPIOB_PIN5__MODE        INPUT_ANALOG
#define GPIOB_PIN6__MODE        INPUT_ANALOG
#define GPIOB_PIN7__MODE        INPUT_ANALOG
#define GPIOB_PIN8__MODE        INPUT_ANALOG
#define GPIOB_PIN9__MODE        INPUT_ANALOG
#define GPIOB_PIN10_MODE        INPUT_ANALOG
#define GPIOB_PIN11_MODE        INPUT_ANALOG
#define GPIOB_PIN12_MODE        INPUT_ANALOG
#define GPIOB_PIN13_MODE        INPUT_ANALOG
#define GPIOB_PIN14_MODE        INPUT_ANALOG
#define GPIOB_PIN15_MODE        INPUT_ANALOG

#define GPIOC_PIN13_MODE        INPUT_ANALOG
#define GPIOC_PIN14_MODE        INPUT_ANALOG
#define GPIOC_PIN15_MODE        INPUT_ANALOG


/*OPTIONS,TO CONFIG GPIO PINS INITIAL VALUE:
 *
 *									PIN_LOW
 *                      			PIN_HIGH
 *
 */
#define GPIOA_PIN0__INIT_VAL        PIN_LOW
#define GPIOA_PIN1__INIT_VAL        PIN_LOW
#define GPIOA_PIN2__INIT_VAL        PIN_LOW
#define GPIOA_PIN3__INIT_VAL        PIN_HIGH
#define GPIOA_PIN4__INIT_VAL        PIN_LOW
#define GPIOA_PIN5__INIT_VAL        PIN_LOW
#define GPIOA_PIN6__INIT_VAL        PIN_LOW
#define GPIOA_PIN7__INIT_VAL        PIN_LOW
#define GPIOA_PIN8__INIT_VAL        PIN_LOW
#define GPIOA_PIN9__INIT_VAL        PIN_LOW
#define GPIOA_PIN10_INIT_VAL        PIN_LOW
#define GPIOA_PIN11_INIT_VAL        PIN_LOW
#define GPIOA_PIN12_INIT_VAL        PIN_LOW
#define GPIOA_PIN13_INIT_VAL        PIN_LOW
#define GPIOA_PIN14_INIT_VAL        PIN_LOW
#define GPIOA_PIN15_INIT_VAL        PIN_LOW

#define GPIOB_PIN0__INIT_VAL        PIN_LOW
#define GPIOB_PIN1__INIT_VAL        PIN_LOW
#define GPIOB_PIN2__INIT_VAL        PIN_LOW
#define GPIOB_PIN3__INIT_VAL        PIN_LOW
#define GPIOB_PIN4__INIT_VAL        PIN_LOW
#define GPIOB_PIN5__INIT_VAL        PIN_LOW
#define GPIOB_PIN6__INIT_VAL        PIN_LOW
#define GPIOB_PIN7__INIT_VAL        PIN_LOW
#define GPIOB_PIN8__INIT_VAL        PIN_LOW
#define GPIOB_PIN9__INIT_VAL        PIN_LOW
#define GPIOB_PIN10_INIT_VAL        PIN_LOW
#define GPIOB_PIN11_INIT_VAL        PIN_LOW
#define GPIOB_PIN12_INIT_VAL        PIN_LOW
#define GPIOB_PIN13_INIT_VAL        PIN_LOW
#define GPIOB_PIN14_INIT_VAL        PIN_LOW
#define GPIOB_PIN15_INIT_VAL        PIN_LOW

#define GPIOC_PIN13_INIT_VAL        PIN_LOW
#define GPIOC_PIN14_INIT_VAL        PIN_LOW
#define GPIOC_PIN15_INIT_VAL        PIN_LOW


#endif
