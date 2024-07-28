/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAL
 * SWC    : SPI
 * Version: 1.0
 * Created: DEC/9/2023
 */

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

#define SPI1_BASE		0x40013000

typedef struct {
	
	volatile u32 CR1		;
	volatile u32 CR2		;
	volatile u32 SR			;
	volatile u32 DR			;
	volatile u32 CRCPR		;
	volatile u32 RXCRCR		;
	volatile u32 TXCRCR		;
	volatile u32 SPI_I2SCFGR;
	volatile u32 I2SPR		;
	
}SPI_t;

#define	SPI1			((SPI_t*)SPI1_BASE)

#endif