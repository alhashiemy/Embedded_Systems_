/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAl
 * SWC    : NVIC
 * Version: 1.0
 * Created: JULY/6/2024
 */
 
#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#define SXTN_GROUP_ZERO_SUB		0
#define EIGHT_GROUP_TWO_SUB		1
#define FOUR_GROUP_FOUR_SUB		2
#define TWO_GROUP_EIGHT_SUB		3
#define ZERO_GROUP_SXTN_SUB		4

#define NVIC_FIRST_GROUPING		0x05FA0300

#define NVIC_PRIORITY_MASK		0x0F

#define NVIC_MAX_NUM			59


#define NVIC_BASE		0xE000E100UL
#define SCB_BASE		0xE000ED00UL

typedef struct {
	volatile u32 ISER 	  [32];
	volatile u32 ICER 	  [32];
	volatile u32 ISPR 	  [32];
	volatile u32 ICPR 	  [32];
	volatile u32 IABR 	  [32];
	volatile u32 RESERVID [32];
	volatile u8  IPR  	  [128];

}NVIC_t;

typedef struct {
	volatile u32 CPUID;
	volatile u32 ICSR;
	volatile u32 VTOR;
	volatile u32 AIRCR;
	volatile u32 SCR;
	volatile u32 CCR;
	volatile u32 SHPR1;
	volatile u32 SHPR2;
	volatile u32 SHPR3;
	volatile u32 SHCRS;
	volatile u32 CFSR;
	volatile u32 HFSR;
	volatile u32 RESERVED;
	volatile u32 MMAR;
	volatile u32 BFAR;

}SCB_t;

#define SCB				((SCB_t*)SCB_BASE)
#define NVIC			((NVIC_t*)NVIC_BASE)

#endif
