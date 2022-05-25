/*************************************************************************/
/*	Author:  AbdelRahman Ra'fat Hegazy									*/
/*	Date: 	 29/4/2022													*/
/*	Version: V01														*/
/*************************************************************************/

#ifndef 	LED_INTERFACE_H
#define		LED_INTERFACE_H


/*
	Function Name:   HLED_voidInit
	Input arguments: it takes 2 parameters (Pin Id which Led connected to,port of this pin)
	Return:		     it returns void 
	Description: 	 this function is used to Initial LED.
*/
void HLED_voidInit(u8 copy_u8LedPin,u8 copy_u8LedPort);

/*
	Function Name:   HLED_voidOn
	Input arguments: it takes 2 parameters (Pin Id which Led connected to,port of this pin)
	Return:		     it returns void 
	Description: 	 this function is used to Turn LED ON.
*/
void HLED_voidOn(u8 copy_u8LedPin,u8 copy_u8LedPort);

/*
	Function Name:   HLED_voidOff
	Input arguments: it takes 2 parameters (Pin Id which Led connected to,port of this pin)
	Return:		     it returns void 
	Description: 	 this function is used to Turn LED OFF.
*/
void HLED_voidOff(u8 copy_u8LedPin,u8 copy_u8LedPort);

/*
	Function Name:   HLED_voidToggle
	Input arguments: it takes 2 parameters (Pin Id which Led connected to,port of this pin)
	Return:		     it returns void 
	Description: 	 this function is used to Toggle LED.
*/
void HLED_voidToggle(u8 copy_u8LedPin,u8 copy_u8LedPort);


#endif
