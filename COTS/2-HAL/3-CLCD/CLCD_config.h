/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : HAL
 * SWC    : CLCD
 * Version: 1.0
 * Created: JUN/10/2024
 */

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/*SET BUS_MODE: 			
 *OPTIONS,							CLCD_EIGHT_BIT 	FOR 8 BIT MODE
 *									CLCD_FOUR_BIT  	FOR 4 BIT MODE(SET FIRST 4 BITS TO NULL)
 */
#define BUS_MODE					CLCD_FOUR_BIT


/*SET CLCD DIMENSIONS:
 */
#define CLCD_LINES_NUM				4
#define CLCD_COLUMS_NUM				20


/*SET CLCD PINS:
 *OPTIONS,							PORT,PIN_NUMBER	
 *(NOTE: SET FIRST 4 PINS TO NULL WHILE USING 4 BIT MODE)
 */
#define CLCD_DATA_PIN0				NULL
#define CLCD_DATA_PIN1				NULL
#define CLCD_DATA_PIN2				NULL
#define CLCD_DATA_PIN3				NULL
#define CLCD_DATA_PIN4				GPIO_u8PORTA,4
#define CLCD_DATA_PIN5				GPIO_u8PORTA,5
#define CLCD_DATA_PIN6				GPIO_u8PORTA,6
#define CLCD_DATA_PIN7				GPIO_u8PORTA,7


#define CLCD_RS_PIN					GPIO_u8PORTB,4
#define CLCD_RW_PIN					GPIO_u8PORTB,6
#define CLCD_E_PIN					GPIO_u8PORTB,7


#endif