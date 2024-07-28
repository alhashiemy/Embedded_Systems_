/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAl
 * SWC    : TWI
 * Version: 1.0
 * Created: NOV/5/2023
 */

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

typedef enum 
{
	NoError,
	StartConditionError,
	RepeatedStartError,
	AddressReadWriteError,
	MasterWriteError,
	MasterReadError,
	
	}TWI_ErrorStatus;


/*PASS 0 IN THE MasterAddress ARGUMENT IF THE MASTER WILL NOT BE ADDRESSED*/
void TWI_voidMasterInit(u8 Copy_u8MasterAddress);
void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress);	

TWI_ErrorStatus TWI_SendStartCondition(void);
TWI_ErrorStatus TWI_SendRepeatedStart(void);
TWI_ErrorStatus TWI_SendSlaveAdderssWithWrite(u8 Copy_u8SlaveAddress);
TWI_ErrorStatus TWI_SendSlaveAdderssWithRead(u8 Copy_u8SlaveAddress);
TWI_ErrorStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte);
TWI_ErrorStatus TWI_MasterReadDataByte(u8* Copy_u8DataByte);
void TWI_voidSendStopCondition(void);

#endif