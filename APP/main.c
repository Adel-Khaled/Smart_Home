/*
 * main.c
 *
 *  Created on: May 24, 2022
 *      Author: Adel Khaled
 */

#include "../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../MCAL/DIO/DIO_config.h"
#include"../MCAL/DIO/DIO_interface.h"
#include"../MCAL/EXTI/EXTI_INT.h"
#include"../MCAL/GIE/GIE_INT.h"
#include"../HAL/CLCD/CLCD_INT.h"
//#include"../HAL/LCD/LCD_interface.h"
#include"../HAL/KPD/KPD_INT.h"
#include"util/delay.h"


static u8 Open_Flag=DIO_LOW;

void OpenSystem();

void main(void){

	u8 u8KpdOutput;            // Store Output key from KPD
	u8 passwordData[10]="";    // Array to store the password
	u8 index=0;				   // counter to move in password array
	u32 WrongCounter=2;		   // Counter number of wrong password

	// LCD Direction pins
	MDIO_voidSetPortMode(DIO_PORTC, 0xff);
	MDIO_voidSetPortMode(DIO_PORTD, 0b00000111);

	// KPD Direction pins
	MDIO_voidSetPortMode(DIO_PORTA, 0b00011100);
	MDIO_voidSetPortValue(DIO_PORTA,0b11111100);

	// EXT Interrupt Pull Up
	MDIO_voidSetPinMode(DIO_PIN3, DIO_PORTD, DIO_INPUT);
	MDIO_voidSetPinValue(DIO_PIN3, DIO_PORTD, DIO_HIGH);

	// Initialize Functions
	CLCD_VoidInitial();
	HLCD_voidInit();
	EXTI_voidINT1Init();
	GIE_voidEnableGlobal();


	while(1){

		EXTI_u8INTSetCallBack(&OpenSystem,EXTI_INT1); /* Use call Back function in Exti Interrupt 1*/

		//HLCD_voidWriteString("welcome");
		if(Open_Flag == 1){                          /* you will enter here if you press on EXTI 1  'PD3' */
			CLCD_WriteString("Welcome :)");				/* Start Open Mode */
			_delay_ms(100);
			while(WrongCounter >=0){				/*Loop Just 3 Times */
				index=0;			  				// Return the counter of array of password in beginning
				CLCD_Clear();
				CLCD_WriteString("Your Password:");
				CLCD_VoidGoToXY(1, 1);
				while(u8KpdOutput != 'e'){					/*The user should press enter to take the password*/
					if(u8KpdOutput == 'c'){					/*if the user press Clear the password*/
						CLCD_Clear();
						CLCD_WriteString("Your Password:");
						CLCD_VoidGoToXY(1, 1);
						index = 0;
					}
					if(u8KpdOutput >= '1' && u8KpdOutput <= '6'){       /*Make sure the data from 1 to 6 to display it*/
					CLCD_VoidWrite(u8KpdOutput);
					_delay_ms(10);
					CLCD_VoidGoToXY(index+1, 1);                      /* Go to the same position */
					CLCD_VoidWrite('*');							  /* 		to write *       */
					passwordData[index]= u8KpdOutput;
					index++;
					//HLCD_voidWriteChracter("Welcome");
					}

					u8KpdOutput = KPD_U8GetPressedKey();				/* Wait until user 		*/
					while(u8KpdOutput == NO_PRESSED_KEY_VALUE){			/*	press any key 		*/
						u8KpdOutput = KPD_U8GetPressedKey();
					}
				}
				passwordData[index]='\0';							 /*End the password with \0 to make sure*/
				u8KpdOutput =NO_PRESSED_KEY_VALUE;                   /* Clear the data from KPD output  */
				CLCD_Clear();

				if(passwordData[0]=='1' && passwordData[1]=='2' && passwordData[2]=='3' && passwordData[3]=='4'){   /*Check the pass*/
					// Display Message on LCD The Password Correct
					CLCD_WriteString("Success :) ");
					CLCD_VoidGoToXY(0, 1);
					CLCD_WriteString("System Opening....");
					_delay_ms(100);
					CLCD_Clear();
					CLCD_WriteString("Door Opened");
					_delay_ms(100);
					CLCD_Clear();
					break;
				}else{
					// Display Message on LCD The Password Wrong
					CLCD_WriteString("Wrong :( ");
					_delay_ms(100);
					CLCD_Clear();

					// Close the system when WrongCounter = 0 you don't have any chance
					if(WrongCounter == 0){
						CLCD_Clear();
						CLCD_WriteString("System Closing....");
						_delay_ms(100);
						index=0;
						break;
					}
					CLCD_WriteString("Try Again ");
					CLCD_VoidGoToXY(3, 1);
					CLCD_WriteNumber(WrongCounter);
					CLCD_WriteString(" Chance");
					_delay_ms(100);
					CLCD_Clear();
					WrongCounter--;       // decrease the counter by 1

				}
			}
			Open_Flag = 0;                // Close this mode by return the flag to 0
			WrongCounter = 2;
		}else{
			/* That is the LDR and temperature Mode
			 *     First MODE */
			CLCD_WriteString("First Mode");
			_delay_ms(50);
			CLCD_Clear();
		}

	}
}


// Function send to ISR for EXTI 1
// Change the flag to 1 to open the second mode
void OpenSystem(){
	Open_Flag = 1;
}
