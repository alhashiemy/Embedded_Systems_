/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAl
 * SWC    : GPIO
 * Version: 1.0
 * Created: JULY/6/2024
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_


#define CONC_HEX(P7,P6,P5,P4,P3,P2,P1,P0)				CONC_HEX_HELPER(P7,P6,P5,P4,P3,P2,P1,P0)
#define CONC_HEX_HELPER(P7,P6,P5,P4,P3,P2,P1,P0)		0x##P7##P6##P5##P4##P3##P2##P1##P0

#define CONC_BI(P15,P14,P13,P12,P11,P10,P9,P8,P7,P6,P5,P4,P3,P2,P1,P0)				CONC_BI_HELPER(P15,P14,P13,P12,P11,P10,P9,P8,P7,P6,P5,P4,P3,P2,P1,P0)
#define CONC_BI_HELPER(P15,P14,P13,P12,P11,P10,P9,P8,P7,P6,P5,P4,P3,P2,P1,P0)		0b##P15##P14##P13##P12##P11##P10##P9##P8##P7##P6##P5##P4##P3##P2##P1##P0

#define GPIOA_CRL_MODE	CONC_HEX(GPIOA_PIN7__MODE,\
								 GPIOA_PIN6__MODE,\
								 GPIOA_PIN5__MODE,\
								 GPIOA_PIN4__MODE,\
								 GPIOA_PIN3__MODE,\
								 GPIOA_PIN2__MODE,\
								 GPIOA_PIN1__MODE,\
								 GPIOA_PIN0__MODE)

#define GPIOA_CRH_MODE	CONC_HEX(GPIOA_PIN15_MODE,\
								 GPIOA_PIN14_MODE,\
								 GPIOA_PIN13_MODE,\
								 GPIOA_PIN12_MODE,\
								 GPIOA_PIN11_MODE,\
								 GPIOA_PIN10_MODE,\
								 GPIOA_PIN9__MODE,\
								 GPIOA_PIN8__MODE)

#define GPIOB_CRL_MODE	CONC_HEX(GPIOB_PIN7__MODE,\
								 GPIOB_PIN6__MODE,\
								 GPIOB_PIN5__MODE,\
								 GPIOB_PIN4__MODE,\
								 GPIOB_PIN3__MODE,\
								 GPIOB_PIN2__MODE,\
								 GPIOB_PIN1__MODE,\
								 GPIOB_PIN0__MODE)

#define GPIOB_CRH_MODE	CONC_HEX(GPIOB_PIN15_MODE,\
								 GPIOB_PIN14_MODE,\
								 GPIOB_PIN13_MODE,\
								 GPIOB_PIN12_MODE,\
								 GPIOB_PIN11_MODE,\
								 GPIOB_PIN10_MODE,\
								 GPIOB_PIN9__MODE,\
								 GPIOB_PIN8__MODE)

#define GPIOC_CRH_MODE	CONC_HEX(GPIOC_PIN15_MODE,\
								 GPIOC_PIN14_MODE,\
								 GPIOC_PIN13_MODE,\
								 0,\
								 0,\
								 0,\
								 0,\
								 0)


#define GPIOA_INIT_VAL	CONC_BI(GPIOA_PIN15_INIT_VAL,\
								GPIOA_PIN14_INIT_VAL,\
								GPIOA_PIN13_INIT_VAL,\
								GPIOA_PIN12_INIT_VAL,\
								GPIOA_PIN11_INIT_VAL,\
								GPIOA_PIN10_INIT_VAL,\
								GPIOA_PIN9__INIT_VAL,\
								GPIOA_PIN8__INIT_VAL,\
								GPIOA_PIN7__INIT_VAL,\
								GPIOA_PIN6__INIT_VAL,\
								GPIOA_PIN5__INIT_VAL,\
								GPIOA_PIN4__INIT_VAL,\
								GPIOA_PIN3__INIT_VAL,\
								GPIOA_PIN2__INIT_VAL,\
								GPIOA_PIN1__INIT_VAL,\
								GPIOA_PIN0__INIT_VAL)

#define GPIOB_INIT_VAL	CONC_BI(GPIOB_PIN15_INIT_VAL,\
								GPIOB_PIN14_INIT_VAL,\
								GPIOB_PIN13_INIT_VAL,\
								GPIOB_PIN12_INIT_VAL,\
								GPIOB_PIN11_INIT_VAL,\
								GPIOB_PIN10_INIT_VAL,\
								GPIOB_PIN9__INIT_VAL,\
								GPIOB_PIN8__INIT_VAL,\
								GPIOB_PIN7__INIT_VAL,\
								GPIOB_PIN6__INIT_VAL,\
								GPIOB_PIN5__INIT_VAL,\
								GPIOB_PIN4__INIT_VAL,\
								GPIOB_PIN3__INIT_VAL,\
								GPIOB_PIN2__INIT_VAL,\
								GPIOB_PIN1__INIT_VAL,\
								GPIOB_PIN0__INIT_VAL)

#define GPIOC_INIT_VAL	CONC_BI(GPIOC_PIN15_INIT_VAL,\
								GPIOC_PIN14_INIT_VAL,\
								GPIOC_PIN13_INIT_VAL,\
								0,\
								0,\
								0,\
								0,\
								0,\
								0,\
								0,\
								0,\
								0,\
								0,\
								0,\
								0,\
								0)

#define LCKR_LCKK				16

#define INPUT_ANALOG			0
#define INPUT_FLOATING			4
#define INPUT_PULL_UP_DOWN		8

#define OUTPUT_PP_10MHZ			1
#define OUTPUT_OD_10MHZ			5
#define OUTPUT_AFPP_10MHZ		9
#define OUTPUT_AFOD_10MHZ		C

#define OUTPUT_PP_2MHZ			2
#define OUTPUT_OD_2MHZ			6
#define OUTPUT_AFPP_2MHZ		A
#define OUTPUT_AFOD_2MHZ		D

#define OUTPUT_PP_50MHZ			3
#define OUTPUT_OD_50MHZ			7
#define OUTPUT_AFPP_50MHZ		B
#define OUTPUT_AFOD_50MHZ		F

#define PIN_LOW					0
#define PIN_HIGH				1


/* GPIO PORTS BASE ADDRESSES */
#define GPIOA_BASE			0x40010800UL
#define GPIOB_BASE			0x40010C00UL
#define GPIOC_BASE			0x40011000UL

/* GPIO OFFSET ADDRESSES */
typedef struct {

	volatile u32 CRL ;
	volatile u32 CRH ;
	volatile u32 IDR ;
	volatile u32 ODR ;
	volatile u32 BSRR;
	volatile u32 BRR ;
	volatile u32 LCKR;

}GPIO_t;

#define GPIOA		((GPIO_t*)GPIOA_BASE)
#define GPIOB		((GPIO_t*)GPIOB_BASE)
#define GPIOC		((GPIO_t*)GPIOC_BASE)

#endif
