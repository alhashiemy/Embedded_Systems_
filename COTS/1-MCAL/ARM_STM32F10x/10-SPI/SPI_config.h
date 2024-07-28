/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAL
 * SWC    : SPI
 * Version: 1.0
 * Created: DEC/9/2023
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/* OPTIONS,							SPI_SLAVE
 *									SPI_MASTER
 */
#define SPI_MODE					SPI_SLAVE

/* OPTIONS,							SPI_MSB					the MOST SIGNEFICANT BI of the data word is transmitted first
 *									SPI_LSB					the LEAST SIGNEFICANT BI of the data word is transmitted first
 */
#define SPI_DATA_ORDER				SPI_MSB

/* OPTIONS,							SPI_RISING_FIRST		rising with leading edge, falling with trailling edge
 *									SPI_FALLING_FIRST		falling with with leading edge, rising trailling edge
 */
#define SPI_CLOCK_POLARITY			SPI_FALLING_FIRST

/* OPTIONS,							SPI_SAMPLE_FIRST		sample with leading edge, setup with trailling edge
 *									SPI_SETUP_FIRST			setup with leading edge, sample with trailling edge
 */
#define SPI_CLOCK_PHASE				SPI_SETUP_FIRST

/* OPTIONS,							fPCLK_BY_2
 *									fPCLK_BY_4
 *									fPCLK_BY_8
 *									fPCLK_BY_16
 *                                  fPCLK_BY_32
 *									fPCLK_BY_64
 *                                  fPCLK_BY_128
 *                                  fPCLK_BY_256
 */
#define SPI_CLOCK_RATE				fPCLK_BY_256

#endif
