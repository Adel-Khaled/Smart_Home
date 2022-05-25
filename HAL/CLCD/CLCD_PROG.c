/*
 * LCD_PROG.c
 *
 *  Created on: Aug 30, 2019
 *      Author: adel1
 */

#include "../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"../../MCAL/DIO/DIO_interface.h"
#include"CLCD_Private.h"
#include"CLCD_config.h"
#include"CLCD_INT.h"
#include"util/delay.h"


void CLCD_VoidInitial(){

#if CLCD_MODE == CLCD_MODE_8_BIT
	_delay_ms(35); // Wait for more than 30ms
	CLCD_VoidSendCmd(0b00111000);//8 bit , N = 1 for *2 lines* ,F = 0 for *5x7*
	_delay_ms(1);
	CLCD_VoidSendCmd(0b00001100);//D= 1 for *display on* ,C=0 for *cursor off* ,B=0 for *blink off*
	_delay_ms(1);
	CLCD_VoidSendCmd(0b00000001);//clear
	_delay_ms(2);
	//LCD_VoidSendCmd(0b00000110);//mode set
	//_delay_ms(1);

#elif CLCD_MODE == CLCD_MODE_4_BIT
	/*
	_delay_ms(35); // Wait for more than 30ms
	MDIO_voidSetPinValue(CLCD_E,CLCD_CTRL_PORT,DIO_LOW);
	MDIO_voidSetPinValue(CLCD_RS,CLCD_CTRL_PORT,DIO_LOW); // Set RS to Low for command
	MDIO_voidSetPinValue(CLCD_RW,CLCD_CTRL_PORT,DIO_LOW); // Set RW pin to Low for write
	MDIO_voidSetPinValue(CLCD_DATA_PORT,CLCD_4_BIT_MODE_PIN0,DIO_LOW);        // Send command
	MDIO_voidSetPinValue(CLCD_DATA_PORT,CLCD_4_BIT_MODE_PIN1,DIO_HIGH);        // Send command
	MDIO_voidSetPinValue(CLCD_DATA_PORT,CLCD_4_BIT_MODE_PIN2,DIO_LOW);        // Send command
	MDIO_voidSetPinValue(CLCD_DATA_PORT,CLCD_4_BIT_MODE_PIN3,DIO_LOW);        // Send command
	MDIO_voidSetPinValue(CLCD_E,CLCD_CTRL_PORT,DIO_HIGH); // Send enable pulse
	_delay_ms(1);
	MDIO_voidSetPinValue(CLCD_E,CLCD_CTRL_PORT,DIO_LOW);

	CLCD_VoidSendCmd(0b00101000);//8 bit , N = 1 for *2 lines* ,F = 0 for *5x7*
	_delay_ms(1);
	CLCD_VoidSendCmd(0b00001100);//D= 1 for *display on* ,C=0 for *cursor off* ,B=0 for *blink off*
	_delay_ms(1);
	CLCD_VoidSendCmd(0b00000001);//clear
	_delay_ms(2);
	//LCD_VoidSendCmd(0b00000110);//mode set
	//_delay_ms(1);*/
	CLCD_VoidSendCmd(0x3);
	CLCD_VoidSendCmd(0x2);
	CLCD_VoidSendCmd(0x08);
	CLCD_VoidSendCmd(0x28);
	CLCD_VoidSendCmd(0x01);
	//CLCD_VoidSendCmd(0x0c);
	_delay_ms(20);


#endif
}
void CLCD_Clear(){
	CLCD_VoidSendCmd(0b00000001);//clear
	_delay_ms(2);
}
void CLCD_VoidSendCmd(u8 Copy_u8cmd){

#if CLCD_MODE == CLCD_MODE_8_BIT

	MDIO_voidSetPinValue(CLCD_E,CLCD_CTRL_PORT,DIO_LOW);
	MDIO_voidSetPinValue(CLCD_RS,CLCD_CTRL_PORT,DIO_LOW); // Set RS to Low for command
	MDIO_voidSetPinValue(CLCD_RW,CLCD_CTRL_PORT,DIO_LOW); // Set RW pin to Low for write
	MDIO_voidSetPortValue(CLCD_DATA_PORT,Copy_u8cmd);        // Send command
	MDIO_voidSetPinValue(CLCD_E,CLCD_CTRL_PORT,DIO_HIGH); // Send enable pulse
	_delay_ms(1);
	MDIO_voidSetPinValue(CLCD_E,CLCD_CTRL_PORT,DIO_LOW);
#elif CLCD_MODE == CLCD_MODE_4_BIT

	//MDIO_voidSetPinValue(CLCD_E,CLCD_CTRL_PORT,DIO_LOW);
	MDIO_voidSetPinValue(CLCD_RS,CLCD_CTRL_PORT,DIO_LOW); // Set RS to Low for command
	//MDIO_voidSetPinValue(CLCD_RW,CLCD_CTRL_PORT,DIO_LOW); // Set RW pin to Low for write

	//MDIO_voidSetPortValue(CLCD_DATA_PORT,Copy_u8cmd);        // Send command

	MDIO_voidSetPinValue(CLCD_4_BIT_MODE_PIN0, CLCD_DATA_PORT, GET_BIT(Copy_u8cmd,4));
	MDIO_voidSetPinValue(CLCD_4_BIT_MODE_PIN1, CLCD_DATA_PORT, GET_BIT(Copy_u8cmd,5));
	MDIO_voidSetPinValue(CLCD_4_BIT_MODE_PIN2, CLCD_DATA_PORT, GET_BIT(Copy_u8cmd,6));
	MDIO_voidSetPinValue(CLCD_4_BIT_MODE_PIN3, CLCD_DATA_PORT, GET_BIT(Copy_u8cmd,7));

	MDIO_voidSetPinValue(CLCD_E,CLCD_CTRL_PORT,DIO_HIGH); // Send enable pulse
	_delay_ms(1);
	MDIO_voidSetPinValue(CLCD_E,CLCD_CTRL_PORT,DIO_LOW);


	// write rest of the command
	//MDIO_voidSetPortValue(CLCD_DATA_PORT,Copy_u8cmd<<4);        // Send command

	MDIO_voidSetPinValue(CLCD_4_BIT_MODE_PIN0, CLCD_DATA_PORT, GET_BIT(Copy_u8cmd,1));
	MDIO_voidSetPinValue(CLCD_4_BIT_MODE_PIN1, CLCD_DATA_PORT, GET_BIT(Copy_u8cmd,2));
	MDIO_voidSetPinValue(CLCD_4_BIT_MODE_PIN2, CLCD_DATA_PORT, GET_BIT(Copy_u8cmd,3));
	MDIO_voidSetPinValue(CLCD_4_BIT_MODE_PIN3, CLCD_DATA_PORT, GET_BIT(Copy_u8cmd,4));

	MDIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E,DIO_HIGH); // Send enable pulse
	_delay_ms(1);
	MDIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E,DIO_LOW);

#endif
}
void CLCD_VoidWrite(u8 Copy_u8Data){
#if CLCD_MODE == CLCD_MODE_8_BIT

	MDIO_voidSetPinValue(CLCD_E,CLCD_CTRL_PORT,DIO_LOW);
	MDIO_voidSetPinValue(CLCD_RS,CLCD_CTRL_PORT,DIO_HIGH); // Set RS to High for data
	MDIO_voidSetPinValue(CLCD_RW,CLCD_CTRL_PORT,DIO_LOW);  // Set RW to low for write
	MDIO_voidSetPortValue(CLCD_DATA_PORT,Copy_u8Data);        // Send data
	MDIO_voidSetPinValue(CLCD_E,CLCD_CTRL_PORT,DIO_HIGH); // Send enable pulse
	_delay_ms(1);
	MDIO_voidSetPinValue(CLCD_E,CLCD_CTRL_PORT,DIO_LOW);

#elif CLCD_MODE == CLCD_MODE_4_BIT
	//MDIO_voidSetPinValue(CLCD_E,CLCD_CTRL_PORT,DIO_LOW);
	MDIO_voidSetPinValue(CLCD_RS,CLCD_CTRL_PORT,DIO_HIGH); // Set RS to High for data
	//MDIO_voidSetPinValue(CLCD_RW,CLCD_CTRL_PORT,DIO_LOW);  // Set RW to low for write

	//MDIO_voidSetPortValue(CLCD_DATA_PORT,Copy_u8Data);        // Send data

	MDIO_voidSetPinValue(CLCD_4_BIT_MODE_PIN0, CLCD_DATA_PORT, GET_BIT(Copy_u8Data,4));
	MDIO_voidSetPinValue(CLCD_4_BIT_MODE_PIN1, CLCD_DATA_PORT, GET_BIT(Copy_u8Data,5));
	MDIO_voidSetPinValue(CLCD_4_BIT_MODE_PIN2, CLCD_DATA_PORT, GET_BIT(Copy_u8Data,6));
	MDIO_voidSetPinValue(CLCD_4_BIT_MODE_PIN3, CLCD_DATA_PORT, GET_BIT(Copy_u8Data,7));

	MDIO_voidSetPinValue(CLCD_E,CLCD_CTRL_PORT,DIO_HIGH); // Send enable pulse
	_delay_ms(1);
	MDIO_voidSetPinValue(CLCD_E,CLCD_CTRL_PORT,DIO_LOW);

	// Write the rest of data
	//MDIO_voidSetPortValue(CLCD_DATA_PORT,Copy_u8Data<<4);        // Send data

	MDIO_voidSetPinValue(CLCD_4_BIT_MODE_PIN0, CLCD_DATA_PORT, GET_BIT(Copy_u8Data,1));
	MDIO_voidSetPinValue(CLCD_4_BIT_MODE_PIN1, CLCD_DATA_PORT, GET_BIT(Copy_u8Data,2));
	MDIO_voidSetPinValue(CLCD_4_BIT_MODE_PIN2, CLCD_DATA_PORT, GET_BIT(Copy_u8Data,3));
	MDIO_voidSetPinValue(CLCD_4_BIT_MODE_PIN3, CLCD_DATA_PORT, GET_BIT(Copy_u8Data,4));

	MDIO_voidSetPinValue(CLCD_E,CLCD_CTRL_PORT,DIO_HIGH); // Send enable pulse
	_delay_ms(1);
	MDIO_voidSetPinValue(CLCD_E,CLCD_CTRL_PORT,DIO_LOW);
#endif
}
void CLCD_WriteString(u8 *Copy_u8data){
	u8 i=0;
	while(Copy_u8data[i] != '\0'){
		CLCD_VoidWrite(Copy_u8data[i]);
		i++;
	}
}
void CLCD_VoidGoToXY(u8 Copy_u8X,u8 Copy_u8Y){
	u8 pos=0;
	if(Copy_u8Y==0)
	{
		pos=128+Copy_u8X; // 0b01000000 + x
	}
	else if(Copy_u8Y==1){
		pos=128+0x40+Copy_u8X;
	}
	//Send the address for DDRAM with set bit 7 =1
	CLCD_VoidSendCmd(pos);
}
void CLCD_VoidWriteSpecialCharacter(u8 *Copy_pPattern,u8 blockNo,u8 Copy_u8X,u8 Copy_u8Y){
	u8 address = blockNo*8+0x40;
	CLCD_VoidSendCmd(address);
	for(u8 i=0;i<8;i++){
		CLCD_VoidWrite(Copy_pPattern[i]);
	}
	CLCD_VoidGoToXY(Copy_u8X,Copy_u8Y);
	CLCD_VoidWrite(blockNo);
}
void CLCD_WriteNumber(u32 Copy_u32num){

	u8 digit1,digit2,digit3,digit4,digit5,digit6;

	digit1=Copy_u32num/100000;
	Copy_u32num=Copy_u32num%100000;

	digit2=Copy_u32num/10000;
	Copy_u32num=Copy_u32num%10000;

	digit3=Copy_u32num/1000;
	Copy_u32num=Copy_u32num%1000;

	digit4=Copy_u32num/100;
	Copy_u32num=Copy_u32num%100;

	digit5=Copy_u32num/10;
	Copy_u32num=Copy_u32num%10;

	digit6=Copy_u32num/1;
	Copy_u32num=Copy_u32num%1;

	if(digit1==0 && digit2==0 && digit3==0 && digit4==0 && digit5==0){
		CLCD_VoidWrite(digit6+48);
	}
	else if(digit1==0 && digit2==0 && digit3==0 && digit4==0){
		CLCD_VoidWrite(digit5+48);
		CLCD_VoidWrite(digit6+48);
	}
	else if(digit1==0 && digit2==0 && digit3==0){
		CLCD_VoidWrite(digit4+48);
		CLCD_VoidWrite(digit5+48);
		CLCD_VoidWrite(digit6+48);
	}
	else if(digit1==0 && digit2==0){
		CLCD_VoidWrite(digit3+48);
		CLCD_VoidWrite(digit4+48);
		CLCD_VoidWrite(digit5+48);
		CLCD_VoidWrite(digit6+48);
	}
	else if(digit1==0){
		CLCD_VoidWrite(digit2+48);
		CLCD_VoidWrite(digit3+48);
		CLCD_VoidWrite(digit4+48);
		CLCD_VoidWrite(digit5+48);
		CLCD_VoidWrite(digit6+48);
		}
	else if(digit1>0){
		CLCD_VoidWrite(digit1+48);
		CLCD_VoidWrite(digit2+48);
		CLCD_VoidWrite(digit3+48);
		CLCD_VoidWrite(digit4+48);
		CLCD_VoidWrite(digit5+48);
		CLCD_VoidWrite(digit6+48);
			}
}
