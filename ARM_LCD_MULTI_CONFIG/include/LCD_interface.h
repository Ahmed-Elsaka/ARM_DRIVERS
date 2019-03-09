/*
 * lcd_interface.h
 *
 *  Created on: Mar 4, 2019
 *      Author: Killua
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


void LCD_voidInit();
u8 LCD_u8ClearScreen(void);
u8 LCD_u8WriteCommand(u8 Copy_u8Command);
u8 LCD_u8WriteData(u8 Copy_u8Data);
u8 Lcd_Au8WriteString(u8 * Copy_Pu8String);

u8 LCD_Au8writeStringWithIndex(u8 * Copy_pu8String,u8  Copy_u8XPos,u8  Copy_u8YPos);

#endif /* LCD_INTERFACE_H_ */
