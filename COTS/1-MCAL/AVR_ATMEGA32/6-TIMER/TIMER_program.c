/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : MCAL
 * SWC	  : TIMER
 * Version: 1.0
 * Created: JULY/2/2024
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER_config.h"
#include "TIMER_private.h"

static void (*TIMER_voidPTimerCallBackFunc[3]) (void)={NULL};
static void (*TIMER_voidPCompareCallBackFunc[4]) (void)={NULL};
static void (*TIMER_voidPCaptureCallBackFunc) (u16 Copy_u16CaptureReading)=NULL;


void TIMER0_voidInit(void)
{
	/*SET TIMER0 WAVEFORM GENERATION MODE*/
	TCCR0 &= TIMER0_WGMODE_MASK;
	TCCR0 |= (TIMER0_MODE &(~TIMER0_WGMODE_MASK));
}

void TIMER2_voidInit(void)
{
	/*SET TIMER2 WAVEFORM GENERATION MODE*/
	TCCR2 &= TIMER2_WGMODE_MASK;
	TCCR2 |= (TIMER2_MODE &(~TIMER2_WGMODE_MASK));
}

void TIMER1_voidInit(void)
{
	/*SET TIMER1 WAVEFORM GENERATION MODE*/
	TCCR1 &= TIMER1_WGMODE_MASK;
	TCCR1 |= (TIMER1_MODE &(~TIMER1_WGMODE_MASK));
}

void TIMER1_voidSetCaptureTrigger(u8 Copy_u8Trigger)
{
	/*SET CAPTURE INTERRUPT & SET VALUE TO CAPUTRE REGESTER IN TIMER1*/
	TCCR1B &= CAPTUR_TRIGGER_MASK;
	TCCR1B |= (Copy_u8Trigger<<6)&(~CAPTUR_TRIGGER_MASK);

}

void TIMER1_voidSetCaptureValue(u16 Copy_u16Value)
{
	/*SET VALUE TO CAPUTRE REGESTER IN TIMER1*/
	ICR1=Copy_u16Value;
}

u8 TIMER_u8SetTimerMode(u8 Copy_u8TimerID, u8 Copy_u8WGMode)
{
	u8 Local_u8ErrorState = CLEAR;
	if(Copy_u8TimerID == TIMER1_TIMER)
	{
		TCCR1 &= TIMER1_WGMODE_MASK; 
		TCCR1A|= (GET_BIT(Copy_u8WGMode,0)<<TCCR1A_WGM10);
		TCCR1A|= (GET_BIT(Copy_u8WGMode,1)<<TCCR1A_WGM11);
		TCCR1B|= (GET_BIT(Copy_u8WGMode,2)<<TCCR1B_WGM12);
		TCCR1B|= (GET_BIT(Copy_u8WGMode,3)<<TCCR1B_WGM13);
		
	}
	else
	{
		switch(Copy_u8TimerID)
		{
			case TIMER0_TIMER: TCCR0 &= TIMER0_WGMODE_MASK; TCCR0 |= (Copy_u8WGMode<<TCCR0_WGM00)&(~TIMER0_WGMODE_MASK); break;
			case TIMER2_TIMER: TCCR2 &= TIMER2_WGMODE_MASK; TCCR2 |= (Copy_u8WGMode<<TCCR2_WGM20)&(~TIMER2_WGMODE_MASK); break;
			default: Local_u8ErrorState = ERROR;
		}
	}
	
	
	return Local_u8ErrorState;
}


u8 TIMER_u8SetCompMatchValue(u8 Copy_u8TimerID, u8 Copy_u8OutputMode, u16 Copy_u16CompValue)
{
	u8 Local_u8ErrorState = CLEAR;
	switch(Copy_u8TimerID)
	{
		case TIMER0_COMPARE	: TCCR0 &= TIMER0_COMODE_MASK; TCCR0 |= (Copy_u8OutputMode<<TCCR0_COM00)  &(~TIMER0_COMODE_MASK); OCR0 =(u8)Copy_u16CompValue; break;
		case TIMER2_COMPARE	: TCCR2 &= TIMER2_COMODE_MASK; TCCR2 |= (Copy_u8OutputMode<<TCCR2_COM20)  &(~TIMER2_COMODE_MASK); OCR2 =(u8)Copy_u16CompValue; break;
		case TIMER1A_COMPARE: TCCR1A&= TIMERA_COMODE_MASK; TCCR1A|= (Copy_u8OutputMode<<TCCR1A_COM1A0)&(~TIMERA_COMODE_MASK); OCR1A=	Copy_u16CompValue; break;
		case TIMER1B_COMPARE: TCCR1A&= TIMERB_COMODE_MASK; TCCR1A|= (Copy_u8OutputMode<<TCCR1A_COM1B0)&(~TIMERB_COMODE_MASK); OCR1B=	Copy_u16CompValue; break;
		default: Local_u8ErrorState = ERROR;
	}
	
	return Local_u8ErrorState;
}


u8 TIMER_u8Start(u8 Copy_u8TimerID, u8 Copy_u8ClockSource, u16 Copy_u8InitialValue)
{
	u8 Local_u8ErrorState = CLEAR;
	switch(Copy_u8TimerID)
	{
		case TIMER0_TIMER: TCNT0 = (u8)Copy_u8InitialValue; TCCR0 &= TIMER_CLOCK_MASK; TCCR0 |= (Copy_u8ClockSource &(~TIMER_CLOCK_MASK)); break;
		case TIMER2_TIMER: TCNT2 = (u8)Copy_u8InitialValue; TCCR2 &= TIMER_CLOCK_MASK; TCCR2 |= (Copy_u8ClockSource &(~TIMER_CLOCK_MASK)); break;
		case TIMER1_TIMER: TCNT1 =(u16)Copy_u8InitialValue; TCCR1B&= TIMER_CLOCK_MASK; TCCR1B|= (Copy_u8ClockSource &(~TIMER_CLOCK_MASK)); break;
		default: Local_u8ErrorState = ERROR;
	}
	
	return Local_u8ErrorState;
	
}


u8 TIMER_u8SetTimerCallBack(u8 Copy_u8TimerID, void (*Copy_voidPCallBackFunc)(void))
{
	u8 Local_u8ErrorState = CLEAR;
	
	if (Copy_voidPCallBackFunc!=NULL)
	{
		switch(Copy_u8TimerID)
		{
			case TIMER0_TIMER: TIMER_voidPTimerCallBackFunc[TIMER0_TIMER]=Copy_voidPCallBackFunc; SET_BIT(TIMSK,TIMSK_TOIE0); break;
			case TIMER2_TIMER: TIMER_voidPTimerCallBackFunc[TIMER2_TIMER]=Copy_voidPCallBackFunc; SET_BIT(TIMSK,TIMSK_TOIE2); break;
			case TIMER1_TIMER: TIMER_voidPTimerCallBackFunc[TIMER1_TIMER]=Copy_voidPCallBackFunc; SET_BIT(TIMSK,TIMSK_TOIE1); break;
			default: Local_u8ErrorState = ERROR;
		}
	} 
	else
		Local_u8ErrorState = NULL_POINTER;
	
	return Local_u8ErrorState;
}

u8 TIMER_u8SetCompareCallBack(u8 Copy_u8TimerID, void (*Copy_voidPCallBackFunc)(void))
{
	u8 Local_u8ErorrState = CLEAR;
	if (Copy_voidPCallBackFunc!=NULL)
	{
		switch(Copy_u8TimerID)
		{
			case TIMER0_COMPARE: TIMER_voidPCompareCallBackFunc[TIMER0_COMPARE] =Copy_voidPCallBackFunc; SET_BIT(TIMSK,TIMSK_OCIE0); break;
			case TIMER2_COMPARE: TIMER_voidPCompareCallBackFunc[TIMER2_COMPARE] =Copy_voidPCallBackFunc; SET_BIT(TIMSK,TIMSK_OCIE2); break;
			case TIMER1A_COMPARE:TIMER_voidPCompareCallBackFunc[TIMER1A_COMPARE]=Copy_voidPCallBackFunc; SET_BIT(TIMSK,TIMSK_OCIE1A);break;
			case TIMER1B_COMPARE:TIMER_voidPCompareCallBackFunc[TIMER1B_COMPARE]=Copy_voidPCallBackFunc; SET_BIT(TIMSK,TIMSK_OCIE1B);break;
			default: Local_u8ErorrState = ERROR;
		}
	}
	else
		Local_u8ErorrState = NULL_POINTER;
	
	return Local_u8ErorrState;
}

u8 TIMER_u8SetCaptureCallBack(void (*Copy_voidPCallBackFunc)(u16 Copy_u16CapturReading))
{
	u8 Local_u8ErrorState = CLEAR;
	
	if (Copy_voidPCallBackFunc!=NULL)
	{
		TIMER_voidPCaptureCallBackFunc=Copy_voidPCallBackFunc;
		SET_BIT(TIMSK,TIMSK_TICIE1);
	} 
	else
		Local_u8ErrorState = NULL_POINTER;
	
	return Local_u8ErrorState;
}




void __vector_4(void) __attribute__((signal));
void __vector_4(void)
{
	if(TIMER_voidPCompareCallBackFunc[TIMER2_COMPARE]!=NULL)
	{
		TIMER_voidPCompareCallBackFunc[TIMER2_COMPARE]();
	}
}

void __vector_5(void) __attribute__((signal));
void __vector_5(void)
{
	if(TIMER_voidPTimerCallBackFunc[TIMER2_TIMER]!=NULL)
	{
		TIMER_voidPTimerCallBackFunc[TIMER2_TIMER]();
	}
}

void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	if(TIMER_voidPCaptureCallBackFunc!=NULL)
	{
		TIMER_voidPCaptureCallBackFunc(ICR1);
	}
}

void __vector_7(void) __attribute__((signal));
void __vector_7(void)
{
	if(TIMER_voidPCompareCallBackFunc[TIMER1A_COMPARE]!=NULL)
	{
		TIMER_voidPCompareCallBackFunc[TIMER1A_COMPARE]();
	}
}

void __vector_8(void) __attribute__((signal));
void __vector_8(void)
{
	if(TIMER_voidPCompareCallBackFunc[TIMER1B_COMPARE]!=NULL)
	{
		TIMER_voidPCompareCallBackFunc[TIMER1B_COMPARE]();
	}
}

void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
	if(TIMER_voidPTimerCallBackFunc[TIMER1_TIMER]!=NULL)
	{
		TIMER_voidPTimerCallBackFunc[TIMER1_TIMER]();
	}
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if(TIMER_voidPCompareCallBackFunc[TIMER0_COMPARE]!=NULL)
	{
		TIMER_voidPCompareCallBackFunc[TIMER0_COMPARE]();
	}
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	if(TIMER_voidPTimerCallBackFunc[TIMER0_TIMER]!=NULL)
	{
		TIMER_voidPTimerCallBackFunc[TIMER0_TIMER]();
	}
}