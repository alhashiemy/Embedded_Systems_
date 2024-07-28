/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : HAL
 * SWC	  : SSD
 * Version: 1.0
 * Created: JUN/6/2023
 */

#ifndef SSD_PRIVATE_H_
#define SSD_PRIVATE_H_

#define SSD_COM_CATH			0
#define SSD_COM_ANOD			1

#define SSD_DATA_PORT			0
#define SSD_DATA_PIN			1

#define SSD_EN_PORT				0
#define SSD_EN_PIN				1


static u8 EnablePin[6][2] = {{SSD_ENABLE_PIN0}, {SSD_ENABLE_PIN1}, {SSD_ENABLE_PIN2}, {SSD_ENABLE_PIN3}, {SSD_ENABLE_PIN4}, {SSD_ENABLE_PIN5}};


#endif