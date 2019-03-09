#include "..\include\STD_TYPES.h"
#include "..\include\BIT_CALC.h"
#include "..\include\RCC_interface.h"
#include "..\include\RCC_config.h"
#include "..\include\RCC_private.h"
/*
bit1 ,bit0
00: HSI selected as system clock
01: HSE selected as system clock
10: PLL selected as system clock
*/

void RCC_voidInitialze(void)
{
	/*
	issue : PLL

	cases:
		case1:
			Config:
				-HSE_State ON
				-HSI_State ON
				-PLL_State ON
				-SysCLK
			/*Check Corner Cases*/
			/*	#if PLL_STATE OFF && SYSCLK_SRC PLL ==> Warning and PLL_STATE is ON
				#if PLL_STATE ON && PLL_SRC HSI && HSI_STATE OFF ==> Warning and HSI_STATE is ON
				#if PLL_STATE ON && PLL_SRC HSE && HSE_STATE OFF ==> Warning and HSE_STATE is ON
			/*======================================================================================
	*/
	if(HSI_STATE)
	{
		RCC->CR.BitAccess.Bit0=1;
	}
	if(HSE_STATE)
	{
		RCC->CR.BitAccess.Bit16=1;
	}
	if(PLL_STATE)
	{
		/*PLL is ON */
		if(RCC->CR.BitAccess.Bit24)
		{

			#if PLL_SRC == HSE
			while(!(RCC->CR.BitAccess.Bit17));/*Monitor HSE RDY Flag*/
			RCC->CFGR |=(1<<0)|(1<<1);        /*Switch to HSE*/
			#endif

			#if PLL_SRC == HALF_HSE
			while(!(RCC->CR.BitAccess.Bit17));/*Monitor HSE RDY Flag*/
			RCC->CFGR |=(1<<0)|(1<<1);        /*Switch to HSE*/
			#endif

			#if PLL_SRC == PLL_HALF_HSI
			/*Switch to HSI*/
			while(!(RCC->CR.BitAccess.Bit1));/*Monitor HSI RDY Flag*/
			RCC->CFGR.WordAccess |=(1<<0)|(1<<1); /*Switch to HSI*/
			#endif

			/*Make PLL OFF*/
			RCC->CR.BitAccess.Bit23=0;
			/*Choose PLL_HALF_HSI as PLL_SRC*/
		}

		switch(PLL_SRC)
		{
			case PLL_HALF_HSI:
				RCC->CFGR.BitAccess.Bit16=0;
			break;

			case PLL_HSE:
				RCC->CFGR.BitAccess.Bit17=0;
				RCC->CFGR.BitAccess.Bit16=1;
			break;

			case PLL_HALF_HSE:
				RCC->CFGR.BitAccess.Bit17=1;
				RCC->CFGR.BitAccess.Bit16=1;
			break;

		}
		/*Assign Multiplier Value*/
		/*Assign Multiplier Value*/
		/*Assign Multiplier Value*/
		(RCC->CFGR.WordAccess)= (PLL_MULTIPLIER << RCC_CFGR_MUL_SHIFT_VAL) |  ((RCC->CFGR.WordAccess) & (~(0xF<<(RCC_CFGR_MUL_SHIFT_VAL))));		RCC->CR.BitAccess.Bit23=1;
		/*PLL is OFF*/
	}

	switch(CLOCK_SRC)
	{
		case HSE:
			while(!(RCC->CR.BitAccess.Bit17));/*Monitor HSE RDY Flag*/
			RCC->CFGR.WordAccess |=(1<<0)|(1<<1);        /*Switch to HSE*/
		break;
		
		case HSI:
			while(!(RCC->CR.BitAccess.Bit1));/*Monitor HSI RDY Flag*/
			RCC->CFGR.WordAccess |=(1<<0)|(1<<1); /*Switch to HSI*/
		break;
		
		case PLL:
		/*Monitor PLL RDY Flag*/
		while(!(RCC->CR.BitAccess.Bit25));
		/*Switch to PLL*/
		RCC->CFGR.WordAccess |=(1<<1);
		RCC->CFGR.WordAccess &=~(1<<0);
	}
	return;
}



u8 RCC_u8EnablePrephiral(u8 Copy_u8Prephiral)
{
	u8 Local_u8Resutl=ERROR_OK;
 
	 switch(Copy_u8Prephiral)
	 {
		case RCC_u8_GPIOA: RCC->APB2ENR.BitAccess.Bit2=1; break;
		case RCC_u8_GPIOB: RCC->APB2ENR.BitAccess.Bit3=1; break;
		case RCC_u8_GPIOC: RCC->APB2ENR.BitAccess.Bit4=1; break;
		case RCC_u8_GPIOD: RCC->APB2ENR.BitAccess.Bit5=1; break;
		default: Local_u8Resutl=ERROR_NOK;
	 }
	 
	return Local_u8Resutl;
}
