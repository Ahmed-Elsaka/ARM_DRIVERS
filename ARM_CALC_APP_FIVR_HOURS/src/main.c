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
#include "delay.h"





u8 num1, num2, num1_Entered, num2_Entered, operator= 0;
u8 number = 0;

u8 number1, number2 ;

void PrintKeypadValue(u8 Copy_u8Col, u8 Copy_u8Row) {
	u8 States[16];
	u8 count = 0 ;
	KPD_u8GetKeysState(States);
	// for(count=0;count<16;count++)
	// {
	// 	while(!(States[count])) break;
	// }

			if(States[0] == 0)
			{
				number = 1 ;
				LCD_Au8writeStringWithIndex("1",Copy_u8Col,Copy_u8Row);
				delay_millisecond(1000);

			}
			else if(States[1] ==0)
			{
				number = 4;
				LCD_Au8writeStringWithIndex("4",Copy_u8Col,Copy_u8Row);
				delay_millisecond(1000);
			}
			else if(States[2] ==0)
			{
				number = 7 ;
				LCD_Au8writeStringWithIndex("7",Copy_u8Col,Copy_u8Row);
				delay_millisecond(1000);
			}else if(States[3] == 0)
			{
				operator = '*';
				LCD_Au8writeStringWithIndex("*",Copy_u8Col,Copy_u8Row);
				delay_millisecond(1000);
			}
			else if(States[4] ==0)
			{
				number = 2;
				LCD_Au8writeStringWithIndex("2",Copy_u8Col,Copy_u8Row);
				delay_millisecond(1000);
			}
			else if(States[5] ==0)
			{
				number= 5;
				LCD_Au8writeStringWithIndex("5",Copy_u8Col,Copy_u8Row);
				delay_millisecond(1000);
			}else if(States[6] ==0)
			{
				number = 8 ;
				LCD_Au8writeStringWithIndex("8",Copy_u8Col,Copy_u8Row);
				delay_millisecond(1000);
			}
			else if(States[7] ==0)
			{
				number = 0 ;
				LCD_Au8writeStringWithIndex("0",Copy_u8Col,Copy_u8Row);
				delay_millisecond(1000);
			}else if(States[8] == 0)
			{
				number = 3;
				LCD_Au8writeStringWithIndex("3",Copy_u8Col,Copy_u8Row);
				delay_millisecond(1000);
			}
			else if(States[9] ==0)
			{
				number = 6;
				LCD_Au8writeStringWithIndex("6",Copy_u8Col,Copy_u8Row);
				delay_millisecond(1000);
			}
			else if(States[10] ==0)
			{
				number = 9 ;
				LCD_Au8writeStringWithIndex("9",Copy_u8Col,Copy_u8Row);
				delay_millisecond(1000);
			}
			else if(States[11] ==0)
			{
				operator = '#';
				LCD_Au8writeStringWithIndex("#",Copy_u8Col,Copy_u8Row);
				delay_millisecond(1000);
			}
			else if(States[12] ==0)
			{
				operator = '+';
				LCD_Au8writeStringWithIndex("+",Copy_u8Col,Copy_u8Row);
				delay_millisecond(1000);
			}else if(States[13] == 0)
			{
				operator = '-';
				LCD_Au8writeStringWithIndex("-",Copy_u8Col,Copy_u8Row);
				delay_millisecond(1000);
			}
			else if(States[14] ==0)
			{
				operator ='/';
				LCD_Au8writeStringWithIndex("/",Copy_u8Col,Copy_u8Row);
				delay_millisecond(1000);
			}
			else if(States[15] ==0)
			{
				operator = '%';
				LCD_Au8writeStringWithIndex("%",Copy_u8Col,Copy_u8Row);
				delay_millisecond(1000);
			}


			if ( num1 == 0 ){
				num1 = number;
				number=0;
			}else if (num2 == 0 ){
				num2 = number;
			}else if (operator ==0){

			}

}


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
	KPD_voidInit();
	LCD_voidInit();




	while(1){







	// 1- welcome screen :
		LCD_u8ClearScreen();
		LCD_Au8writeStringWithIndex("Welcome",4,0);
		delay_millisecond(10000);

// 2- Enter operators Screen
		LCD_u8ClearScreen();
		LCD_Au8writeStringWithIndex("OP1: ",0,0);
		LCD_Au8writeStringWithIndex("OP2: ",0,1);
	// 3- let user insert operators
		// insert operator 1
		while(num1 == 0){
			PrintKeypadValue(5,0);
		}
		delay_millisecond(10000);
		// insert operator 2
		while (num2 == 0){
			PrintKeypadValue(5,1);
		}

		delay_millisecond(5000);
	// 4 - Select operation
		LCD_u8ClearScreen();
		LCD_Au8writeStringWithIndex("Operation: ",0,0);
		while (operator == 0){
			PrintKeypadValue(13,0);
		}
		delay_millisecond(10000);
	// 5 - print the result
		LCD_u8ClearScreen();

		int result = num1 + num2;

		//LCD(result+'0', 0, 0);
		switch(operator){
		case '*': result = num1 * num2 ; break;
		case '+': result = num2 + num1 ; break;
		case '/': result = num1 / num2 ; break ;
		case '-': result = num1 - num2 ; break;
		default :
			LCD_Au8writeStringWithIndex("fuck you :D :D", 0, 0);

		}

			char res[50];
			sprintf(res,"Result : %d",result);
			LCD_Au8writeStringWithIndex(res,0,0);



			delay_millisecond(50000);

			number =num1 = num2 = operator = 0 ;

	}
	return 0;
}



// ----------------------------------------------------------------------------
