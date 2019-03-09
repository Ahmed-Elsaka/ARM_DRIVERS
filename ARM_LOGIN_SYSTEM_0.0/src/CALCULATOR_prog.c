/*
 * CALCULATOR_prog.c
 *
 *  Created on: Mar 8, 2019
 *      Author: Killua
 */
#include "STD_TYPES.h"
#include "..\include\BIT_CALC.h"
#include "..\include\RCC_interface.h"
#include "..\include\DIO_interface.h"
#include "KPD_interface.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"


u8 Calculator_init(){
	RCC_voidInitialze();
	RCC_u8EnablePrephiral(RCC_u8_GPIOA);
	RCC_u8EnablePrephiral(RCC_u8_GPIOB);
	RCC_u8EnablePrephiral(RCC_u8_GPIOC);
	RCC_u8EnablePrephiral(RCC_u8_GPIOD);
	DIO_voidInit();
	LCD_voidInit();
	KPD_voidInit();
}

u8 KPD_getchar(){
	u8 keypad_characters [] ="147*2580369#abcd";
	u8 keypad_status[16];
	u8 Local_loopIndex = 0;
	while(1){
		KPD_u8GetKeysState(keypad_status);
		if(keypad_status[Local_loopIndex]==0){
			return keypad_characters[Local_loopIndex];
		}
		if(Local_loopIndex == 15) Local_loopIndex = 0 ;
		else Local_loopIndex++;


	}
	return -1;
}

u8 CompareTwoString(u8 * Copy_pu8String1, u8 * Copy_pu8String2, u8 Copy_u8Length){
	u8 Local_loopIndex = 0 ;
	u8 Local_u8Result = 1;
	for(Local_loopIndex =0 ; Local_loopIndex < Copy_u8Length; Local_loopIndex++){
		if (Copy_pu8String1[Local_loopIndex] != Copy_pu8String2[Local_loopIndex]){
			Local_u8Result = 0;
			break;
		}
	}
	return Local_u8Result;
}


