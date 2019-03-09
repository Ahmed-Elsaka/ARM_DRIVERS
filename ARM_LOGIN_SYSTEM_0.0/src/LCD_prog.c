/**************************************************/
/* Author      :  Ahmed Elsaka                    */
/* Date        : 6/3/2019                         */
/* Description :                                  */
/* -------------                                  */
/*   this file  contains implementations of       */
/*  LCD_prog.c                                    */
/**************************************************/
#include "../include/STD_TYPES.h"
#include "../include/BIT_CALC.h"
#include "../include/DIO_interface.h"
#include "../include/LCD_config.h"
#include "../include/LCD_private.h"
#include "../include/LCD_interface.h"
#include "../include/delay.h"


void LCD_voidInit(){
	/*********************************************************/
	/*Description :                                          */
	/*------------                                           */
	/*		this function initialize LCD with Commands       */
	/* INPUTS :                                              */
	/* 	this function take no arguments                      */
	/*********************************************************/
	/* set zero on lcd enable pin                           */
	DIO_u8SetPinValue(LCD_EN_Pin, 0);
	/* delay should be 39 micro second                       */
	delay_millisecond(2000);

	switch (LCD_MODE){
		case EIGHT_BIT_MODE :
			/* set 8-bit mode for lcd                                */
			LCD_u8WriteCommand(0x38);

			break;
		case FOUR_BIT_MODE :

			/* set 8-bit mode for lcd                                */
			LCD_u8WriteCommand(0x33);
			LCD_u8WriteCommand(0x32);
			LCD_u8WriteCommand(0x28);
		break;

	}
	/* turn on display and turn cursor on                    */
	LCD_u8WriteCommand(0x0E);
	/* delay should be 39 micro second also                  */
	delay_millisecond(1000);
	/* clear LCD                                             */
	LCD_u8WriteCommand(0x01);
	/* delay will 1.53 millisecond                        */
	delay_millisecond(5000);
	/* shift the cursor right                                 */
	LCD_u8WriteCommand(0x06);

}


u8 LCD_u8WriteCommand(u8 Copy_u8Command){
	/*********************************************************/
	/*Description :                                          */
	/*------------                                           */
	/*		this function Send  Commands to LCD              */
	/* INPUTS :                                              */
	/* 	Copy_u8Command : this is the command                 */
	/*********************************************************/

	/* the display is working in 8-bit mode so when using u8 */
	/* we will send each bit on specific pin                 */
	switch (LCD_MODE){
		case EIGHT_BIT_MODE :
			DIO_u8SetPinValue(LCD_D0_Pin,BIT_CALC_GET_BIT(Copy_u8Command, 0));
				/* send bit 1 on Lcd D1 pin                              */
				DIO_u8SetPinValue(LCD_D1_Pin,BIT_CALC_GET_BIT(Copy_u8Command, 1));
				/* send bit 2 on Lcd D2 pin                              */
				DIO_u8SetPinValue(LCD_D2_Pin,BIT_CALC_GET_BIT(Copy_u8Command, 2));
				/* send bit 3 on Lcd D3 pin                              */
				DIO_u8SetPinValue(LCD_D3_Pin,BIT_CALC_GET_BIT(Copy_u8Command, 3));
				/* send bit 4 on Lcd D4 pin                              */
				DIO_u8SetPinValue(LCD_D4_Pin,BIT_CALC_GET_BIT(Copy_u8Command, 4));
				/* send bit 5 on Lcd D5 pin                              */
				DIO_u8SetPinValue(LCD_D5_Pin,BIT_CALC_GET_BIT(Copy_u8Command, 5));
				/* send bit 6 on Lcd D6 pin                              */
				DIO_u8SetPinValue(LCD_D6_Pin,BIT_CALC_GET_BIT(Copy_u8Command, 6));
				/* send bit 7 on Lcd D7 pin                              */
				DIO_u8SetPinValue(LCD_D7_Pin,BIT_CALC_GET_BIT(Copy_u8Command, 7));
					DIO_u8SetPinValue(LCD_RS_Pin,0);
					DIO_u8SetPinValue(LCD_RW_Pin,0);
					DIO_u8SetPinValue(LCD_EN_Pin,1);
					delay_millisecond(3000);
					DIO_u8SetPinValue(LCD_EN_Pin,0);
					delay_millisecond(1000);

			break;
		case FOUR_BIT_MODE :
			/* send bit 0 on Lcd D0 pin                              */
			DIO_u8SetPinValue(LCD_D4_Pin,BIT_CALC_GET_BIT(Copy_u8Command, 4));
			/* send bit 1 on Lcd D1 pin                              */
			DIO_u8SetPinValue(LCD_D5_Pin,BIT_CALC_GET_BIT(Copy_u8Command, 5));
			/* send bit 2 on Lcd D2 pin                              */
			DIO_u8SetPinValue(LCD_D6_Pin,BIT_CALC_GET_BIT(Copy_u8Command, 6));
			/* send bit 3 on Lcd D3pin                              */
			DIO_u8SetPinValue(LCD_D7_Pin,BIT_CALC_GET_BIT(Copy_u8Command, 7));

			DIO_u8SetPinValue(LCD_RS_Pin,0);
			DIO_u8SetPinValue(LCD_RW_Pin,0);
			DIO_u8SetPinValue(LCD_EN_Pin,1);
			delay_millisecond(3000);
			DIO_u8SetPinValue(LCD_EN_Pin,0);
			delay_millisecond(3000);

			/* send bit 4 on Lcd D4 pin                              */
			DIO_u8SetPinValue(LCD_D4_Pin,BIT_CALC_GET_BIT(Copy_u8Command, 0));
			/* send bit 5 on Lcd D5 pin                              */
			DIO_u8SetPinValue(LCD_D5_Pin,BIT_CALC_GET_BIT(Copy_u8Command, 1));
			/* send bit 6 on Lcd D6 pin                              */
			DIO_u8SetPinValue(LCD_D6_Pin,BIT_CALC_GET_BIT(Copy_u8Command, 2));
			/* send bit 7 on Lcd D7 pin                              */
			DIO_u8SetPinValue(LCD_D7_Pin,BIT_CALC_GET_BIT(Copy_u8Command, 3));


				DIO_u8SetPinValue(LCD_EN_Pin,1);
				delay_millisecond(3000);
				DIO_u8SetPinValue(LCD_EN_Pin,0);
				delay_millisecond(3000);

				break;
	}


	return 0;
}
u8 LCD_u8WriteData(u8 Copy_u8Data){
	/*********************************************************/
	/*Description :                                          */
	/*------------                                           */
	/*		this function Send  character to LCD             */
	/* INPUTS :                                              */
	/* 	Copy_u8Command : this is the character               */
	/*********************************************************/

	/* the display is working in 8-bit mode so when using u8 */
	/* we will send each bit on specific pin                 */
	switch (LCD_MODE){
	case EIGHT_BIT_MODE :
		/* send bit 0 on Lcd D0 pin                              */
			DIO_u8SetPinValue(LCD_D0_Pin,BIT_CALC_GET_BIT(Copy_u8Data, 0));
			/* send bit 1 on Lcd D1 pin                              */
			DIO_u8SetPinValue(LCD_D1_Pin,BIT_CALC_GET_BIT(Copy_u8Data, 1));
			/* send bit 2 on Lcd D2 pin                              */
			DIO_u8SetPinValue(LCD_D2_Pin,BIT_CALC_GET_BIT(Copy_u8Data, 2));
			/* send bit 3 on Lcd D3 pin                              */
			DIO_u8SetPinValue(LCD_D3_Pin,BIT_CALC_GET_BIT(Copy_u8Data, 3));
			/* send bit 4 on Lcd D4 pin                              */
			DIO_u8SetPinValue(LCD_D4_Pin,BIT_CALC_GET_BIT(Copy_u8Data, 4));
			/* send bit 5 on Lcd D5 pin                              */
			DIO_u8SetPinValue(LCD_D5_Pin,BIT_CALC_GET_BIT(Copy_u8Data, 5));
			/* send bit 6 on Lcd D6 pin                              */
			DIO_u8SetPinValue(LCD_D6_Pin,BIT_CALC_GET_BIT(Copy_u8Data, 6));
			/* send bit 7 on Lcd D7 pin                              */
			DIO_u8SetPinValue(LCD_D7_Pin,BIT_CALC_GET_BIT(Copy_u8Data, 7));

			DIO_u8SetPinValue(LCD_RS_Pin,1);
			DIO_u8SetPinValue(LCD_RW_Pin,0);
			DIO_u8SetPinValue(LCD_EN_Pin,1);
			delay_millisecond(500);
			DIO_u8SetPinValue(LCD_EN_Pin,0);
			delay_millisecond(500);

		break;
	case FOUR_BIT_MODE  :
		/* send bit 0 on Lcd D0 pin                              */
		DIO_u8SetPinValue(LCD_D4_Pin,BIT_CALC_GET_BIT(Copy_u8Data, 4));
		/* send bit 1 on Lcd D1 pin                              */
		DIO_u8SetPinValue(LCD_D5_Pin,BIT_CALC_GET_BIT(Copy_u8Data, 5));
		/* send bit 2 on Lcd D2 pin                              */
		DIO_u8SetPinValue(LCD_D6_Pin,BIT_CALC_GET_BIT(Copy_u8Data, 6));
		/* send bit 3 on Lcd D3pin                              */
		DIO_u8SetPinValue(LCD_D7_Pin,BIT_CALC_GET_BIT(Copy_u8Data, 7));

		DIO_u8SetPinValue(LCD_RS_Pin,1); // try
		DIO_u8SetPinValue(LCD_RW_Pin,0);
		delay_millisecond(1000);
		DIO_u8SetPinValue(LCD_EN_Pin,1);
		delay_millisecond(500);
		DIO_u8SetPinValue(LCD_EN_Pin,0);
		delay_millisecond(500);



		DIO_u8SetPinValue(LCD_D4_Pin,BIT_CALC_GET_BIT(Copy_u8Data, 0));
		/* send bit 5 on Lcd D5 pin                              */
		DIO_u8SetPinValue(LCD_D5_Pin,BIT_CALC_GET_BIT(Copy_u8Data, 1));
		/* send bit 6 on Lcd D6 pin                              */
		DIO_u8SetPinValue(LCD_D6_Pin,BIT_CALC_GET_BIT(Copy_u8Data, 2));
		/* send bit 7 on Lcd D7 pin                              */
		DIO_u8SetPinValue(LCD_D7_Pin,BIT_CALC_GET_BIT(Copy_u8Data, 3));


		DIO_u8SetPinValue(LCD_EN_Pin,1);
		delay_millisecond(500);
		DIO_u8SetPinValue(LCD_EN_Pin,0);
		delay_millisecond(1000);

		break;
	}

	return 0 ;
}



u8 LCD_Au8writeStringWithIndex(u8 * Copy_pu8String,u8  Copy_u8XPos,u8  Copy_u8YPos){
	u8 Local_u8Result = ERROR_OK;
	u8 Local_u8Address;

	if((Copy_u8XPos < 16 ) && (Copy_u8YPos < 2)){
		Local_u8Address = Copy_u8XPos + (Copy_u8YPos * 0x40);
		Local_u8Address |=0x80;
		LCD_u8WriteCommand(Local_u8Address);

		while( * Copy_pu8String != END_OF_STRING){
			LCD_u8WriteData(* Copy_pu8String);
			Copy_pu8String++;
			Local_u8Address++; // this variable simulate address counter ;

			/* End of line 1 */
			if(Local_u8Address == 0x90){
				Local_u8Address = 0xC0;   // 4 + 1 on left
				LCD_u8WriteCommand(Local_u8Address);
			}

			// End of line 2 *

			else if (Local_u8Address ==0xD0){
				Local_u8Address = 0x80;
				LCD_u8WriteCommand(Local_u8Address);
			}
		}
	}else {
		Local_u8Result = ERROR_NOK;
	}
	return Local_u8Result;
}



u8 LCD_u8ClearScreen(void){
	LCD_u8WriteCommand(LCD_CLEAR_CMD);
	return ERROR_OK;
}



u8 LCD_u8GoToXY(u8 Copy_u8XPosition, u8 Copy_u8YPosition){
	u8 Local_u8Error_State = ERROR_OK;
	if((Copy_u8XPosition< 16 ) && (Copy_u8YPosition < 2)){

		u8 Local_u8FirstCharAddress []={0x80,0xC0,0x94,0xD4};
		LCD_u8WriteCommand(Local_u8FirstCharAddress[Copy_u8YPosition-1]+Copy_u8XPosition-1);
	}else {
		Local_u8Error_State= ERROR_NOK;
	}
	return Local_u8Error_State;

}

















