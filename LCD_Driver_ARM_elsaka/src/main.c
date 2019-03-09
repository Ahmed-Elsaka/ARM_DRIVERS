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

// ----------------------------------------------------------------------------
#include "../include/STD_TYPES.h"
#include "../include/BIT_CALC.h"

#include "../include/RCC_interface.h"
#include "../include/DIO_interface.h"
#include "../include/lcd_interface.h"
#include "../include/delay.h"
#include "../include/LCD_config.h"

// ----------------------------------------------------------------------------
//
// Standalone STM32F1 empty sample (trace via DEBUG).
//
// Trace support is enabled by adding the TRACE macro definition.
// By default the trace messages are forwarded to the DEBUG output,
// but can be rerouted to any device or completely suppressed, by
// changing the definitions required in system/src/diag/trace_impl.c
// (currently OS_USE_TRACE_ITM, OS_USE_TRACE_SEMIHOSTING_DEBUG/_STDOUT).
//

// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.


int main()
{
  // At this stage the system clock should have already been configured
  // at high speed.

	RCC_voidInitialze();
	RCC_u8EnablePrephiral(0);
	RCC_u8EnablePrephiral(1);
	RCC_u8EnablePrephiral(2);
	RCC_u8EnablePrephiral(3);
	DIO_voidInit();
	LCD_voidInit();


	{
//	LCD_u8WriteCommand(0b11000101);
//
//	LCD_u8WriteCommand(0b01000000);
//	LCD_u8WriteData(8);
//	LCD_u8WriteData(8);
//	LCD_u8WriteData(8);
//	LCD_u8WriteData(8);
//	LCD_u8WriteData(8);
//	LCD_u8WriteData(8);
//	LCD_u8WriteData(8);
//	LCD_u8WriteData(8);
//
//
//
//
//	LCD_u8WriteData(0);
//	LCD_u8WriteData(0);
//	LCD_u8WriteData(24);
//	LCD_u8WriteData(4);
//	LCD_u8WriteData(2);
//	LCD_u8WriteData(255);
//	LCD_u8WriteData(0);
//	LCD_u8WriteData(0);
//
//
//	LCD_u8WriteData(0);
//	LCD_u8WriteData(0);
//	LCD_u8WriteData(0);
//	LCD_u8WriteData(0);
//	LCD_u8WriteData(3);
//	LCD_u8WriteData(255);
//	LCD_u8WriteData(0);
//	LCD_u8WriteData(0);
//
//
//
//
//	LCD_u8WriteData(1);
//	LCD_u8WriteData(1);
//	LCD_u8WriteData(1);
//	LCD_u8WriteData(1);
//	LCD_u8WriteData(1);
//	LCD_u8WriteData(255);
//	LCD_u8WriteData(0);
//	LCD_u8WriteData(0);
//
//
//	LCD_u8WriteData(' ');
//
//	// w
//	// 0, 7, 5, 7, 1, 255, 0, 0
//	LCD_u8WriteData(0);
//	LCD_u8WriteData(7);
//	LCD_u8WriteData(5);
//	LCD_u8WriteData(7);
//	LCD_u8WriteData(1);
//	LCD_u8WriteData(255);
//	LCD_u8WriteData(0);
//	LCD_u8WriteData(0);
//
//
//
//	//  (0, 0, 7, 4, 4, 255, 0, 0 a
//
//	LCD_u8WriteData(0);
//	LCD_u8WriteData(0);
//	LCD_u8WriteData(7);
//	LCD_u8WriteData(4);
//	LCD_u8WriteData(4);
//	LCD_u8WriteData(255);
//	LCD_u8WriteData(0);
//	LCD_u8WriteData(0);
//
//// R
//
//	LCD_u8WriteData(255);
//	LCD_u8WriteData(1);
//	LCD_u8WriteData(1);
//	LCD_u8WriteData(0);
//	LCD_u8WriteData(0);
//	LCD_u8WriteData(0);
//	LCD_u8WriteData(0);
//	LCD_u8WriteData(0);
//
//
//	LCD_u8WriteCommand(0b10000000);
//	LCD_u8WriteData(3);
//	LCD_u8WriteData(2);
//	LCD_u8WriteData(1);
//	LCD_u8WriteData(0);
//
//
//	LCD_u8WriteData(6);
//	LCD_u8WriteData(5);
//	LCD_u8WriteData(4);
	}
	 LCD_Au8writeStringWithIndex("Ahmed Fathy Elsakaaaaaaaaaaaaaaaaaaaaa" , 8, 0);


return 0;
}


// ----------------------------------------------------------------------------



