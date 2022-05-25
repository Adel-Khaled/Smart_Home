/*************************************************************************/
/*	Author:  AbdelRahman Ra'fat Hegazy									*/
/*	Date: 	 29/4/2022													*/
/*	Version: V01														*/
/*************************************************************************/

#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

/*************************************************************************************************/
/**************************************Private Macros*********************************************/
/*************************************************************************************************/

/* DIO Registers Definitions*/

/*	(0x3B) is the address of PORTA register this register is 8bit
	so, it can be accessed by pointer u8*,but i want access the value at register Not the address
	so, I made PORT_REG a pointer to point to pointer that points to register address
*/
#define PORTA_REG	*((volatile u8*)0x3B)
#define DDRA_REG	*((volatile u8*)0x3A)
#define PINA_REG	*((volatile u8*)0x39)

#define PORTB_REG	*((volatile u8*)0x38)
#define DDRB_REG	*((volatile u8*)0x37)
#define PINB_REG	*((volatile u8*)0x36)

#define PORTC_REG	*((volatile u8*)0x35)
#define DDRC_REG	*((volatile u8*)0x34)
#define PINC_REG	*((volatile u8*)0x33)

#define PORTD_REG	*((volatile u8*)0x32)
#define DDRD_REG	*((volatile u8*)0x31)
#define PIND_REG	*((volatile u8*)0x30)

#endif /* DIO_REGISTERS_H_ */
