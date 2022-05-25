/*************************************************************************/
/*	Author:  AbdelRahman Ra'fat Hegazy									*/
/*	Date: 	 29/4/2022													*/
/*	Version: V01														*/
/*************************************************************************/


/*LIB Includes*/
#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"

/*MCAL Includes*/
#define F_CPU 8000000UL
#include<util/delay.h>
#include"../MCAL/DIO/DIO_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/GIE/GIE_INT.h"
#include "../MCAL/EXTI/EXTI_INT.h"
#include "../MCAL/TIMER_0/TIMER0_interface.h"
#include "../MCAL/TIMER_1/TIMER1_interface.h"

/*HAL Includes*/
#include "../HAL/LED/LED_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/KPD/KPD_INT.h"
#include "../HAL/BUZZER/BUZZER_interface.h"
#include "../HAL/SERVO/SERVO.h"




u8 u8KpdOutput;            // Store Output key from KPD
u8 passwordData[10]="";    // Array to store the password
u8 index=0;				   // counter to move in password array
u32 WrongCounter=2;		   // Counter number of wrong password

void OpenSystem(void);
void LDR_On_LCD(void);
void TempSensor(void);

int main(void)
{
	/*BUZZER Initialization*/
	HBUZ_voidInit(DIO_PIN6,DIO_PORTD);
	/*LCD Initialization and welcome board*/
	HLCD_voidInit();
	HLCD_voidGoTo(0,5);
	HLCD_voidWriteString("WELCOME");
	HLCD_voidGoTo(1,4);
	HLCD_voidWriteString("SMART  HOME");

	/*LEDS Initialization */
	HLED_voidInit(DIO_PIN0,DIO_PORTB);
	HLED_voidInit(DIO_PIN1,DIO_PORTB);
	HLED_voidInit(DIO_PIN2,DIO_PORTB);
	HLED_voidInit(DIO_PIN3,DIO_PORTB);
	HLED_voidInit(DIO_PIN4,DIO_PORTB);
	HLED_voidInit(DIO_PIN5,DIO_PORTB);
	HLED_voidInit(DIO_PIN6,DIO_PORTB);
	HLED_voidInit(DIO_PIN7,DIO_PORTB);
	/*MOTOR PIN Initialization*/
	MDIO_voidSetPinMode(DIO_PIN7,DIO_PORTD,DIO_OUTPUT);

	/*ADC Initialization*/
	MDIO_voidSetPinMode(DIO_PIN0,DIO_PORTA,DIO_INPUT);
	MDIO_voidSetPinMode(DIO_PIN1,DIO_PORTA,DIO_INPUT);
	ADC_voidInit();
	/*TIMER0 Initialization*/
	TIMER0_voidInit();
	TIMER0_voidSetTime(1000);
	TIMER0_voidStart();
	TIMER0_voidSetCallBack(&TempSensor);

	// KPD Direction pins
	MDIO_voidSetPortMode(DIO_PORTA, 0b00011100);
	MDIO_voidSetPortValue(DIO_PORTA,0b11111100);

	// EXT Interrupt Pull Up
	MDIO_voidSetPinMode(DIO_PIN3, DIO_PORTD, DIO_INPUT);
	MDIO_voidSetPinValue(DIO_PIN3, DIO_PORTD, DIO_HIGH);

	MDIO_voidSetPinMode(DIO_PIN5,DIO_PORTD,DIO_OUTPUT);


	EXTI_voidINT1Init();
	GIE_voidEnableGlobal();

	EXTI_u8INTSetCallBack(&OpenSystem,EXTI_INT1); /* Use call Back function in Exti Interrupt 1*/

	while(1)
	{

	}

	return 0;
}


void TempSensor(void)
{
	HLCD_voidClear();
	HLCD_voidGoTo(0,0);
	HLCD_voidWriteString("TEMP:");

	u16 Local_u16Temp = ADC_u16Read(0);
	Local_u16Temp = Local_u16Temp*(5000/1024.0);
	HLCD_voidWriteIntNumber((Local_u16Temp/10));
	HLCD_voidWriteChracter('C');
	if( (Local_u16Temp/10) > 25)
	{
		HLCD_voidGoTo(0,9);
		HLCD_voidWriteString("Fan:ON");
		MDIO_voidSetPinValue(DIO_PIN7,DIO_PORTD,DIO_HIGH);
	}
	else
	{
		HLCD_voidGoTo(0,9);
		HLCD_voidWriteString("Fan:OFF");
		MDIO_voidSetPinValue(DIO_PIN7,DIO_PORTD,DIO_LOW);
	}
	if((Local_u16Temp/10) > 40)
	{
		HBUZ_voidToggle(DIO_PIN6,DIO_PORTD);
	}
	LDR_On_LCD();

}

void LDR_On_LCD(void)
{

	HLCD_voidGoTo(1,0);
	HLCD_voidWriteString("Bright:");

	u16 Local_u16Ldr = ADC_u16Read(1);
	HLCD_voidWriteIntNumber((100*Local_u16Ldr)/1024);
	HLCD_voidWriteChracter('%');
	if(Local_u16Ldr >= 0 && Local_u16Ldr < 100)
	{
		HLCD_voidGoTo(1,11);
		HLCD_voidWriteString("LEDS:");
		HLCD_voidWriteIntNumber(8);
		HLED_voidOn(DIO_PIN0,DIO_PORTB);
		HLED_voidOn(DIO_PIN1,DIO_PORTB);
		HLED_voidOn(DIO_PIN2,DIO_PORTB);
		HLED_voidOn(DIO_PIN3,DIO_PORTB);
		HLED_voidOn(DIO_PIN4,DIO_PORTB);
		HLED_voidOn(DIO_PIN5,DIO_PORTB);
		HLED_voidOn(DIO_PIN6,DIO_PORTB);
		HLED_voidOn(DIO_PIN7,DIO_PORTB);
	}
	else if(Local_u16Ldr >= 100 && Local_u16Ldr < 300)
	{
		HLCD_voidGoTo(1,11);
		HLCD_voidWriteString("LEDS:");
		HLCD_voidWriteIntNumber(7);
		HLED_voidOn(DIO_PIN0,DIO_PORTB);
		HLED_voidOn(DIO_PIN1,DIO_PORTB);
		HLED_voidOn(DIO_PIN2,DIO_PORTB);
		HLED_voidOn(DIO_PIN3,DIO_PORTB);
		HLED_voidOn(DIO_PIN4,DIO_PORTB);
		HLED_voidOn(DIO_PIN5,DIO_PORTB);
		HLED_voidOn(DIO_PIN6,DIO_PORTB);
		HLED_voidOff(DIO_PIN7,DIO_PORTB);
	}
	else if(Local_u16Ldr >= 300 && Local_u16Ldr < 500)
	{
		HLCD_voidGoTo(1,11);
		HLCD_voidWriteString("LEDS:");
		HLCD_voidWriteIntNumber(6);
		HLED_voidOn(DIO_PIN0,DIO_PORTB);
		HLED_voidOn(DIO_PIN1,DIO_PORTB);
		HLED_voidOn(DIO_PIN2,DIO_PORTB);
		HLED_voidOn(DIO_PIN3,DIO_PORTB);
		HLED_voidOn(DIO_PIN4,DIO_PORTB);
		HLED_voidOn(DIO_PIN5,DIO_PORTB);
		HLED_voidOff(DIO_PIN6,DIO_PORTB);
		HLED_voidOff(DIO_PIN7,DIO_PORTB);
	}
	else if(Local_u16Ldr >= 500 && Local_u16Ldr < 700)
	{
		HLCD_voidGoTo(1,11);
		HLCD_voidWriteString("LEDS:");
		HLCD_voidWriteIntNumber(5);
		HLED_voidOn(DIO_PIN0,DIO_PORTB);
		HLED_voidOn(DIO_PIN1,DIO_PORTB);
		HLED_voidOn(DIO_PIN2,DIO_PORTB);
		HLED_voidOn(DIO_PIN3,DIO_PORTB);
		HLED_voidOn(DIO_PIN4,DIO_PORTB);
		HLED_voidOff(DIO_PIN5,DIO_PORTB);
		HLED_voidOff(DIO_PIN6,DIO_PORTB);
		HLED_voidOff(DIO_PIN7,DIO_PORTB);
	}
	else if(Local_u16Ldr >= 700 && Local_u16Ldr < 900)
	{
		HLCD_voidGoTo(1,11);
		HLCD_voidWriteString("LEDS:");
		HLCD_voidWriteIntNumber(4);
		HLED_voidOn(DIO_PIN0,DIO_PORTB);
		HLED_voidOn(DIO_PIN1,DIO_PORTB);
		HLED_voidOn(DIO_PIN2,DIO_PORTB);
		HLED_voidOn(DIO_PIN3,DIO_PORTB);
		HLED_voidOff(DIO_PIN4,DIO_PORTB);
		HLED_voidOff(DIO_PIN5,DIO_PORTB);
		HLED_voidOff(DIO_PIN6,DIO_PORTB);
		HLED_voidOff(DIO_PIN7,DIO_PORTB);
	}
	else if(Local_u16Ldr >= 900 && Local_u16Ldr < 1024)
	{
		HLCD_voidGoTo(1,11);
		HLCD_voidWriteString("LEDS:");
		HLCD_voidWriteIntNumber(2);
		HLED_voidOn(DIO_PIN0,DIO_PORTB);
		HLED_voidOn(DIO_PIN1,DIO_PORTB);
		HLED_voidOff(DIO_PIN2,DIO_PORTB);
		HLED_voidOff(DIO_PIN3,DIO_PORTB);
		HLED_voidOff(DIO_PIN4,DIO_PORTB);
		HLED_voidOff(DIO_PIN5,DIO_PORTB);
		HLED_voidOff(DIO_PIN6,DIO_PORTB);
		HLED_voidOff(DIO_PIN7,DIO_PORTB);
	}
}



void OpenSystem()
{
	WrongCounter=2;
	HLCD_voidWriteString("Welcome :)");				/* Start Open Mode */
	_delay_ms(1000);
	while(WrongCounter >=0)		/*Loop Just 3 Times */
	{
		index=0;			  				// Return the counter of array of password in beginning
		HLCD_voidClear();
		HLCD_voidWriteString("Your Password:");
		HLCD_voidGoTo(1, 1);
		while(u8KpdOutput != 'e')	/*The user should press enter to take the password*/
		{
			if(u8KpdOutput == 'c')		/*if the user press Clear the password*/
			{
				HLCD_voidClear();
				HLCD_voidWriteString("Your Password:");
				HLCD_voidGoTo(1, 1);
				index = 0;
			}
			if(u8KpdOutput >= '1' && u8KpdOutput <= '6')	/*Make sure the data from 1 to 6 to display it*/
			{
				HLCD_voidWriteChracter(u8KpdOutput);
				_delay_ms(10);
				HLCD_voidGoTo(1,index+1);                      /* Go to the same position */
				HLCD_voidWriteChracter('*');							  /* 		to write *       */
				passwordData[index]= u8KpdOutput;
				index++;
				//HLCD_voidWriteChracter("Welcome");
			}

			u8KpdOutput = KPD_U8GetPressedKey();				/* Wait until user 		*/
			while(u8KpdOutput == NO_PRESSED_KEY_VALUE)			/*	press any key 		*/
			{
				u8KpdOutput = KPD_U8GetPressedKey();
			}
			HBUZ_voidOnce(DIO_PIN6,DIO_PORTD);
		}
		passwordData[index]='\0';							 /*End the password with \0 to make sure*/
		u8KpdOutput =NO_PRESSED_KEY_VALUE;                   /* Clear the data from KPD output  */
		HLCD_voidClear();
		/*Check the pass*/
		if(passwordData[0]=='1' && passwordData[1]=='2' && passwordData[2]=='3' && passwordData[3]=='4')
		{
			// Display Message on LCD The Password Correct
			HLCD_voidWriteString("Success :) ");
			HLCD_voidGoTo(1, 0);
			HLCD_voidWriteString("System Opening....");
			_delay_ms(500);
			HLCD_voidClear();
			HLCD_voidWriteString("Door Opened");
			SERVO_INIT(700);
			_delay_ms(2000);
			HLCD_voidClear();
			SERVO_INIT(1600);
			HLCD_voidWriteString("Good Bye!");
			_delay_ms(2000);
			HLCD_voidClear();
			break;
		}
		else
		{
			// Display Message on LCD The Password Wrong
			HBUZ_voidTwice(DIO_PIN6,DIO_PORTD);
			HLCD_voidWriteString("Wrong :( ");
			_delay_ms(500);
			HLCD_voidClear();

			// Close the system when WrongCounter = 0 you don't have any chance
			if(WrongCounter == 0)
			{
				HLCD_voidClear();
				HLCD_voidWriteString("System Closing....");
				_delay_ms(500);
				index=0;
				break;
			}
			HLCD_voidWriteString("Try Again ");
			HLCD_voidGoTo(1, 3);
			HLCD_voidWriteIntNumber(WrongCounter);
			HLCD_voidWriteString(" Chance");
			_delay_ms(500);
			HLCD_voidClear();
			WrongCounter--;       // decrease the counter by 1
		}
	}
}
