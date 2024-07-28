/*
 * Author : Bassam_Mahmoud_
 * Layer  : SRVC
 * Version: 1.0
 * Created: JULY/18/2024
 */

#ifndef SRVC_INTERFACE_H_
#define SRVC_INTERFACE_H_

/* Please before use port driver:
 * -Set GPIO driver configurations.
 * -Set RCC  driver configurations (set RCC OUTPUT CLOCK 8MHz).
 * -Set STK  driver configurations (set STK_CLKSOURCE_MODE AHB_BY_EIGHT).
 * -Set SRVC driver configurations
 */


void SRVC_voidInit();
void SRVC_voidShiftLeftRight(u32 Copy_u32Delay);
void SRVC_voidInOut(u32 Copy_u32Delay);
void SRVC_voidFlashing(u32 Copy_u32Delay);

#endif
