/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAL
 * SWC    : SPI
 * Version: 1.0
 * Created: DEC/9/2023
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

static u8 u8BusyState = IDL;
static void (*NotFunc)(u8 Data) = NULL;

#define SPI_SLAVE 					0
#define SPI_MASTER					1

#define SPI_MSB						0
#define SPI_LSB						1

#define SPI_RISING_FIRST			0
#define SPI_FALLING_FIRST			1

#define SPI_SAMPLE_FIRST			0
#define SPI_SETUP_FIRST				1

#define fPCLK_BY_2  				000
#define fPCLK_BY_4                  001
#define fPCLK_BY_8                  010
#define fPCLK_BY_16                 011
#define fPCLK_BY_32                 100
#define fPCLK_BY_64                 101
#define fPCLK_BY_128                110
#define fPCLK_BY_256                111

#define SPI_DISABLED				0
#define SPI_ENABLED					1

#define SPI_CR1_SPE					6

#define SPI_CR2_TXEIE				7
#define SPI_CR2_RXNEIE				6

#define SPI_SR_BSY					7
#define SPI_SR_TXE					1
#define SPI_SR_RXNE					0


#define CONC(P7,P6,P5_4_3,P2,P1,P0)			COND_HELPER(P7,P6,P5_4_3,P2,P1,P0)
#define COND_HELPER(P7,P6,P5_4_3,P2,P1,P0)	0b##P7##P6##P5_4_3##P2##P1##P1

#define SPI_CONFIG		CONC(SPI_DATA_ORDER,SPI_DISABLED,SPI_CLOCK_RATE,SPI_MODE,SPI_CLOCK_POLARITY,SPI_CLOCK_PHASE)


#endif
