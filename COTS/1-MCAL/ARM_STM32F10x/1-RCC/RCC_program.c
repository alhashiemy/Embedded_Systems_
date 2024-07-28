/*
 * Author : Bassam_Mahmoud_
 * Layer  : MCAl
 * SWC    : RCC
 * Version: 1.0
 * Created: JULY/6/2024
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_private.h"
#include "RCC_config.h"
#include "RCC_interface.h"


u8 RCC_u8Init(RCC_config_t *RCC_Config)
{
	u8 Local_u8ErrorState = CLR;
	if(RCC_Config == NULL) {
		
		Local_u8ErrorState = NULL_POINTER;
	}
	else if(RCC_Config->HSE > RCC_HSE_RC) {
		/* RETURN ERR */
		Local_u8ErrorState = ERR;
	}
	else if(RCC_Config->HSE_State > RCC_HSE_ON) {
		/* RETURN ERR */
		Local_u8ErrorState = ERR;
	}
	else if(RCC_Config->PLL > PLL_HSE_DIV_BY_2) {
		/* RETURN ERR */
		Local_u8ErrorState = ERR;
	}
	else if(RCC_Config->PLL_State > RCC_PLL_ON) {
		/* RETURN ERR */
		Local_u8ErrorState = ERR;
	}
	else if(RCC_Config->PLL_MultFactor > PLL_INPUT_CLOCK_x_16) {
		/* RETURN ERR */
		Local_u8ErrorState = ERR;
	}
	else if(RCC_Config->Output_Clock > RCC_PLL) {
		/* RETURN ERR */
		Local_u8ErrorState = ERR;
	}
	else {
		/* SET CLOCK BYPASS BASED ON EXTERNAL OSCILATOR */
		RCC->CR |= (RCC_Config->HSE << CR_HSEBYP);
		
		/* SET HSEON BIT */
		RCC->CR |= (RCC_Config->HSE_State << CR_HSEON);
		
		/* SET PLL CLOCK SOURCE */
		RCC->CFGR |= (RCC_Config->PLL << CFGR_PLLSRC);
		
		/* SET PLLON BIT */
		RCC->CR |= (RCC_Config->PLL_State << CR_PLLON);
		
		/* SET MULTIPLICATION FACTOR */
		RCC->CFGR |= (RCC_Config->PLL_MultFactor << CFGR_PLLMUL0);
		
		/* SET RCC OUTPUT CLOCK */
		RCC->CFGR |= (RCC_Config->Output_Clock<<CFGR_SW0);
	}
	
	return Local_u8ErrorState;
	
}

void RCC_voidInit(void)
{

#if RCC_CLOCK_SOURCE == HSI

	/* SET HSION BIT */
	SET_BIT(RCC->CR, CR_HSION);

	/* BUSY WAITING ON HSIRDY FLAG */
	while(GET_BIT(RCC->CR, CR_HSIRDY)==0);

#elif RCC_CLOCK_SOURCE == HSE
	#if RCC_XTAL_OSCI == CRYSTAL

	/* SET CLOCK BYPASS BASED ON EXTERNAL OSCILATOR */
	CLR_BIT(RCC->CR,CR_HSEBYP);

	#elif RCC_XTAL_OSCI == RC
	/* CLR BYPASS BIT */
	SET_BIT(RCC->CR,CR_HSEBYP);
	
	#else
	#error	("Wrong clock source choice")
	
	#endif
	/* SET HSEON BIT */
	SET_BIT(RCC->CR, CR_HSEON);
	
	/* BUSY WAITING ON HSERDY FLAG */
	while(GET_BIT(RCC->CR, CR_HSERDY)!=1);
#else
#error 	("Wrong clock source choice")

#endif

#if RCC_OUTPUT_CLOCK == HSI
	CLR_BIT(RCC->CFGR, CFGR_SW0);
	CLR_BIT(RCC->CFGR, CFGR_SW1);

#elif RCC_OUTPUT_CLOCK == HSE

	SET_BIT(RCC->CFGR, CFGR_SW0);
	CLR_BIT(RCC->CFGR, CFGR_SW1);

#elif RCC_OUTPUT_CLOCK == PLL

	#if RCC_PLL_SOURCE == PLL_HSI_DIV_BY_2

	CLR_BIT(RCC->CFGR, CFGR_PLLSRC);

	#elif RCC_PLL_SOURCE == PLL_HSE_DIV_BY_2

	SET_BIT(RCC->CFGR, CFGR_PLLSRC);
	SET_BIT(RCC->CRGR, CFGR_PLLXTPRE);

	#elif RCC_PLL_SOURCE == PLL_HSE

	SET_BIT(RCC->CFGR, CFGR_PLLSRC);
	CLR_BIT(RCC->CFGR, CFGR_PLLXTPRE);

	#else
	#error ("Wrong PLL source")

	#endif

	/* SET PLLON BIT */
	SET_BIT(RCC->CR, CR_PLLON);
	
	/* BUSY WAITING ON PLLRDY FLAG */
	while(GET_BIT(RCC->CR, CR_PLLRDY)==0);
	
	/* SET MULTIPLICATION FACTOR */
	RCC->CFGR &= PLLMUL_MASK;
	RCC->CFGR |= ((RCC_PLL_MUL << CFGR_PLLMUL0) &(~PLLMUL_MASK));
	
	/* SET OUTPUT CLOCK PLL */
	SET_BIT(RCC->CFGR, CFGR_SW0);
	CLR_BIT(RCC->CFGR, CFGR_SW1);
	

#else
#error ("Wrong clock source choice")

#endif

}

u8 RCC_u8EnableClock(u8 Copy_u8BusID, u8 Copy_u8PerID)
{
	u8 Local_u8ErrorState = CLR;
	if(Copy_u8PerID<32)
	{
		switch(Copy_u8BusID)
		{
			case RCC_AHB : SET_BIT(RCC->AHBENR,  Copy_u8PerID); break;
			case RCC_APB1: SET_BIT(RCC->APB1ENR, Copy_u8PerID); break;
			case RCC_APB2: SET_BIT(RCC->APB2ENR, Copy_u8PerID); break;
			default: Local_u8ErrorState = ERR;
		}
	}
	else
	{
		/* Return error */
		Local_u8ErrorState = ERR;
	}

	return Local_u8ErrorState;
}

u8 RCC_u8DisableClock(u8 Copy_u8BusID, u8 Copy_u8PerID)
{
	u8 Local_u8ErrorState = CLR;
	if(Copy_u8PerID<32)
	{
		switch(Copy_u8BusID)
		{
			case RCC_AHB : CLR_BIT(RCC->AHBENR,  Copy_u8PerID); break;
			case RCC_APB1: CLR_BIT(RCC->APB1ENR, Copy_u8PerID); break;
			case RCC_APB2: CLR_BIT(RCC->APB2ENR, Copy_u8PerID); break;
			default: Local_u8ErrorState = ERR;
		}
	}
	else
	{
		/* Return error */
		Local_u8ErrorState = ERR;
	}

	return Local_u8ErrorState;
}
