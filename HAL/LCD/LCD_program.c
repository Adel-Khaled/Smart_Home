/*************************************************************************/
/*	Author:  AbdelRahman Ra'fat Hegazy									*/
/*	Date: 	 29/4/2022													*/
/*	Version: V01														*/
/*************************************************************************/

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"

#include"../../MCAL/DIO/DIO_interface.h"

#define F_CPU 8000000UL
#include<util/delay.h>

#include "LCD_interface.h"
#include "LCD_config.h"

void HLCD_voidInit(void)
{
	MDIO_voidSetPortMode(DATA_PORT,0xFF);
	MDIO_voidSetPinMode (RS_PIN,CONTROL_PORT,DIO_OUTPUT);
	MDIO_voidSetPinMode (RW_PIN,CONTROL_PORT,DIO_OUTPUT);
	MDIO_voidSetPinMode (E_PIN ,CONTROL_PORT,DIO_OUTPUT);
	/*delay 30 ms to ensure That LCD Initialized and power on*/
	_delay_ms(30);
	#if LCD_MODE == _8Bit_Mode
	/*Function SET (8bit/2-line/5x7 dot character) and wait 1 ms*/
	HLCD_voidWriteCmd(0x38);
	_delay_ms(1);

	
	#elif LCD_MODE == _4Bit_Mode
	/*Function SET (4bit/2-line/5x7 dot character) and wait 1 ms*/
	HLCD_voidWriteCmd(0x33);
	HLCD_voidWriteCmd(0x32);
	HLCD_voidWriteCmd(0x28);
	_delay_ms(1);
	#endif

	/*Display ON/OFF Control(display on, cursor off, don't blink character) and wait 1 ms*/
	HLCD_voidWriteCmd(0x0C);
	_delay_ms(1);

	/* Clear Display and wait 2 ms*/
	HLCD_voidWriteCmd(0x01);
	_delay_ms(2);

	/* Entry Mode Set */
	HLCD_voidWriteCmd(0x06);
	_delay_ms(2);
}


void HLCD_voidWriteCmd(u8 copy_u8Cmd)
{
	/*Set RS Pin to LOW*/
	MDIO_voidSetPinValue(RS_PIN,CONTROL_PORT,DIO_LOW);
	/*Set RW Pin to LOW*/
	MDIO_voidSetPinValue(RW_PIN,CONTROL_PORT,DIO_LOW);
	#if LCD_MODE == _8Bit_Mode
	/* Load Command to Data Pins(D0....D7)*/
	MDIO_voidSetPortValue(DATA_PORT,copy_u8Cmd);
	/*Set E Pin to HIGH*/
	MDIO_voidSetPinValue(E_PIN,CONTROL_PORT,DIO_HIGH);
	/*Set E Pin to LOW*/
	MDIO_voidSetPinValue(E_PIN,CONTROL_PORT,DIO_LOW);
	/* Wait for E to settle */
	_delay_ms(5);
	#elif LCD_MODE == _4Bit_Mode
	MDIO_voidSetPinValue(D4_PIN,DATA_PORT,GET_BIT(copy_u8Cmd,4));
	MDIO_voidSetPinValue(D5_PIN,DATA_PORT,GET_BIT(copy_u8Cmd,5));
	MDIO_voidSetPinValue(D6_PIN,DATA_PORT,GET_BIT(copy_u8Cmd,6));
	MDIO_voidSetPinValue(D7_PIN,DATA_PORT,GET_BIT(copy_u8Cmd,7));

	/*Set E Pin to HIGH*/
	MDIO_voidSetPinValue(E_PIN,CONTROL_PORT,DIO_HIGH);
	/*Set E Pin to LOW*/
	MDIO_voidSetPinValue(E_PIN,CONTROL_PORT,DIO_LOW);
	/* Wait for E to settle */
	_delay_ms(5);

	MDIO_voidSetPinValue(D4_PIN,DATA_PORT,GET_BIT(copy_u8Cmd,0));
	MDIO_voidSetPinValue(D5_PIN,DATA_PORT,GET_BIT(copy_u8Cmd,1));
	MDIO_voidSetPinValue(D6_PIN,DATA_PORT,GET_BIT(copy_u8Cmd,2));
	MDIO_voidSetPinValue(D7_PIN,DATA_PORT,GET_BIT(copy_u8Cmd,3));

	/*Set E Pin to HIGH*/
	MDIO_voidSetPinValue(E_PIN,CONTROL_PORT,DIO_HIGH);
	/*Set E Pin to LOW*/
	MDIO_voidSetPinValue(E_PIN,CONTROL_PORT,DIO_LOW);
	/* Wait for E to settle */
	_delay_ms(5);
	#endif

}

void HLCD_voidWriteChracter(u8 copy_u8Chr)
{
	/*Set RS Pin to HIGH*/
	MDIO_voidSetPinValue(RS_PIN,CONTROL_PORT,DIO_HIGH);
	/*Set RW Pin to LOW*/
	MDIO_voidSetPinValue(RW_PIN,CONTROL_PORT,DIO_LOW);
	
	#if LCD_MODE == _8Bit_Mode
	/* Load DATA to Data Pins(D0....D7)*/
	MDIO_voidSetPortValue(DATA_PORT,copy_u8Chr);
	/*Set E Pin to HIGH*/
	MDIO_voidSetPinValue(E_PIN,CONTROL_PORT,DIO_HIGH);
	/*Set E Pin to LOW*/
	MDIO_voidSetPinValue(E_PIN,CONTROL_PORT,DIO_LOW);
	/* Wait for E to settle */
	_delay_ms(5);
	
	#elif LCD_MODE == _4Bit_Mode
	MDIO_voidSetPinValue(D4_PIN,DATA_PORT,GET_BIT(copy_u8Chr,4));
	MDIO_voidSetPinValue(D5_PIN,DATA_PORT,GET_BIT(copy_u8Chr,5));
	MDIO_voidSetPinValue(D6_PIN,DATA_PORT,GET_BIT(copy_u8Chr,6));
	MDIO_voidSetPinValue(D7_PIN,DATA_PORT,GET_BIT(copy_u8Chr,7));
	
	/*Set E Pin to HIGH*/
	MDIO_voidSetPinValue(E_PIN,CONTROL_PORT,DIO_HIGH);
	/*Set E Pin to LOW*/
	MDIO_voidSetPinValue(E_PIN,CONTROL_PORT,DIO_LOW);
	/* Wait for E to settle */
	_delay_ms(5);
	
	MDIO_voidSetPinValue(D4_PIN,DATA_PORT,GET_BIT(copy_u8Chr,0));
	MDIO_voidSetPinValue(D5_PIN,DATA_PORT,GET_BIT(copy_u8Chr,1));
	MDIO_voidSetPinValue(D6_PIN,DATA_PORT,GET_BIT(copy_u8Chr,2));
	MDIO_voidSetPinValue(D7_PIN,DATA_PORT,GET_BIT(copy_u8Chr,3));
	
	/*Set E Pin to HIGH*/
	MDIO_voidSetPinValue(E_PIN,CONTROL_PORT,DIO_HIGH);
	/*Set E Pin to LOW*/
	MDIO_voidSetPinValue(E_PIN,CONTROL_PORT,DIO_LOW);
	/* Wait for E to settle */
	_delay_ms(5);
	#endif
}

void HLCD_voidWriteString(u8* copy_u8PStr)
{
	u8 Local_u8Iteration=0;
	while(copy_u8PStr[Local_u8Iteration]!='\0')
	{
		HLCD_voidWriteChracter(copy_u8PStr[Local_u8Iteration++]);
	}
}

void HLCD_voidClear(void)
{
	HLCD_voidWriteCmd(0x01);
	_delay_ms(2);
}

void HLCD_voidGoTo(u8 copy_u8XLoc , u8 copy_u8YLoc)
{
	switch(copy_u8XLoc)
	{
		case 0:
			HLCD_voidWriteCmd(copy_u8YLoc+128);
			break;
		case 1:
			HLCD_voidWriteCmd(copy_u8YLoc+191);
			break;
		default:
			break;
	}
}

void HLCD_voidWriteIntNumber(s32 copy_s32Num)
{
	s8 i=0,j=0;
	u32 Local_u32Num;
	u8 base_NUM[10]={0};
	if (copy_s32Num < 0)
	{
		copy_s32Num*=-1;
		Local_u32Num = copy_s32Num;
		HLCD_voidWriteChracter('-');
	}
	else if (copy_s32Num == 0)
	{
		HLCD_voidWriteChracter(48);
	}

	while(copy_s32Num !=0)
	{
		base_NUM[i++] = copy_s32Num % 10;
		copy_s32Num/=10;
	}
	i--;
	while(i>=0)
	{
		HLCD_voidWriteChracter(base_NUM[i--]+48);
	}

}

void HLCD_voidWriteFloatNumber(f64 number)
{
	s8 i=0,j=0;
	u32 x=number;
	u8 base_NUM[10]={0};
	f64 y=0;
	if (number<0)
	{
		number*=-1;
		x=number;
		HLCD_voidWriteChracter('-');
	}
	y=(((number+1.0)-x)*10000000);
	while(x !=0)
	{
		base_NUM[i++] = x % 10;
		x/=10;
	}
	u8 k=i--;
	while(i>=0)
	{
		HLCD_voidWriteChracter(base_NUM[i--]+48);
	}
	u8 F_NUM[10]={0};
	i=0;
	u32 z=y;
	HLCD_voidWriteChracter('.');
	while(z !=0)
	{
		F_NUM[i++] = z % 10;
		z/=10;
	}
	i-=2;
	for(j=0;j<10;j++)
	{
		if(F_NUM[j]==0)
		{
			F_NUM[j]='k';
		}
		else
		{
			break;
		}
	}
	while(F_NUM[i]!='k'&& k!=7)
	{
		HLCD_voidWriteChracter(F_NUM[i--]+48);
		k++;
	}

}
