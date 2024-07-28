/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAL
 * SWC    : SPI
 * Version: 1.0
 * Created: DEC/9/2023
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


void SPI_voidInit(void);

u8 SPI_u8TranceiveSynch(u8 Copy_u8TData, u8* Copy_u8RData);

u8 SPI_u8TranceiveAsynch(u8 Copy_u8TData, void (*Copy_voidNotFunc)(u8 Copy_u8RData));

#endif
