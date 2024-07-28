/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAl
 * SWC    : TWI
 * Version: 1.0
 * Created: NOV/5/2023
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "TWI_config.h"
#include "TWI_private.h"
#include "TWI_register.h"
#include "TWI_interface.h"

void TWI_voidMasterInit(u8 Copy_u8MasterAddress)
{
	/*SET CLOCK SPEED TO 400 KBPS WHIN PRESCALLER = 0*/
	TWBR=2;
	
	/*CLEAR 2 BITS OF PRESCALER*/
	TWSR&=0b11111100;
	
	/*SET ACKNOLEDGE BIT*/
	SET_BIT(TWCR,TWCR_TWEA);
	
	/*INITIALIS NODE ADDRESS*/
	if (Copy_u8MasterAddress!=0)
	{
		/*SET ADDRESS BITS AT MOST SEGINFICANT BIT*/
		TWAR=(Copy_u8MasterAddress<<1);
	} 
	
	/*ENABLE TWI*/
	SET_BIT(TWCR,TWCR_TWEN); /*NOTE: THIS STEP RAISES TWI INTERRUPT FLAG*/
	
}

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
	/*SET NODE ADDRESS*/
	TWAR=(Copy_u8SlaveAddress<<1);
	
	/*ENABLE TWI*/
	SET_BIT(TWCR,TWCR_TWEN);
}

TWI_ErrorStatus TWI_SendStartCondition(void)
{
	TWI_ErrorStatus Local_ErrorState=NoError;
	
	/*SEND START CONDITION ON THE BUS*/
	SET_BIT(TWCR,TWCR_TWSTA);
	
	/*CLEAR THE INTERRPT FLAG TO START THE PREVIOUS OPERATION*/
	/*KNOWING THAT THE FLAG IS INITIALLY ZERO SO WE COULD SKIP THIS STEP*/
	
	/*WAIT UNTIL THE INTERRUPT FLAG IS RISED(THE START CONDETION IS ENDED)*/
	while(GET_BIT(TWCR,TWCR_TWINT)!=1);
	
	/*CHACK STATUS REGISTER TO*/
	if ((TWSR&0xf8) != START_ACK)
	{
		Local_ErrorState=StartConditionError;
	}
	else
	{
		/*CLEAR START CONDITION BIT*/
		CLR_BIT(TWCR,TWCR_TWSTA);
	}
	return Local_ErrorState;
}
TWI_ErrorStatus TWI_SendRepeatedStart(void)
{
	TWI_ErrorStatus Local_ErrorState;
	
	/*SEND START CONDITION ON THE BUS*/
	SET_BIT(TWCR,TWCR_TWSTA);
	
	/*CLEAR THE INTERRPT FLAG TO START THE PREVIOUS OPERATION*/
	SET_BIT(TWCR,TWCR_TWINT);
	
	/*WAIT UNTIL THE INTERRUPT FLAG IS RISED AGAIN(THE START CONDETION IS ENDED)*/
	while(GET_BIT(TWCR,TWCR_TWINT)!=1);
	
	/*CHACK STATUS REGISTER TO*/
	if ((TWSR&0xf8) != REP_START_ACK)
	{
		Local_ErrorState=RepeatedStartError;
	}
	else
	{
		/*CLEAR START CONDITION BIT*/
		CLR_BIT(TWCR,TWCR_TWSTA);
		Local_ErrorState=NoError;
	}
	return Local_ErrorState;
}
TWI_ErrorStatus TWI_SendSlaveAdderssWithWrite(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorStatus Local_ErrorState;
	
	/*SET READ WRITE BIT LOW TO WRITE*/
	TWDR=Copy_u8SlaveAddress<<1;
	CLR_BIT(TWDR,0);
	
	/*CLEAR THE INTERRPT FLAG TO START THE PREVIOUS OPERATION*/
	SET_BIT(TWCR,TWCR_TWINT);
	
	/*WAIT UNTIL THE INTERRUPT FLAG IS RISED AGAIN(THE START CONDETION IS ENDED)*/
	while(GET_BIT(TWCR,TWCR_TWINT)!=1);
	
	/*CHACK STATUS REGISTER TO*/
	if ((TWSR&0xf8) != SLAVE_ADDRESS_WR_ACK)
	{
		Local_ErrorState=AddressReadWriteError;
	}
	else
	{
		Local_ErrorState=NoError;
	}
	return Local_ErrorState;
}

TWI_ErrorStatus TWI_SendSlaveAdderssWithRead(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorStatus Local_ErrorState;
	
	/*SET ADDRESS AND READ WRITE(LS) BIT HIGH TO READ*/
	TWDR=Copy_u8SlaveAddress<<1;
	SET_BIT(TWDR,0);
	
	/*CLEAR THE INTERRPT FLAG TO START THE PREVIOUS OPERATION*/
	SET_BIT(TWCR,TWCR_TWINT);
	
	/*WAIT UNTIL THE INTERRUPT FLAG IS RISED AGAIN(THE START CONDETION IS ENDED)*/
	while(GET_BIT(TWCR,TWCR_TWINT)!=1);
	
	/*CHACK STATUS REGISTER TO*/
	if ((TWSR&0xf8) != SLAVE_ADDRESS_RD_ACK)
	{
		Local_ErrorState=AddressReadWriteError;
	}
	else
	{
		Local_ErrorState=NoError;
	}
	return Local_ErrorState;
}

TWI_ErrorStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte)
{
	TWI_ErrorStatus Local_ErrorState;
	
	/*WRITE DATA TO DATA REGISTER*/
	TWDR = Copy_u8DataByte;
	
	/*CLEAR THE INTERRPT FLAG TO START THE PREVIOUS OPERATION*/
	SET_BIT(TWCR,TWCR_TWINT);
	
	/*WAIT UNTIL THE INTERRUPT FLAG IS RISED AGAIN(THE START CONDETION IS ENDED)*/
	while(GET_BIT(TWCR,TWCR_TWINT)!=1);
	
	/*CHACK STATUS REGISTER TO*/
	if ((TWSR&0xf8) != MASTAR_WRITE_ACK)
	{
		Local_ErrorState=MasterWriteError;
	}
	else
	{
		Local_ErrorState=NoError;
	}
	return Local_ErrorState;
}
TWI_ErrorStatus TWI_MasterReadDataByte(u8* Copy_u8DataByte)
{
	TWI_ErrorStatus Local_ErrorState;
	
	/*CLEAR FLAG BIT AT FRIST TO START RECEIVING FROM THE SLAVE*/
	SET_BIT(TWCR,TWCR_TWINT);
	
	/*WAIT UNTIL RECEIVING IS DONE AND FLAG IS RISED AGAIN(THE START CONDETION IS ENDED)*/
	while(GET_BIT(TWCR,TWCR_TWINT)!=1);
	
	/*CHACK STATUS REGISTER TO*/
	if ((TWSR&0xf8) != MASTAR_READ_ACK)
	{
		Local_ErrorState=MasterReadError;
	}
	else
	{
		/*SAVE RECEIVED BYTE TO PASSED REFERANCE*/
		*Copy_u8DataByte=TWDR;
		Local_ErrorState=NoError;
	}
	return Local_ErrorState;
}
void TWI_voidSendStopCondition(void)
{
	/*GENERATE SOTP CONDITION ON THE BUS BY SETTING BIT TWSTO IN REGISTER TWCR*/
	SET_BIT(TWCR,TWCR_TWSTO);
	
	/*CLEAR FLAG*/
	SET_BIT(TWCR,TWCR_TWINT);
}