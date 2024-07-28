/*
 * Author : BASSAM_MAHMOUD_
 * Layer  : LIB
 * Version: 1.0
 * Created: JUN/6/2023
 */
 
#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char u8;
typedef signed   char s8;

typedef unsigned short int u16;
typedef signed   short int s16;

typedef unsigned long int u32;
typedef signed   long int s32;

typedef float  f32;
typedef double f64;


typedef struct
{
	u8 DataPin[8][2];
	u8 EnablePin[8][2];
	u8 CommonType[8];
	
	}SSD_t;

typedef struct ADCStruct
{
	u8 ChainSize;
	u8* Channel_ID;
	u16* ReturnValue;
	void (*ChainNotFunc)(void);

	}CHAIN_t;
	
typedef struct ADCMap
{
	u16 MinReading;
	u16 MaxReading;
	u32 MinOutput;
	u32 MaxOutput;
	
	}Map_t;

#define  NULL					(void*)0

/*FUNCTIONS ERROR STATES*/
typedef enum {

	CLR 	,
	ERR 	,
	TimeOut	,
	IDL		,
	BUSY

}ErrorState_t;

#define KPD_NO_PRESSED_KEY		0xFE

#define NULL_POINTER			0xFF

#endif
