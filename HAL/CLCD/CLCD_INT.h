/*
 * LCD_INT.h
 *
 *  Created on: Aug 30, 2019
 *      Author: adel1
 */

#ifndef CLCD_INT_H_
#define CLCD_INT_H_




void CLCD_VoidInitial();                            // LCD Initialize
void CLCD_VoidSendCmd(u8 Copy_u8cmd);				// Set Command Line to LCD
void CLCD_VoidWrite(u8 Copy_u8Data);				// Write character in LCD
void CLCD_WriteString(u8 Copy_u8data[]);			// Write string in LCD
void CLCD_VoidGoToXY(u8 Copy_u8X,u8 Copy_u8Y);		// Go to specific Position
void CLCD_VoidWriteSpecialCharacter(u8 *Copy_pPattern,u8 Copy_u8blockNo,u8 Copy_u8X,u8 Copy_u8Y);    // Set new Pattern in CGRAM and write it in LCD
void CLCD_WriteNumber(u32 Copy_u32num);             // Write any number in LCD
void CLCD_Clear();                                  // Clear all data in LCD
#endif /* LCD_INT_H_ */
