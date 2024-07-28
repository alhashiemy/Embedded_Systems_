/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : MCAL
 * SWC    : GIE
 * Version: 1.0
 * Created: JUN/14/2024
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_register.h"

void GIE_voidEnable()
{
	SET_BIT(SREG,SREG_I);
}

void GIE_voidDisable()
{
	CLR_BIT(SREG,SREG_I);
}
