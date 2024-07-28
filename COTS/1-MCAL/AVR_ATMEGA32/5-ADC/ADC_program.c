/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : MCAl
 * SWC    : ADC
 * Version: 1.0
 * Created: JUN/18/2024
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "ADC_config.h"
#include "ADC_private.h"

static void (*ADC_voidNotification)(u16 Copy_u16Reading)=NULL;
u8 ADC_u8BusyState = IDL;

void ADC_voidInit(void)
{
	/*SET REFERANCE VOLTAGE (USING MASKING)*/
	ADMUX &= REF_BITS_MASK;
	ADMUX |= (ADC_REF_SELECTION<<REFS0)&(~REF_BITS_MASK);
	
	/*SET LEFT ADJUST RESULT*/
	ADMUX &= LEFT_ADJUST_BIT_MASK;
	ADMUX |= (ADC_RESOLUTION<<ADLAR)&(~LEFT_ADJUST_BIT_MASK);
	
	/*SET PRESCALER (USING MASKING)*/
	ADCSRA &= PRESCALER_MASK;
	ADCSRA |= ((ADC_PRESCALER<<ADPS0)&(~PRESCALER_MASK));
	
	/*ENABLE ACD*/
	SET_BIT(ADCSRA,ADEN);
}

u8 ADC_u8SetADC(u8 Copy_u8RefSelection, u8 Copy_u8Resolution, u8 Copy_u8Prescaler)
{
	u8 Local_u8ErrorState = CLEAR;
	
	/*SET REFERANCE VOLTAGE */
	switch(Copy_u8RefSelection)
	{
		case AREF	: CLR_BIT(ADMUX,REFS1); CLR_BIT(ADMUX,REFS0); break;
		case AVCC	: CLR_BIT(ADMUX,REFS1); SET_BIT(ADMUX,REFS0); break;
		case INTERN	: SET_BIT(ADMUX,REFS1); SET_BIT(ADMUX,REFS0); break;
		default: Local_u8ErrorState = ERROR;
	}
	
	/*SET LEFT ADJUST RESULT*/
	switch(Copy_u8Resolution)
	{
		case TEN_BIT_RESOLUTION   : CLR_BIT(ADMUX,ADLAR); break;
		case EIGHT_BIT_RESOLUTION : SET_BIT(ADMUX,ADLAR); break;
		default: Local_u8ErrorState = ERROR;
	}
	
	/*SET PRESCALER (USING MASKING)*/				 
	if(Copy_u8Prescaler <= PRESCALER128)
	{
		ADCSRA &= PRESCALER_MASK;
		ADCSRA |= (Copy_u8Prescaler<<ADPS0)&(~PRESCALER_MASK);
	}
	else
		Local_u8ErrorState = ERROR;
	
	/*ENABLE ACD*/
	SET_BIT(ADCSRA,ADEN);
	
	return Local_u8ErrorState;
}

u8 ADC_u8StartConvertionSynch(u8 Copy_u8Channal)
{
	u8  Local_u8ErrorState = CLEAR;
	u16 Local_u8Iterator = 0;
	
	/*CHACK THAT NO OTHER CONVETION IS RUNNING AT THIS MOMENT*/
	if(ADC_u8BusyState == IDL)
	{
		/*SET ADC_u8BusyState TO BUSY*/
		ADC_u8BusyState = BUSY;
		
		/*SET CHANNEL*/
		ADMUX &= MUX_MASK;
		ADMUX |= (Copy_u8Channal<<MUX0)&(~MUX_MASK);
		
		/*CLEAR INTERRUPT BIT*/			 	 
		CLR_BIT(ADCSRA,ADIE);  
		
		/*CLEAR AUTO TRIGGER ENABLE BIT*/
		CLR_BIT(ADCSRA,ADATE); 
		
		/*START CONVERTION*/
		SET_BIT(ADCSRA,ADSC);
		
		/*BUSY WAITING UNTILL CONVERTION IS COMPLETE*/
		while((GET_BIT(ADCSRA,ADIF)!=1) && (Local_u8Iterator < MAX_BUSY_WAITING))
		{
			Local_u8Iterator++;
		}
		
		/*CHACK IF CONVERTIONS IS COMPLETE*/
		if (Local_u8Iterator != MAX_BUSY_WAITING)
		{
			/*CLEAR FLAG*/
			SET_BIT(ADCSRA,ADIF);
			
			switch(GET_BIT(ADMUX,ADLAR))
			{
				case TEN_BIT_RESOLUTION	  : ADC_voidNotification(ADC) ; break;
				case EIGHT_BIT_RESOLUTION :	ADC_voidNotification(ADCH); break;
			}
			
			/*RETURN ADC_u8BusyState TO IDL STATE*/
			ADC_u8BusyState = IDL;
			
		}
		else
			Local_u8ErrorState = TIME_OUT;
	}
	else
		Local_u8ErrorState = BUSY;
	
	return  Local_u8ErrorState;
}

u8 ADC_u8StartConvertionASynch(u8 Copy_u8Channal)
{
	u8  Local_u8ErrorState = CLEAR;
	
	/*CHACK THAT NO OTHER CONVETION IS RUNNING AT THIS MOMENT*/
	if (ADC_u8BusyState == IDL)
	{
		/*SET ADC_u8BusyState TO BUSY*/
		ADC_u8BusyState = BUSY;
		
		/*SET CHANNEL*/
		ADMUX &= MUX_MASK;
		ADMUX |= (Copy_u8Channal<<MUX0)&(~MUX_MASK);
		
		/*CLEAR AUTO TRIGGER ENABLE BIT*/
		CLR_BIT(ADCSRA,ADATE);
		
		/*SET INTERRUPT BIT*/
		SET_BIT(ADCSRA,ADIE);
		
		/*START CONVERTION*/
		SET_BIT(ADCSRA,ADSC);
		
	}
	else
		Local_u8ErrorState = BUSY;
	
	return  Local_u8ErrorState;
}

u8 ADC_u8StartAutoConvertion(u8 Copy_u8Channal, u8 Copy_u8ConvrtionMode)
{
	u8 Local_u8ErrorState = CLEAR; 
	
	/*CHACK THAT NO OTHER CONVETION IS RUNNING AT THIS MOMENT*/
	if (ADC_u8BusyState == IDL)
	{
		/*SET ADC_u8BusyState TO BUSY*/
		ADC_u8BusyState = BUSY;
		
		/*SET CHANNEL*/
		ADMUX &= MUX_MASK;
		ADMUX |= (Copy_u8Channal<<MUX0)&(~MUX_MASK);
		
		/*SET AUTO TRIGGER BIT*/
		SET_BIT(ADCSRA,ADATE); 
		
		/*SET AUTO TREIGGER SOURCE*/
		SFIOR &= TRIGGER_MASK;
		SFIOR |= (Copy_u8ConvrtionMode<<ADTS0)&(~TRIGGER_MASK);
		
		/*SET INTERRUPT BIT*/		 	 
		SET_BIT(ADCSRA,ADIE);
		
		/*START CONVERTION*/
		SET_BIT(ADCSRA,ADSC);
	}
	else
	{
		Local_u8ErrorState = BUSY;
	}
	
	return Local_u8ErrorState;
}

u8 ADC_u8SetCallBack(void (*Copy_PNotFunc)(u16 Copy_u16Reading))
{
	u8 Local_u8ErrorState = CLEAR;
	
	if (Copy_PNotFunc!=NULL)
	{
		if (ADC_u8BusyState == IDL)
		{
			ADC_voidNotification=Copy_PNotFunc;
		}
		else
			Local_u8ErrorState = BUSY;
	} 
	else
		Local_u8ErrorState = NULL_POINTER;
	
	return Local_u8ErrorState;
}

void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{	
	/*RETURN ADC_u8BusyState TO IDL STATE*/
	ADC_u8BusyState = IDL;
	
	/*GO TO NOTIFICTION FUNCTION*/
	if(ADC_voidNotification!=NULL)
	{
		switch(GET_BIT(ADMUX,ADLAR))
		{
			case TEN_BIT_RESOLUTION	  : ADC_voidNotification(ADC) ; break;
			case EIGHT_BIT_RESOLUTION :	ADC_voidNotification(ADCH); break;
		}
	}

}

