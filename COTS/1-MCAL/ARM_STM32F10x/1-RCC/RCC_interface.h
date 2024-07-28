/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAl
 * SWC    : RCC
 * Version: 1.0
 * Created: JULY/6/2024
 */
 

#ifndef	RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


typedef struct {
	
	u8 HSE			 ;
	u8 HSE_State	 ;
	u8 PLL			 ;
	u8 PLL_State	 ;
	u8 PLL_MultFactor;
	u8 Output_Clock	 ;
	
}RCC_config_t;

typedef enum {
	
	RCC_HSE_CRYSTAL,
	RCC_HSE_RC

}RCC_HSE_r;

typedef enum {
	
	RCC_HSE_OFF,
	RCC_HSE_ON

}RCC_HSE_State_t;

typedef enum {
	
	PLL_HSI_DIV_BY_2,
	PLL_HSE			,
	PLL_HSE_DIV_BY_2 = 3
	
}RCC_PLL_t;

typedef enum {
	
	RCC_PLL_OFF,
	RCC_PLL_ON
	
}RCC_PLL_state_t;

typedef enum {
	
	PLL_INPUT_CLOCK_x_2,
	PLL_INPUT_CLOCK_x_3,
	PLL_INPUT_CLOCK_x_4,
	PLL_INPUT_CLOCK_x_5,
	PLL_INPUT_CLOCK_x_6,
	PLL_INPUT_CLOCK_x_7,
	PLL_INPUT_CLOCK_x_8,
	PLL_INPUT_CLOCK_x_9,
	PLL_INPUT_CLOCK_x_10,
	PLL_INPUT_CLOCK_x_11,
	PLL_INPUT_CLOCK_x_12,
	PLL_INPUT_CLOCK_x_13,
	PLL_INPUT_CLOCK_x_14,
	PLL_INPUT_CLOCK_x_15,
	PLL_INPUT_CLOCK_x_16
	
}RCC_PLL_MultFactor_t;

typedef enum {
	
	RCC_HSI,
	RCC_HSE,
	RCC_PLL
	
}RCC_OutputClock_t;

/* OPTIONS, FOR Copy_u8BusID*/
typedef enum {

	RCC_AHB ,
	RCC_APB1,
	RCC_APB2

}Copy_u8BusID_t;

/* OPTIONS, FOR Copy_u8PerID*/
typedef enum {

	RCC_AFIO		,
	RES				,
	RCC_GPIO_PORTA	,
	RCC_GPIO_PORTB	,
	RCC_GPIO_PORTC

}Copy_u8PerID_t;

void RCC_voidInit();

u8 RCC_u8Init(RCC_config_t *RCC_Config);

u8 RCC_u8EnableClock(u8 Copy_u8BusID, u8 Copy_u8PerID);

u8 RCC_u8DisableClock(u8 Copy_u8BusID, u8 Copy_u8PerID);

#endif
