/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAL
 * SWC    : UART
 * Version: 1.0
 * Created: DEC/9/2023
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_config.h"
#include "UART_private.h"
#include "UART_register.h"



void UART1_voidInit(void)
{
	/* SET BAUD RATE */
	u16 Local_u16Mantissa = 	((UART_SYS_FREQ / (UART_BAUD_RATE*16))<<4) ;
	u8  Local_u8Fraction  = (u8)((UART_SYS_FREQ % (UART_BAUD_RATE*16))*16) ;
	UART1->BRR = Local_u16Mantissa | Local_u8Fraction;
}

u8 UART1_u8TransmitSynch(u8* Copy_u8TData)
{
	u8 Local_u8ErrorState = CLEAR;
	u8 Local_u8Counter = 0;

	if(Copy_u8TData != NULL)
	{
		if(u8TxState == IDL)
		{
			/* SET u8TxState TO BUSY STATE */
			u8TxState = BUSY;

			/* ENABLE TRANSMITTER */
			SET_BIT(UART1->CR1, UART_CR1_TE);

			/* ENABLE UART PERIPHIRAL */
			SET_BIT(UART1->CR1, UART_CR1_UE);

			/* SEND DATA */
			while (Copy_u8TData[Local_u8Counter] != '\0')
			{
				/* SET DATA TO DATA REGISTER */
				UART1->DR = Copy_u8TData[Local_u8Counter];

				/* WAIT UNTIL DATA IS TRANSMITTED (BUSY WAITING ON TC REG) */
				while (GET_BIT(UART1->SR, UART_SR_TC) == 0);

				Local_u8Counter++;
			}

			/* DISABLE TRANSMITTER */
			CLR_BIT(UART1->CR1, UART_CR1_TE);

			/* DISABLE UART PERIPHIRAL */
			CLR_BIT(UART1->CR1, UART_CR1_UE);

			/* RESET u8TxState TO BUSY STATE */
			u8TxState = IDL;
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

u8 UART1_u8TransmitAsynch(u8* Copy_Pu8TData, void (*Copy_voidNotFunc)(void))
{
	u8 Local_u8ErrorState = CLEAR;

	if((Copy_Pu8TData != NULL) && (Copy_voidNotFunc!=NULL))
	{
		if(u8TxState == IDL)
		{
			/* SET TX STATE TO BUSY STATE */
			u8TxState = BUSY;

			/* PASS DATA REFERANCES TO ISR */
			u8TData = Copy_Pu8TData;
			voidTxNotFunc = Copy_voidNotFunc;

			/* SET UART TRANSMIT IRQ FUNCTION */
			USART1_IRQTx = USART1_voidTransmitIRQ;

			/* ENABLE TRANSMITTER */
			SET_BIT(UART1->CR1, UART_CR1_TE);

			/* ENABLE UART PERIPHIRAL */
			SET_BIT(UART1->CR1, UART_CR1_UE);

			/* ENABLE TRANSMIT BUFFER EMPTY INTERRUPT */
			SET_BIT(UART1->CR1, UART_CR1_TXEIE);
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

static void USART1_voidTransmitIRQ(void)
{
	static u8 Local_u8TxCounter = 0;

	if(u8TData[Local_u8TxCounter] != '\0')
	{
		UART1->DR = u8TData[Local_u8TxCounter];
		Local_u8TxCounter++;
	}
	else
	{
		UART1->DR = u8TData[Local_u8TxCounter];

		/* RESET COUNTER */
		Local_u8TxCounter  = 0;

		/* DISABLE TRANSMITTER */
		CLR_BIT(UART1->CR1, UART_CR1_TE);

		/* DISABLE TXEIE INTERRUPT */
		CLR_BIT(UART1->CR1, UART_CR1_TXEIE);

		/* RESET TX STATE */
		u8TxState = IDL;

		/* CALL NOTIFICATION FUNCTION */
		voidTxNotFunc();
	}
}


u8 UART1_u8ReceiveSynch(u8* Copy_Pu8RData)
{
	u8 Local_u8ErrorState = CLEAR;
	u8 Local_u8Counter = 0;

	if(Copy_Pu8RData != NULL)
	{
		if(u8RxState == IDL)
		{
			/* SET RX STATE TO BUSY STATE */
			u8RxState = BUSY;

			/* ENABLE RECEIVER */
			SET_BIT(UART1->CR1, UART_CR1_RE);

			/* ENABLE PERIPHERAL */
			SET_BIT(UART1->CR1, UART_CR1_UE);

			/* READ RECEIVED DATA */
			do
			{
				/* WAIT UNTIL DATA IS RECEIVED (SET BUSY WAITING ON RXNE) */
				while(GET_BIT(UART1->SR, UART_SR_RXNE) == 0);

				/* SET RECEIVED VALUE TO PASSED REFERANCE */
				Copy_Pu8RData[Local_u8Counter] = UART1->DR;

				Local_u8Counter++;

			}while(Copy_Pu8RData[Local_u8Counter-1] != '\0');

			/* DISABLE RECEIVER */
			CLR_BIT(UART1->CR1, UART_CR1_RE);

			/* DISABLE PERIPHRAL */
			CLR_BIT(UART1->CR1, UART_CR1_UE);

			/* RESET RX STATE TO IDL */
			u8RxState = IDL;
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

u8 UART1_u8ReceiveAsync(u8* Copy_Pu8RData, void (*Copy_voidNotFunc)(void))
{
	u8 Local_u8ErrorState = CLEAR;

	if((Copy_Pu8RData!= NULL) && (Copy_voidNotFunc != NULL))
	{
		if(u8RxState == IDL)
		{
			/* SET RX STATE TO BUSY STATE */
			u8RxState = BUSY;

			/* PASS DATA REFERANCES TO ISR */
			u8RData = Copy_Pu8RData;
			voidRxNotFunc = Copy_voidNotFunc;

			/* SET UART RECEIVE IRQ FUNCTION */
			USART1_IRQRx = USART1_voidReceiveIRQ;

			/* ENABLE RECEIVER */
			SET_BIT(UART1->CR1, UART_CR1_RE);

			/* ENABLE UART PERIPHIRAL */
			SET_BIT(UART1->CR1, UART_CR1_UE);

			/* ENABLE RECEIVE BUFFER NOT EMPTY INTERRUPT */
			SET_BIT(UART1->CR1, UART_CR1_RXNEIE);
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

static void USART1_voidReceiveIRQ(void)
{
	static u8 Local_u8RxCounter = 0;

	/* READ DATA RECEIVED */
	u8RData[Local_u8RxCounter] = (u8)UART1->DR;

	if(u8RData[Local_u8RxCounter] != '\0')
	{
		Local_u8RxCounter++;
	}
	else
	{
		/* RESET COUNTER */
		Local_u8RxCounter  = 0;

		/* DISABLE RECEIVER */
		CLR_BIT(UART1->CR1, UART_CR1_RE);

		/* DISABLE RXNEIE INTERRUPT */
		CLR_BIT(UART1->CR1, UART_CR1_RXNEIE);

		/* RESET TX STATE */
		u8RxState = IDL;

		/* CALL NOTIFICATION FUNCTION */
		voidRxNotFunc();
	}

}

void USART1_IRQHandler(void)
{
	if(USART1_IRQTx != NULL)
	{
		USART1_IRQTx();
	}

	if(USART1_IRQRx != NULL)
	{
		USART1_IRQRx();
	}

	if((u8TxState == IDL) && (u8RxState == IDL))
	{
		/* DISABLE PERIPHERAL */
		CLR_BIT(UART1->CR1, UART_CR1_UE);
	}
}
