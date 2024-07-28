/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : HAL
 * SWC    : STPR
 * Version: 1.0
 * Created: JUN/14/2024
 */

#include <util/delay.h>
#include "STD_TYPES.h"
#include "GPIO_interface.h"

#include "STPR_config.h"
#include "STPR_private.h"

void STPR_voidOneStepClockWise(void)
{
	if(Step_Index==0)
		Step_Index=4;
	
	Step_Index--;
	GPIO_u8SetPinValue(STPR_Pin[Step_Index][PORT],STPR_Pin[Step_Index][PIN],GPIO_u8PIN_HIGH);
	_delay_ms(STPR_STEP_TIME_ms);
	GPIO_u8SetPinValue(STPR_Pin[Step_Index][PORT],STPR_Pin[Step_Index][PIN],GPIO_u8PIN_LOW);
	
}

void STPR_voidOneStepCClockWise(void)
{
	if(Step_Index==4)
		Step_Index=0;
	
	GPIO_u8SetPinValue(STPR_Pin[Step_Index][PORT],STPR_Pin[Step_Index][PIN],GPIO_u8PIN_HIGH);
	_delay_ms(STPR_STEP_TIME_ms);
	GPIO_u8SetPinValue(STPR_Pin[Step_Index][PORT],STPR_Pin[Step_Index][PIN],GPIO_u8PIN_LOW);
	Step_Index++;
}
