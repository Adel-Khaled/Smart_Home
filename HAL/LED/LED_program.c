/*************************************************************************/
/*	Author:  AbdelRahman Ra'fat Hegazy									*/
/*	Date: 	 29/4/2022													*/
/*	Version: V01														*/
/*************************************************************************/

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"

#include"../../MCAL/DIO/DIO_interface.h"
#include "LED_interface.h"

void HLED_voidInit(u8 copy_u8LedPin,u8 copy_u8LedPort)
{
	MDIO_voidSetPinMode (copy_u8LedPin,copy_u8LedPort,DIO_OUTPUT);
	MDIO_voidSetPinValue(copy_u8LedPin,copy_u8LedPort,DIO_LOW);
}

void HLED_voidOn(u8 copy_u8LedPin,u8 copy_u8LedPort)
{
	MDIO_voidSetPinValue(copy_u8LedPin,copy_u8LedPort,DIO_HIGH);
}

void HLED_voidOff(u8 copy_u8LedPin,u8 copy_u8LedPort)
{
	MDIO_voidSetPinValue(copy_u8LedPin,copy_u8LedPort,DIO_LOW);
}

void HLED_voidToggle(u8 copy_u8LedPin,u8 copy_u8LedPort)
{
	MDIO_voidTogPinValue(copy_u8LedPin,copy_u8LedPort);
}
