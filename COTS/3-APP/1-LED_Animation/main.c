/*
 * main.c
 *
 *  Created on: Jul 6, 2024
 *      Author: DX
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SRVC_interface.h"


int main(void)
{
	u8 Local_u8Iterator;
	SRVC_voidInit();
	while(1)
	{
		for(Local_u8Iterator=0; Local_u8Iterator<4; Local_u8Iterator++)
		SRVC_voidShiftLeftRight(200);

		for(Local_u8Iterator=0; Local_u8Iterator<4; Local_u8Iterator++)
		SRVC_voidInOut(200);

		for(Local_u8Iterator=0; Local_u8Iterator<8; Local_u8Iterator++)
		SRVC_voidFlashing(500);
	}

}

void shift_left_right(void){

}


