/*
 * Author : Bassam_Mahmoud_
 * Layer  : HAL
 * SWC    : SENSOR
 * Version: 1.0
 * Created: OCT/22/2023
 */

#include "STD_TYPES.h"
#include "ADC_interface.h"
#include "SENSOR_config.h"
#include "SENSOR_private.h"
#include "SENSOR_interface.h"


u8 SENSOR_u8GetReading(u8 Copy_u8Channel, u16* Copy_u8PReading)
{
	if (Copy_u8PReading!=NULL)
	{
		ADC_voidInit();
		ADC_u8StartConvertion(Copy_u8Channel,Single_Convertion,ADC_INTERRUPT_DISABLED);
		ADC_u8ReadADC(Copy_u8PReading);
		return CLEAR;
	} 
	else
	return NULL_POINTER;
}

u8 SENSOR_u8GetMapping(u8 Copy_u8Channel, Map_t* Copy_ADCMapData, u32* Copy_Pu32Output)
{
	if (Copy_Pu32Output!=NULL)
	{
		ADC_voidInit();
		ADC_u8StartConvertion(Copy_u8Channel,Single_Convertion,ADC_INTERRUPT_DISABLED);
		ADC_u8Map(Copy_ADCMapData, Copy_Pu32Output);
		return CLEAR;
	} 
	else
	return NULL_POINTER;
}
