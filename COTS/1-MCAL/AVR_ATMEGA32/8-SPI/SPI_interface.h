/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAl
 * SWC    : SPI
 * Version: 1.0
 * Created: NOV/5/2023
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_voidInit(void);

u8 SPI_u8TranceiveSynch(u8* Copy_Pu8SendData, u8* Copy_Pu8ReceiveData);

u8 SPI_u8TranceiveASynch(u8* Copy_Pu8SendData, u8* Copy_Pu8ReceiveData, void(*Copy_PvoidNotFunc)(void));

#endif