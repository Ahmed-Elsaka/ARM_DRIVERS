/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include <stdio.h>
// ----------------------------------------------------------------------------
#include "..\include\STD_TYPES.h"
#include "..\include\BIT_CALC.h"
#include "..\include\RCC_interface.h"
#include "..\include\DIO_interface.h"
#include "KPD_interface.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"
#include "delay.h"






int
main(void)
{


	/****************Initial Functions******************/
	RCC_voidInitialze();
	RCC_u8EnablePrephiral(RCC_u8_GPIOA);
	RCC_u8EnablePrephiral(RCC_u8_GPIOB);
	RCC_u8EnablePrephiral(RCC_u8_GPIOC);
	RCC_u8EnablePrephiral(RCC_u8_GPIOD);
	DIO_voidInit();
	LCD_voidInit();

	switch(LCD_MODE){
	case EIGHT_BIT_MODE :
		LCD_Au8writeStringWithIndex("Eight_bit_mode", 0,0);
		break;
	case FOUR_BIT_MODE :
		LCD_Au8writeStringWithIndex("Four_bit_mode", 0, 0);
		break;
	}


	return 0;
}



// ----------------------------------------------------------------------------
