/*************************************************************************/
/*	Author:  AbdelRahman Ra'fat Hegazy									*/
/*	Date: 	 29/4/2022													*/
/*	Version: V01														*/
/*************************************************************************/

#ifndef TIMER1_PRIVATE_H
#define TIMER1_PRIVATE_H

       
//address of TCCR1A Register
#define TCCR1A_REG	*((volatile u8*)0x4F)
//TCCR1A PINS
#define  WGM10		0
#define  WGM11		1
#define  FOC1B		2
#define  FOC1A		3
#define  COM1B0		4
#define  COM1B1		5
#define  COM1A0		6
#define  COM1A1		7

#define TCCR1B_REG	*((volatile u8*)0x4E)
//TCCR1A PINS
#define  CS10		0
#define  CS11		1
#define  CS12		2
#define  WGM12		3
#define  WGM13		4
#define  ICES1		6
#define  ICNC1		7

#define OCRA1_REG	*((volatile u16*)0x4A)

#define OCRB1_REG	*((volatile u16*)0x48)

#define ICR1_REG	*((volatile u16*)0x46)


//address of SERG register
#define SREG_REG	*((volatile u8*)0x5F)	//The AVR Status Register – SREG(it has Bit No.7 as Global Interrupt Enable)
//SERG PINS
//this bit is The Global Interrupt Enable bit in SERG register
#define GIE		7

//address TIMSK register
#define TIMSK_REG	*((volatile u8*)0x59)
//TIMSK PINS   
#define TOIE1	2
#define OCIE1B	3
#define OCIE1A	4
#define TICIE1	5


#endif