/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAl
 * SWC    : AFIO
 * Version: 1.0
 * Created: JULY/15/2024
 */

#ifndef AFIO_CONFIG_H_
#define AFIO_CONFIG_H_


#define AFIO_BASE		(0x40010000UL)

typedef struct
{
	u32 EVCR;
	u32 MAPR;
	u32 EXTICR[4];
	u32 MAPR2;

}AFIO_t;


#define AFIO	((volatile AFIO_t*)AFIO_BASE)


#endif
