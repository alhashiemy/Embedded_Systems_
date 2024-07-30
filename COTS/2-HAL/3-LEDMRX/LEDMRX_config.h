/*
 * Author : Bassam_Mahmoud_
 * Layer  : HAL
 * SWC	  : LEDMRX
 * Version: 1.1
 * Created: JULY/31/2024
 */

#ifndef LEDMRX_CONFIG_H_
#define LEDMRX_CONFIG_H_


#define	LEDMRX_ROWS_NUM			8
#define LEDMRX_COLS_NUM			8

/* PLEASE DEFINE LED MATRIX COLUMNS & ROWS PINS IN ORDER
 * Note: LED matrix starts from left upper corner
 */
#define LEDMRX_COLS_PINS		{{GPIO_PORTA, 0},\
								 {GPIO_PORTA, 1},\
								 {GPIO_PORTA, 2},\
								 {GPIO_PORTA, 3},\
								 {GPIO_PORTA, 4},\
								 {GPIO_PORTA, 5},\
								 {GPIO_PORTA, 6},\
								 {GPIO_PORTA, 7}}

#define LEDMRX_ROWS_PINS		{{GPIO_PORTA, 8},\
								 {GPIO_PORTA, 9},\
								 {GPIO_PORTA,10},\
								 {GPIO_PORTA,11},\
								 {GPIO_PORTA,12},\
								 {GPIO_PORTA,13},\
								 {GPIO_PORTA,14},\
								 {GPIO_PORTA,15}}

/* PLEASE ENTER DISPLAY SHIFTING SPEED (0 FOR MAX)*/
#define LEDMRX_SPEED			3

#endif
