/*************************************************************************/
/*	Author:  AbdelRahman Ra'fat Hegazy									*/
/*	Date: 	 29/4/2022													*/
/*	Version: V01														*/
/*************************************************************************/


#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H


#define	_8Bit_Mode	1
#define	_4Bit_Mode	0


/*
	Function Name:   HLCD_voidInit
	Input arguments: it takes no parameter (void)
	Return:		     it returns void
	Description: 	 this function is used to Initialed LCD.
*/
void HLCD_voidInit(void);

/*
	Function Name:   HLCD_voidWriteCmd
	Input arguments: it takes 1 parameter (command value)
	Return:		     it returns void
	Description: 	 this function is used to Send command to LCD.
*/
void HLCD_voidWriteCmd(u8 copy_u8Cmd);

/*
	Function Name:   HLCD_voidWriteChracter
	Input arguments: it takes 1 parameter (character)
	Return:		     it returns void
	Description: 	 this function is used to display character.
*/
void HLCD_voidWriteChracter(u8 copy_u8Chr);

/*
	Function Name:   HLCD_voidWriteString
	Input arguments: it takes 1 parameter (pointer to array of characters)
	Return:		     it returns void
	Description: 	 this function is used to print string on LCD.
*/
void HLCD_voidWriteString(u8* copy_u8PStr);

/*
	Function Name:   HLCD_voidGoTo
	Input arguments: it takes 2 parameters (Row_location,col_location)
	Return:		     it returns void
	Description: 	 this function is used to set cursor to specific position on LCD.
*/
void HLCD_voidGoTo(u8 copy_u8XLoc , u8 copy_u8YLoc);

/*
	Function Name:   HLCD_voidClear
	Input arguments: it takes No parameter (void)
	Return:		     it returns void
	Description: 	 this function is used to Clear LCD.
*/
void HLCD_voidClear(void);

/*
	Function Name:   HLCD_voidWriteNumber
	Input arguments: it takes 1 parameter (float Number to be displayed on LCD)
	Return:		     it returns void
	Description: 	 this function is used to Display Number on LCD.
*/
void HLCD_voidWriteNumber(f64 number);

void HLCD_voidWriteIntNumber(s32 copy_s32Num);

#endif
