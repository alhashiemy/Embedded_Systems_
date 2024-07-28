/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : LIB
 * Version: 1.0
 * Created: JUN/6/2023
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(var,bit_no) var|=(1<<bit_no)

#define CLR_BIT(var,bit_no) var&=~(1<<bit_no)

#define TGL_BIT(var,bit_no) var^=(1<<bit_no)

#define GET_BIT(var,bit_no) ((var>>bit_no)&1)

#endif