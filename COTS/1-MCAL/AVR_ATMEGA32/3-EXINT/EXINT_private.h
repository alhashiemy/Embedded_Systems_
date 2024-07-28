/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : MCAL
 * SWC    : EEXINT
 * Version: 1.0
 * Created: JUN/15/2024
 */
 
#ifndef EXINT_PRIVATE_H_
#define EXINT_PRIVATE_H_

/*GLOBAL POINTER TO ISR FUNCTION*/
static void (*NotFunc[3])(void) = {NULL};

#define LOW_LEVEL					0
#define LOGICAL_CHANGE				1
#define FALLING_EDGE				2
#define RISING_EDGE 				3
		
#define DISABLED					0
#define ENABLED						1
		
#define INT0						1
#define INT1						2
#define INT2						3

#define INT0_ENABLE_BIT_MASK		0b10111111
#define INT1_ENABLE_BIT_MASK		0b01111111
#define INT2_ENABLE_BIT_MASK		0b11011111

/*SPICIAL PRIFRAL ENABLE REGISTER*/
#define GICR						*((volatile u8*)0x5b)
#define GICR_INT1					7
#define GICR_INT0					6
#define GICR_INT2					5
		
/*FLAG REGISTER*/		
#define GIFR						*((volatile u8*)0x5a)
#define GIFR_INTF1					7
#define GIFR_INTF0					6
#define GIFR_INTF2					5

/*INT0&INT1 SENSE STATE REGISTER*/
#define MCUCR						*((volatile u8*)0x55)
#define MCUCR_ISC00					0
#define MCUCR_ISC01					1
#define MCUCR_ISC10					2
#define MCUCR_ISC11					3
		
/*INT2 SENSE STATE REGISTER*/
#define MCUCSR						*((volatile u8*)0x54)
#define MCUCSR_ISC2					6

#endif