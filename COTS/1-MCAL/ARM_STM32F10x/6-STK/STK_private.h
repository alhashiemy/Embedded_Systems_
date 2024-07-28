/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAl
 * SWC    : STK
 * Version: 1.0
 * Created: JULY/15/2024
 */

#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_

#define PROCESSOR_CLOCK_AHB				1
#define AHB_BY_EIGHT					0

#define STK_INTERRUPT_ENABLED			1
#define STK_INTERRUPT_DISABLED			0

#define STK_ENABLE						0
#define STK_INTERRUPT					1
#define STK_CLKSOURCE					2
#define STK_COUNTFLAG					16


#define STK_BASE		0xE000E010

typedef struct {
	
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
	
}STK_t;

#define STK		((STK_t*)STK_BASE)

#endif
