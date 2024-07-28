/*
 * Author : Bassam_Mahmoud_
 * Layer  : HAL
 * SWC    : SENSOR
 * Version: 1.0
 * Created: OCT/22/2023
 */

#ifndef SENSOR_INTERFACE_H_
#define SENSOR_INTERFACE_H_

u8 SENSOR_u8GetReading(u8 Copy_u8Channel, u16* Copy_u8PReading);

u8 SENSOR_u8GetMapping(u8 Copy_u8Channel, Map_t* Copy_ADCMapData, u32* Copy_Pu32Output);


#endif