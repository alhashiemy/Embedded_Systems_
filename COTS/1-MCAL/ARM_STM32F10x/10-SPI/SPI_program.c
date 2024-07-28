/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAL
 * SWC    : SPI
 * Version: 1.0
 * Created: DEC/9/2023
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_register.h"
#include "SPI_config.h"
#include "SPI_private.h"

void SPI_voidInit(void)
{
	SPI1->CR1 = SPI_CONFIG ;
}

u8 SPI_u8TranceiveSynch(u8 Copy_u8TData, u8* Copy_u8RData)
{
	u8 Local_u8ErrorState = CLEAR;
	if(Copy_u8RData!=NULL)
	{
		/* CHECK BUSY STATE */
		if(u8BusyState == IDL)
		{
			/* SET u8BusyState to BUSY STATE */
			u8BusyState = BUSY;

			/* ENABLE SPI PERIPHIRAL */
			SET_BIT(SPI1->CR1, SPI_CR1_SPE);

			/* WAIT UNTIL TXE INTERRUPT IS RAISED */
			while(GET_BIT(SPI1->SR, SPI_SR_TXE) == 0);

			/* SET TRANSMESSION DATA TO DATA REG */
			SPI1->DR = Copy_u8TData;

			/* MAKE BUSY WAITING ON BUSY FLAG */
			while(GET_BIT(SPI1->SR, SPI_SR_RXNE) == 0);

			/* GET RECEIVED DATA */
			*Copy_u8RData = SPI1->DR;

			/* DISABLE SPI PERIPHIRAL */
			CLR_BIT(SPI1->CR1, SPI_CR1_SPE);

			/* RETURN u8BusyState to IDL STATE */
			u8BusyState = IDL;

		}
		else
		{
			Local_u8ErrorState = BUSY;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}

u8 SPI_u8TranceiveAsynch(u8 Copy_u8TData, void (*Copy_voidNotFunc)(u8 Copy_u8RData))
{
	u8 Local_u8ErrorState = CLEAR;
	if(Copy_voidNotFunc!=NULL)
	{
		/* CHECK BUSY STATE */
		if(u8BusyState == IDL)
		{
			/* SET u8BusyState to BUSY STATE */
			u8BusyState = BUSY;

			/* SET CALLBACK NOTIFICATION FUNCTION */
			NotFunc = Copy_voidNotFunc;

			/* ENABLE SPI PERIPHIRAL */
			SET_BIT(SPI1->CR1, SPI_CR1_SPE);

			/* ENABLE SPI RX NOT EMPTY INTERRUPT */
			SET_BIT(SPI1->CR2, SPI_CR2_RXNEIE);

			/* WAIT UNTIL TXE INTERRUPT IS RAISED */
			while(GET_BIT(SPI1->SR, SPI_SR_TXE) == 0);

			/* SET TRANSMESSION DATA TO DATA REG (SET DATA TO TX BUFFER) */
			SPI1->DR = Copy_u8TData;

		}
		else
		{
			Local_u8ErrorState = BUSY;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}


void SPI1_IRQHandler(void)
{
	/* DISABLE PERIPHERAL */
	CLR_BIT(SPI1->CR1, SPI_CR1_SPE);

	/* DISABLE RX NOT EMPTY INTERRUPT */
	CLR_BIT(SPI1->CR2, SPI_CR2_RXNEIE);

	/* RETURN u8BusyState to IDL STATE */
	u8BusyState = IDL;

	/* CALL NOTIFICATION FUNCTION */
	NotFunc((u8)SPI1->DR);
}
