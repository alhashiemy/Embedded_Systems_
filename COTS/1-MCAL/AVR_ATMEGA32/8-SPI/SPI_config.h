/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAl
 * SWC    : SPI
 * Version: 1.0
 * Created: NOV/5/2023
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/* OPTIONS,							SPI_MASTER
 *									SPI_SLAVE
 */
#define SPI_MODE					SPI_MASTER

/* OPTIONS,							SPI_MSB					the MOST SIGNEFICANT BI of the data word is transmitted first
 *									SPI_LSB					the LEAST SIGNEFICANT BI of the data word is transmitted first
 */
#define SPI_DATA_ORDER				SPI_MSB

/* OPTIONS,							SPI_RISING_FIRST		rising with leading edge, falling with trailling edge
 *									SPI_FALLING_FIRST		falling with with leading edge, rising trailling edge
 */
#define SPI_CLOCK_POLARITY			SPI_RISING_FIRST

/* OPTIONS,							SPI_SAMPLE_FIRST		sample with leading edge, setup with trailling edge
 *									SPI_SETUP_FIRST			setup with leading edge, sample with trailling edge
 */
#define SPI_CLOCK_PHASE				SPI_SAMPLE_FIRST

/* OPTIONS,							SPI_DIVID_BY_4
*									SPI_DIVID_BY_16
*									SPI_DIVID_BY_64
*									SPI_DIVID_BY_128
 */
#define SPI_CLOCK_RATE				SPI_DIVID_BY_128

/* OPTIONS,							SPI_DOUBLE_SPEED_OFF
 *									SPI_DOUBLE_SPEED_ON	
 */
#define SPI_DOUBLE_SPEED			SPI_DOUBLE_SPEED_OFF

/* OPTIONS,							SET TIMEOUT	IN MS
 */
#define SPI_TIMEOUT					10000

#endif