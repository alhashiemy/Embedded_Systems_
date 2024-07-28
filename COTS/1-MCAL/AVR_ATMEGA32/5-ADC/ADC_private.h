/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : MCAl
 * SWC    : ADC
 * Version: 1.0
 * Created: JUN/18/2024
 */
 
#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define AREF								0
#define AVCC								1
#define INTERN								3

#define REF_BITS_MASK						0b00111111
#define LEFT_ADJUST_BIT_MASK				0b11011111
#define PRESCALER_MASK						0b11111000
#define MUX_MASK							0b11100000
#define TRIGGER_MASK						0b00011111

#define PRESCALER2							1
#define PRESCALER4							2
#define PRESCALER8							3
#define PRESCALER16							4
#define PRESCALER32							5
#define PRESCALER64							6
#define PRESCALER128						7

#define TEN_BIT_RESOLUTION					0
#define EIGHT_BIT_RESOLUTION				1


#define ADMUX								*((volatile u8* )0x27)	/*ADC MULTIPLIXER selection register*/
#define REFS1								7						/*REFERACE SELECTION Bit 1			*/
#define REFS0								6						/*REFERACE SELECTION Bit 2			*/
#define ADLAR								5						/*ADC Left Adjust Result			*/
#define MUX0								0						/*Analoge channel selection bit 0	*/

#define ADCSRA								*((volatile u8* )0x26)	/*ADC Control and Status Register	*/
#define ADEN								7						/*ADC Enable						*/
#define ADSC								6						/*ADC Start Conversion				*/
#define ADATE								5						/*ADC Auto Trigger Enable			*/
#define ADIF								4						/*ADC Interrupt Flag				*/
#define ADIE								3						/*ADC Interrupt Enable				*/
#define ADPS2								2						/*ADC PRESCALER Select Bit2			*/
#define ADPS1								1						/*ADC PRESCALER Select Bit1			*/
#define ADPS0								0						/*ADC PRESCALER Select Bit0			*/

#define ADCH								*((volatile u8* )0x25)	/*ADC Higher Data Register			*/
#define ADCL								*((volatile u8* )0x24)	/*ADC Lower Data Register			*/
#define ADC									*((volatile u16*)0x24)	/*ADC Data Register					*/
					
#define SFIOR								*((volatile u8* )0x50)	/*ADC Auto Trigger Source register	*/
#define ADTS2								7						/*Auto Trigger Source BIN2*/
#define ADTS1								6                       /*Auto Trigger Source BIN1*/
#define ADTS0								5                       /*Auto Trigger Source BIN0*/

#endif