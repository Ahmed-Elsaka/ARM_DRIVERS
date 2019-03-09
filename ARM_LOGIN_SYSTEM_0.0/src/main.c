#include "..\include\STD_TYPES.h"
#include "delay.h"




int
main(void)
{
	u8 keypad_status[16];
	u8 Local_ID[5];
	u8 Local_PASS[5];
	u8 Local_loopIndex =0;
	u8 Local_outerLoopIndex =0;
	u8 val = 0 ;
	u8 Local_IDAndPsFlag = 0 ;
	// initialize calculator
	Calculator_init();


for(Local_outerLoopIndex = 0 ; Local_outerLoopIndex <3 ; Local_outerLoopIndex++){
	LCD_u8ClearScreen();
	LCD_Au8writeStringWithIndex("ID : ", 0, 0);
	LCD_Au8writeStringWithIndex("Pass : ", 0, 1);

	// return the cursor to first line
	LCD_Au8writeStringWithIndex(" ", 5,0);
	// get id from user
	for(Local_loopIndex = 0 ; Local_loopIndex  < 4; Local_loopIndex++){
		Local_ID[Local_loopIndex] = KPD_getchar();
		delay_millisecond(1000);
		LCD_u8WriteData(Local_ID[Local_loopIndex]);

	}

	Local_ID[4]='\0';
	// get password from user
	LCD_Au8writeStringWithIndex(" ", 7,1);
	for(Local_loopIndex = 0 ; Local_loopIndex  < 4; Local_loopIndex++){
		Local_PASS[Local_loopIndex] = KPD_getchar();
		delay_millisecond(1000);
		LCD_u8WriteData(Local_PASS[Local_loopIndex]);
	}
	Local_PASS[4]='\0';

	if(CompareTwoString("1234", Local_ID,4) && CompareTwoString("4321", Local_PASS,4)){
		LCD_u8ClearScreen();
		LCD_Au8writeStringWithIndex("Welcome My friend ",0,0);
		Local_IDAndPsFlag = 1;
		break;
	}else{
		LCD_u8ClearScreen();
		LCD_Au8writeStringWithIndex("Try Again ",0,0);
		delay_millisecond(2000);
	}
}

if(Local_IDAndPsFlag ==0){
	LCD_u8ClearScreen();
	LCD_Au8writeStringWithIndex("BYE BYE 3",0,0);
	delay_millisecond(1000);
	LCD_Au8writeStringWithIndex("2",8,0);
	delay_millisecond(1000);
	LCD_Au8writeStringWithIndex("1",8,0);
	delay_millisecond(1000);
	LCD_Au8writeStringWithIndex("0",8,0);
	delay_millisecond(1000);
	LCD_u8ClearScreen();
}

	return 0;
}



// ----------------------------------------------------------------------------
