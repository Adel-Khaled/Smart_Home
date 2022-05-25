/*
 * KPD_PROG.c
 *
 *  Created on: May 14, 2022
 *      Author: Adel Khaled
 */

#include "../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"../../MCAL/DIO/DIO_interface.h"
#include"KPD_config.h"
#include"KPD_Private.h"
#include"KPD_INT.h"

u8 KPD_U8GetPressedKey(){
	u8 Local_u8ColIndex , Local_u8RowIndex , Local_u8PinState , Local_u8PressedKey=NO_PRESSED_KEY_VALUE;
	u8 KPD_u8Array[KPD_ROW_NUMBER][KPD_COLUMN_NUMBER] = KPD_BUTTONS_VALUES;

	u8 KPD_u8ColumnArray[KPD_COLUMN_NUMBER]={KPD_COLUMN_PIN0,KPD_COLUMN_PIN1,KPD_COLUMN_PIN2};
	u8 KPD_u8RowArray[KPD_ROW_NUMBER]={KPD_ROW_PIN0,KPD_ROW_PIN1,KPD_ROW_PIN2};


	for(Local_u8ColIndex=0 ; Local_u8ColIndex < KPD_COLUMN_NUMBER ; Local_u8ColIndex++){

		// Activate the current column
		MDIO_voidSetPinValue(KPD_u8ColumnArray[Local_u8ColIndex],KPD_PORT,DIO_LOW);

		for(Local_u8RowIndex=0 ; Local_u8RowIndex < KPD_ROW_NUMBER ; Local_u8RowIndex++){

			// Read the current Row
			Local_u8PinState = MDIO_u8GetPinValue(KPD_u8RowArray[Local_u8RowIndex],KPD_PORT);

			if(Local_u8PinState == DIO_LOW){

				Local_u8PressedKey=KPD_u8Array[Local_u8RowIndex][Local_u8ColIndex];

				// wait with blocking until the key released   (polling with Blocking)
				while(Local_u8PinState == DIO_LOW){

					Local_u8PinState = MDIO_u8GetPinValue(KPD_u8RowArray[Local_u8RowIndex],KPD_PORT);
				}
				return Local_u8PressedKey;
			}
		}
		MDIO_voidSetPinValue(KPD_u8ColumnArray[Local_u8ColIndex],KPD_PORT,DIO_HIGH);
	}
	return Local_u8PressedKey;
}
