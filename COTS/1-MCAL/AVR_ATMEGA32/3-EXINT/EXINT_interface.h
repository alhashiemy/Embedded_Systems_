/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : MCAL
 * SWC    : EEXINT
 * Version: 1.0
 * Created: JUN/15/2024
 */

#ifndef EXINT_INTERFACE_H_
#define EXINT_INTERFACE_H_


/*PRE-BUILD CONFIG FUNCTIONS*/
void EXINT_voidInt0Init(void);
void EXINT_voidInt1Init(void);
void EXINT_voidInt2Init(void);

/*INT CONTROL ARGUMENTS FOR EXINT_u8SetExInt FUNCTION */
/*OPTIONS FOR Copy_u8IntNumber*/
#define	XINT_u8LOW_LEVEL				0
#define	XINT_u8LOGICAL_CHANGE			1
#define	XINT_u8FALLING_EDGE				2
#define	XINT_u8RISING_EDGE				3

/*OPTIONS FOR Copy_u8SenseState*/
#define XINT_u8DISABLED					0
#define XINT_u8ENABLED					1

/*OPTIONS FOR Copy_u8SenseState*/
#define XINT_u8INT0						1
#define XINT_u8INT1						2
#define XINT_u8INT2						3

/* Discription: A function to set INT enable state using postbuild configuration
 *
 * Inputs:		Copy_u8IntNumber,	Options are:	XINT_u8INT0
 *													XINT_u8INT1
 *													XINT_u8INT2
 *
 *				Copy_u8EnableState, Options are:	XINT_u8DISABLED	
 *				                                    XINT_u8ENABLED	
 *				
 *				
 * Outputs: 	Error state with type u8
 */
u8 EXINT_u8SetEnableState(u8 Copy_u8IntNumber, u8 Copy_u8EnableState);

/* Discription: A function to set INT sense state using postbuild configuration
 *
 * Inputs:		Copy_u8IntNumber,	Options are:	XINT_u8INT0
 *													XINT_u8INT1
 *													XINT_u8INT2
 *
 *				Copy_u8SenseState,	Options are:	XINT_u8LOW_LEVEL	
 *				                                    XINT_u8LOGICAL_CHANGE
 *													XINT_u8FALLING_EDGE	
 *													XINT_u8RISING_EDGE	
 *
 * Outputs: 	Error state with type u8
 */
u8 EXINT_u8SetSenseState(u8 Copy_u8IntNumber, u8 Copy_u8SenseState);


/* Discription: A function to set INT notification function
 * Inputs:		Copy_u8PInt0Func,	OPtions are:	Pointer to INT0	Function
 *													Pointer to INT1	Function
 *													Pointer to INT2	Function
 *
 *				Copy_u8EXINTerrupt,	Options are:	XINT_u8INT0
 *													XINT_u8INT1
 *													XINT_u8INT2
 * Outputs: Error state with type u8
 */
u8 EXINT_u8SetCallBack(u8 Copy_u8ExInterrupt, void (*Copy_PNotFunc)(void));

#endif