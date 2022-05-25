/*************************************************************************/
/*	Author:  AbdelRahman Ra'fat Hegazy									*/
/*	Date: 	 29/4/2022													*/
/*	Version: V01														*/
/*************************************************************************/

/*Includes*/

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"


#include "DIO_interface.h"
#include "DIO_private.h"



void MDIO_voidSetPinMode(u8 copy_u8PinId , u8 copy_u8PortId , u8 copy_u8PinMode)
{
	/*check that PinId and PortId are in Range*/
	if(copy_u8PinId <= DIO_PIN7 && copy_u8PortId <= DIO_PORTD)
	{
		/*Direction Mode of Pin is OUTPUT*/
		if(copy_u8PinMode == DIO_OUTPUT)
		{
			/*Switch on PortId*/
			switch(copy_u8PortId)
			{
			/*case PORTA set the bit number PinId in DDRA register */
			case DIO_PORTA:	SET_BIT(DDRA_REG,copy_u8PinId);break;
			/*case PORTB set the bit number PinId in DDRB register */
			case DIO_PORTB:	SET_BIT(DDRB_REG,copy_u8PinId);break;
			/*case PORTC set the bit number PinId in DDRC register */
			case DIO_PORTC:	SET_BIT(DDRC_REG,copy_u8PinId);break;
			/*case PORTD set the bit number PinId in DDRD register */
			case DIO_PORTD:	SET_BIT(DDRD_REG,copy_u8PinId);break;
			}
		}
		/*Direction Mode of Pin is INPUT*/
		else if(copy_u8PinMode == DIO_INPUT)
		{
			/*Switch on PortId*/
			switch(copy_u8PortId)
			{
			/*case PORTA Clear the bit number PinId in DDRA register */
			case DIO_PORTA:	CLR_BIT(DDRA_REG,copy_u8PinId);break;
			/*case PORTB Clear the bit number PinId in DDRB register */
			case DIO_PORTB:	CLR_BIT(DDRB_REG,copy_u8PinId);break;
			/*case PORTC Clear the bit number PinId in DDRC register */
			case DIO_PORTC:	CLR_BIT(DDRC_REG,copy_u8PinId);break;
			/*case PORTD Clear the bit number PinId in DDRD register */
			case DIO_PORTD:	CLR_BIT(DDRD_REG,copy_u8PinId);break;
			}
		}
		else
		{
			//report error massage
		}
	}
	else
	{
		//report error massage
	}
	
}


void MDIO_voidSetPinValue(u8 copy_u8PinId , u8 copy_u8PortId , u8 copy_u8PinValue)
{
	/*check that PinId and PortId are in Range*/
	if(copy_u8PinId <= DIO_PIN7 && copy_u8PortId <= DIO_PORTD)
	{
		/*Value is HIGH*/
		if(copy_u8PinValue == DIO_HIGH)
		{
			/*Switch on PortId*/
			switch(copy_u8PortId)
			{
			/*case PORTA SET the bit number PinId in PORTA register */
			case DIO_PORTA:	SET_BIT(PORTA_REG,copy_u8PinId);break;
			/*case PORTB SET the bit number PinId in PORTB register */
			case DIO_PORTB:	SET_BIT(PORTB_REG,copy_u8PinId);break;
			/*case PORTC SET the bit number PinId in PORTC register */
			case DIO_PORTC:	SET_BIT(PORTC_REG,copy_u8PinId);break;
			/*case PORTD SET the bit number PinId in PORTD register */
			case DIO_PORTD:	SET_BIT(PORTD_REG,copy_u8PinId);break;
			}
		}
		/*Value is LOW*/
		else if(copy_u8PinValue == DIO_LOW)
		{
			/*Switch on PortId*/
			switch(copy_u8PortId)
			{
			/*case PORTA Clear the bit number PinId in PORTA register */
			case DIO_PORTA:	CLR_BIT(PORTA_REG,copy_u8PinId);break;
			/*case PORTB Clear the bit number PinId in PORTB register */
			case DIO_PORTB:	CLR_BIT(PORTB_REG,copy_u8PinId);break;
			/*case PORTC Clear the bit number PinId in PORTC register */
			case DIO_PORTC:	CLR_BIT(PORTC_REG,copy_u8PinId);break;
			/*case PORTD Clear the bit number PinId in PORTD register */
			case DIO_PORTD:	CLR_BIT(PORTD_REG,copy_u8PinId);break;
			}
		}
		else
		{
			//report error massage
		}
	}
	else
	{
		//report error massage
	}	
}

void MDIO_voidTogPinValue(u8 copy_u8PinId , u8 copy_u8PortId)
{
	/*check that PinId and PortId are in Range*/
	if(copy_u8PinId <= DIO_PIN7 && copy_u8PortId <= DIO_PORTD)
	{
		/*Switch on PortId*/
		switch(copy_u8PortId)
		{
		/*case PORTA Toggle the bit number PinId in PORTA register*/
		case DIO_PORTA:	TOG_BIT(PORTA_REG,copy_u8PinId);break;
		/*case PORTB Toggle the bit number PinId in PORTB register*/
		case DIO_PORTB:	TOG_BIT(PORTB_REG,copy_u8PinId);break;
		/*case PORTC Toggle the bit number PinId in PORTC register*/
		case DIO_PORTC:	TOG_BIT(PORTC_REG,copy_u8PinId);break;
		/*case PORTD Toggle the bit number PinId in PORTD register*/
		case DIO_PORTD:	TOG_BIT(PORTD_REG,copy_u8PinId);break;
		}
	}
	else
	{
		//report error massage
	}	
}

u8 MDIO_u8GetPinValue(u8 copy_u8PinId , u8 copy_u8PortId)
{
	/*8_bit variable which hold and return The Value of Pin */
	u8 Local_u8Pinvalue;
	/*check that PinId and PortId are in Range*/
	if(copy_u8PinId <= DIO_PIN7 && copy_u8PortId <= DIO_PORTD)
	{
		/*Switch on PortId*/
		switch(copy_u8PortId)
		{
		/*case PORTA Get Bit Number PinId from PINA register and assign it to Local_u8Pinvalue variable*/
		case DIO_PORTA:	Local_u8Pinvalue = GET_BIT(PINA_REG,copy_u8PinId);break;
		/*case PORTB Get Bit Number PinId from PINB register and assign it to Local_u8Pinvalue variable*/
		case DIO_PORTB:	Local_u8Pinvalue = GET_BIT(PINB_REG,copy_u8PinId);break;
		/*case PORTC Get Bit Number PinId from PINC register and assign it to Local_u8Pinvalue variable*/
		case DIO_PORTC: Local_u8Pinvalue = GET_BIT(PINC_REG,copy_u8PinId);break;
		/*case PORTD Get Bit Number PinId from PIND register and assign it to Local_u8Pinvalue variable*/
		case DIO_PORTD: Local_u8Pinvalue = GET_BIT(PIND_REG,copy_u8PinId);break;
		}
	}
	else
	{
		//report error massage
	}
	/*return the pin value*/
	return Local_u8Pinvalue;
}

void MDIO_voidSetPortMode(u8 copy_u8PortId , u8 copy_u8PortMode)
{
		/*Switch on PortId*/
		switch(copy_u8PortId)
		{
			/*case PORTA Clear DDRA register*/
			case DIO_PORTA:	ASSIGN_REG(DDRA_REG,copy_u8PortMode);break;
			/*case PORTA Clear DDRA register*/
			case DIO_PORTB:	ASSIGN_REG(DDRB_REG,copy_u8PortMode);break;
			/*case PORTA Clear DDRA register*/
			case DIO_PORTC:	ASSIGN_REG(DDRC_REG,copy_u8PortMode);break;
			/*case PORTA Clear DDRA register*/
			case DIO_PORTD: ASSIGN_REG(DDRD_REG,copy_u8PortMode);break;
		}

}

void MDIO_voidSetPortValue(u8 copy_u8PortId , u8 copy_u8PortValue)
{
		/*switch on PortId*/
		switch(copy_u8PortId)
		{
		    /*case PORTA Assign The Value to PORTA register*/
			case DIO_PORTA:	ASSIGN_REG(PORTA_REG,copy_u8PortValue);break;
			/*case PORTB Assign The Value to PORTB register*/
			case DIO_PORTB:	ASSIGN_REG(PORTB_REG,copy_u8PortValue);break;
			/*case PORTC Assign The Value to PORTC register*/
			case DIO_PORTC:	ASSIGN_REG(PORTC_REG,copy_u8PortValue);break;
			/*case PORTD Assign The Value to PORTD register*/
			case DIO_PORTD: ASSIGN_REG(PORTD_REG,copy_u8PortValue);break;
			default:break;
		}
}

void MDIO_voidTogPortValue(u8 copy_u8PortId)
{
	/*check that PortId is in Range*/
	if(copy_u8PortId <= DIO_PORTD)
	{
		/*switch on PortId*/
		switch(copy_u8PortId)
		{
		    /*case PORTA Toggle The Value In PORTA register*/
			case DIO_PORTA:	TOG_REG(PORTA_REG);break;
			/*case PORTB Toggle The Value in PORTB register*/
			case DIO_PORTB:	TOG_REG(PORTB_REG);break;
			/*case PORTC Toggle The Value in PORTC register*/
			case DIO_PORTC:	TOG_REG(PORTC_REG);break;
			/*case PORTD Toggle The Value in PORTD register*/
			case DIO_PORTD: TOG_REG(PORTD_REG);break;
		}
	}
	else
	{
		//report error massage
	}
}

u8 MDIO_u8GetPortValue(u8 copy_u8PortId)
{
	/*local variable to hold the value of PINx register*/
	u8 Local_u8PortValue;
	/*check that PortId is in Range*/
	if(copy_u8PortId <= DIO_PORTD)
	{
		/*switch on PortId*/
		switch(copy_u8PortId)
		{
		/*case PORTA Get The Value In PINA register and assign it to Local_u8Portvalue variable*/
		case DIO_PORTA:	Local_u8PortValue = GET_REG(PINA_REG);break;
		/*case PORTB Get The Value In PINB register and assign it to Local_u8Portvalue variable*/
		case DIO_PORTB:	Local_u8PortValue = GET_REG(PINB_REG);break;
		/*case PORTC Get The Value In PINC register and assign it to Local_u8Portvalue variable*/
		case DIO_PORTC: Local_u8PortValue = GET_REG(PINC_REG);break;
		/*case PORTD Get The Value In PIND register and assign it to Local_u8Portvalue variable*/
		case DIO_PORTD: Local_u8PortValue = GET_REG(PIND_REG);break;
		}
	}
	else
	{
		//report error massage
	}
	/*return the value of PINx register*/
	return Local_u8PortValue;
}
