/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : MCAl
 * SWC    : ADC
 * Version: 1.0
 * Created: JUN/18/2024
 */
 
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC_u8AREF							0
#define ADC_u8AVCC							1
#define ADC_u8INTERN						3

#define ADC_TIN_BIT_RESOLUTION				0
#define ADC_EIGHT_BIT_RESOLUTION			1

#define ADC_PRESCALER2						1
#define ADC_PRESCALER4						2
#define ADC_PRESCALER8						3
#define ADC_PRESCALER16						4
#define ADC_PRESCALER32						5
#define ADC_PRESCALER64						6
#define ADC_PRESCALER128					7

#define Free_Running						0
#define Analog_Comparator					1
#define External_Interrupt0					2
#define Timer_Counter0_CompareMatch			3
#define Timer_Counter0_Overflow				4
#define Timer_Counter_CompareMatchB			5
#define Timer_Counter1_Overflow				6
#define Timer_Counter1_Capture_Event		7


void ADC_voidInit(void);

void ADC_voidDesableADC(void);

u8 ADC_u8SetADC(u8 Copy_u8RefSelection, u8 Copy_u8Resolution, u8 Copy_u8Prescaler);

u8 ADC_u8StartConvertionSynch(u8 Copy_u8Channal);

u8 ADC_u8StartConvertionASynch(u8 Copy_u8Channle);

u8 ADC_u8StartAutoConvertion(u8 Copy_u8Channal, u8 Copy_u8ConvrtionMode);

u8 ADC_u8SetCallBack(void (*Copy_PNotFunc)(u16 Copy_u16Reading));

#endif