/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAl
 * SWC    : RCC
 * Version: 1.0
 * Created: JULY/6/2024
 */
 

#ifndef	RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

#define PLLMUL_MASK					0xFFC3FFFF

#define CR_PLLON					24
#define CR_PLLRDY					25
#define CR_HSEON					16
#define CR_HSERDY					17
#define CR_HSEBYP					18
#define CR_HSION					0
#define CR_HSIRDY					1

#define CFGR_PLLMUL3				21
#define CFGR_PLLMUL2				20
#define CFGR_PLLMUL1				19
#define CFGR_PLLMUL0				18
#define CFGR_PLLXTPRE				17
#define CFGR_PLLSRC					16
#define CFGR_SWS1					3
#define CFGR_SWS0					2
#define CFGR_SW1					1
#define CFGR_SW0					0


/* REGISTER DISCRIPTION */
#define RCC_BASE		0x40021000UL

typedef struct {
	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;
}RCC_t;

#define RCC				((RCC_t*)RCC_BASE)

#endif
