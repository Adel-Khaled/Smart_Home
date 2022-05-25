/*************************************************************************/
/*	Author:  AbdelRahman Ra'fat Hegazy									*/
/*	Date: 	 29/4/2022													*/
/*	Version: V01														*/
/*************************************************************************/


#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/***************************************************************************/
/**************************public Macros********************************/
/**************************************************************************/
/*Value States*/
#define DIO_HIGH	1
#define DIO_LOW		0

/*Mode States*/
#define DIO_INPUT	0
#define DIO_OUTPUT	1

/*PORTS ID*/
#define DIO_PORTA	0
#define DIO_PORTB	1
#define DIO_PORTC	2
#define DIO_PORTD	3

/*PINS ID*/
#define DIO_PIN0	0
#define DIO_PIN1	1
#define DIO_PIN2	2
#define DIO_PIN3	3
#define DIO_PIN4	4
#define DIO_PIN5	5
#define DIO_PIN6	6
#define DIO_PIN7	7


/***************************************************************************/
/**************************public functions********************************/
/**************************************************************************/

/*
	Function Name:   MMDIO_voidSetPinMode
	Input arguments: it takes 3 parameters 1-PIN NUMBER 2-PORT_NUMBER 3-PIN Direction
	Return:		     it returns void
	Description: 	 this function determine The direction of pin.
*/
void MDIO_voidSetPinMode(u8 copy_u8PinId , u8 copy_u8PortId , u8 copy_u8PinMode);

/*
	Function Name:   MDIO_voidSetPinValue
	Input arguments: it takes 3 parameters 1-PIN NUMBER 2-PORT_NUMBER 3-PIN Value
	Return:		     it returns void
	Description: 	 this function SET The Value of pin.
*/
void MDIO_voidSetPinValue(u8 copy_u8PinId , u8 copy_u8PortId , u8 copy_u8PinValue);

/*
	Function Name:   MDIO_voidSetPinValue
	Input arguments: it takes 3 parameters 1-PIN NUMBER 2-PORT_NUMBER 3-PIN Value
	Return:		     it returns void
	Description: 	 this function SET The Value of pin.
*/
void MDIO_voidTogPinValue(u8 copy_u8PinId , u8 copy_u8PortId);

/*
	Function Name:   MDIO_u8GetPinValue
	Input arguments: it takes 2 parameters 1-PIN NUMBER 2-PORT_NUMBER
	Return:		     it returns u8 value(0 OR 1).
	Description: 	 this function Read The Value of pin.
*/
u8 MDIO_u8GetPinValue(u8 copy_u8PinId , u8 copy_u8PortId);

/*
	Function Name:   MDIO_voidSetPortMode
	Input arguments: it takes 2 parameters 1-PORT NUMBER  2-PORT Direction
	Return:		     it returns void
	Description: 	 this function determine The direction of PORT.
*/
void MDIO_voidSetPortMode(u8 copu_u8PortId , u8 copy_u8PortMode);

/*
	Function Name:   MDIO_voidSetPortValue
	Input arguments: it takes 2 parameters 1-PORT NUMBER  2-PORT Value
	Return:		     it returns void
	Description: 	 this function SET The Value of PORT.
*/
void MDIO_voidSetPortValue(u8 copy_u8PortId , u8 copy_u8PortValue);

/*
	Function Name:   MDIO_voidTogPortValue
	Input arguments: it takes 1 parameter 1-PORT NUMBER
	Return:		     it returns void
	Description: 	 this function TOG The Value of PORT.
*/
void MDIO_voidTogPortValue(u8 copy_u8PortId);

/*
	Function Name:   MDIO_u8GetPortValue
	Input arguments: it takes 1 parameters 1-PORT NUMBER  
	Return:		     it returns u8 (the value of PIN register for PORT Number passed)
	Description: 	 this function GET The Value of PORT.
*/
u8 MDIO_u8GetPortValue(u8 copy_u8PortId);

#endif /* DIO_H_ */
