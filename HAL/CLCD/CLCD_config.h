

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

#define CLCD_DATA_PORT     DIO_PORTC
#define CLCD_CTRL_PORT     DIO_PORTD

#define CLCD_RS            DIO_PIN0
#define CLCD_RW 		   DIO_PIN1
#define CLCD_E 			   DIO_PIN2
/*
 * In Mode 4 bit Set these 4 pins
 * */

#define CLCD_4_BIT_MODE_PIN0         DIO_PIN4
#define CLCD_4_BIT_MODE_PIN1         DIO_PIN5
#define CLCD_4_BIT_MODE_PIN2         DIO_PIN6
#define CLCD_4_BIT_MODE_PIN3         DIO_PIN7



/*  	  In Mode 4 bit
 * 	Must put your pins in
 * 	4 most significant bit
 * 	for any Port
 * */
/*
 * Choose from Menu:
 * 		1) CLCD_MODE_8_BIT
 * 		2) CLCD_MODE_4_BIT
 * */

#define CLCD_MODE   CLCD_MODE_8_BIT
#endif
