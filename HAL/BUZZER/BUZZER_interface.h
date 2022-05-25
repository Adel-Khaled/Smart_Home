/*************************************************************************/
/*	Author:  AbdelRahman Ra'fat Hegazy									*/
/*	Date: 	 29/4/2022													*/
/*	Version: V01														*/
/*************************************************************************/

#ifndef BUZZER_INTERFACE_H
#define BUZZER_INTERFACE_H

/*
	Function Name:   HBUZ_voidInit
	Input arguments: it takes No parameters (pin connected to BUZ ,port connected to BUZ)
	Return:		     it returns void 
	Description: 	 this function is used to Intial Buzzer as an output.
*/
void HBUZ_voidInit(u8 copy_u8BuzPin,u8 copy_u8BuzPort);

/*
	Function Name:   HBUZ_voidOn
	Input arguments: it takes No parameters (pin connected to BUZ ,port connected to BUZ)
	Return:		     it returns void 
	Description: 	 this function is used to Turn Buzzer on
*/
void HBUZ_voidOn(u8 copy_u8BuzPin,u8 copy_u8BuzPort);

/*
	Function Name:   HBUZ_voidOff
	Input arguments: it takes No parameters (pin connected to BUZ ,port connected to BUZ)
	Return:		     it returns void 
	Description: 	 this function is used to Turn Buzzer off
*/
void HBUZ_voidOff(u8 copy_u8BuzPin,u8 copy_u8BuzPort);

/*
	Function Name:   HBUZ_voidToggle
	Input arguments: it takes No parameters (pin connected to BUZ ,port connected to BUZ)
	Return:		     it returns void 
	Description: 	 this function is used to Toggle Buzzer
*/
void HBUZ_voidToggle(u8 copy_u8BuzPin,u8 copy_u8BuzPort);

/*
	Function Name:   HBUZ_voidOn
	Input arguments: it takes No parameters (pin connected to BUZ ,port connected to BUZ)
	Return:		     it returns void 
	Description: 	 this function is used to Turn Buzzer on once.
*/
void HBUZ_voidOnce(u8 copy_u8BuzPin,u8 copy_u8BuzPort);

/*
	Function Name:   HBUZ_voidTwice
	Input arguments: it takes No parameters (pin connected to BUZ ,port connected to BUZ)
	Return:		     it returns void 
	Description: 	 this function is used to Turn Buzzer on twice.
*/
void HBUZ_voidTwice(u8 copy_u8BuzPin,u8 copy_u8BuzPort);

/*
	Function Name:   HBUZ_voidTriple
	Input arguments: it takes No parameters (pin connected to BUZ ,port connected to BUZ)
	Return:		     it returns void 
	Description: 	 this function is used to Turn Buzzer on triple.
*/
void HBUZ_voidTriple(u8 copy_u8BuzPin,u8 copy_u8BuzPort);

/*
	Function Name:   HBUZ_voidLong
	Input arguments: it takes No parameters (pin connected to BUZ ,port connected to BUZ)
	Return:		     it returns void 
	Description: 	 this function is used to Turn Buzzer on always.
*/
void HBUZ_voidLong(u8 copy_u8BuzPin,u8 copy_u8BuzPort);

#endif 
