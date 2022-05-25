/*************************************************************************/
/*	Author:  AbdelRahman Ra'fat Hegazy									*/
/*	Date: 	 29/4/2022													*/
/*	Version: V01														*/
/*************************************************************************/

#include"../../LIB/STD_TYPES.h"
#define F_CPU 8000000UL
#include<util/delay.h>
#include"../../MCAL/DIO/DIO_interface.h"
#include "BUZZER_interface.h"

void HBUZ_voidInit(u8 copy_u8BuzPin,u8 copy_u8BuzPort)
{
	MDIO_voidSetPinMode(copy_u8BuzPin,copy_u8BuzPort,DIO_OUTPUT);
	MDIO_voidSetPinValue(copy_u8BuzPin,copy_u8BuzPort,DIO_LOW);
}

void HBUZ_voidOn(u8 copy_u8BuzPin,u8 copy_u8BuzPort)
{
	MDIO_voidSetPinValue(copy_u8BuzPin , copy_u8BuzPort , DIO_HIGH);
}

void HBUZ_voidOff(u8 copy_u8BuzPin,u8 copy_u8BuzPort)
{
	MDIO_voidSetPinValue(copy_u8BuzPin , copy_u8BuzPort , DIO_LOW);
}

void HBUZ_voidToggle(u8 copy_u8BuzPin,u8 copy_u8BuzPort)
{
	MDIO_voidTogPinValue(copy_u8BuzPin , copy_u8BuzPort);
}

void HBUZ_voidOnce(u8 copy_u8BuzPin,u8 copy_u8BuzPort)
{
	MDIO_voidSetPinValue(copy_u8BuzPin , copy_u8BuzPort , DIO_HIGH);
	_delay_ms(200);
	MDIO_voidSetPinValue(copy_u8BuzPin , copy_u8BuzPort , DIO_LOW);
}

void HBUZ_voidTwice(u8 copy_u8BuzPin,u8 copy_u8BuzPort)
{
	MDIO_voidSetPinValue(copy_u8BuzPin , copy_u8BuzPort , DIO_HIGH);
	_delay_ms(200);
	MDIO_voidSetPinValue(copy_u8BuzPin , copy_u8BuzPort , DIO_LOW);
	_delay_ms(200);
	MDIO_voidSetPinValue(copy_u8BuzPin , copy_u8BuzPort , DIO_HIGH);
	_delay_ms(200);
	MDIO_voidSetPinValue(copy_u8BuzPin , copy_u8BuzPort , DIO_LOW);
}

void HBUZ_voidTriple(u8 copy_u8BuzPin,u8 copy_u8BuzPort)
{
	MDIO_voidSetPinValue(copy_u8BuzPin , copy_u8BuzPort , DIO_HIGH);
	_delay_ms(200);
	MDIO_voidSetPinValue(copy_u8BuzPin , copy_u8BuzPort , DIO_LOW);
	_delay_ms(200);
	MDIO_voidSetPinValue(copy_u8BuzPin , copy_u8BuzPort , DIO_HIGH);
	_delay_ms(200);
	MDIO_voidSetPinValue(copy_u8BuzPin , copy_u8BuzPort , DIO_LOW);
	_delay_ms(200);
	MDIO_voidSetPinValue(copy_u8BuzPin , copy_u8BuzPort , DIO_HIGH);
	_delay_ms(200);
	MDIO_voidSetPinValue(copy_u8BuzPin , copy_u8BuzPort , DIO_LOW);
}

void HBUZ_voidLong(u8 copy_u8BuzPin,u8 copy_u8BuzPort)
{
	MDIO_voidSetPinValue(copy_u8BuzPin , copy_u8BuzPort , DIO_HIGH);
}
