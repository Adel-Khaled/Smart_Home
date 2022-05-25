/*
 * EXTI_REG.h
 *
 *  Created on: May 14, 2022
 *      Author: Adel Khaled
 */

#ifndef EXTI_REG_H_
#define EXTI_REG_H_

#define MCUCR			*((volatile u8*)0x55)		/*MCU Control register*/
#define MCUCR_ISC11		3                           /*Int1 sense control bit 1*/
#define MCUCR_ISC10		2                           /*Int1 sense control bit 0*/
#define MCUCR_ISC01		1                           /*Int0 sense control bit 1*/
#define MCUCR_ISC00		0                           /*Int0 sense control bit 0*/

#define MCUCSR			*((volatile u8*)0x54)		/*MCU Control and status register*/
#define MCUCSR_ISC2		6							/*Int2 sense control*/

#define GICR			*((volatile u8*)0x5B)		/*General interrupt control register*/
#define GICR_INT1		7		                     /*INT1 PIE*/
#define GICR_INT0		6                            /*INT0 PIE*/
#define GICR_INT2		5                            /*INT2 PIE*/

#define GIFR            *((volatile u8*)0x5A)        /*MCU Flag register*/
#define GIFR_INTF1      7                            /*INT1 PIF*/
#define GIFR_INTF0      6							 /*INT0 PIF*/
#define GIFR_INTF2      5                            /*INT2 PIF*/
#endif
