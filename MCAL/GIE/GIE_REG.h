/*
 * GIE_REG.h
 *
 *  Created on: May 14, 2022
 *      Author: Adel Khaled
 */

#ifndef GIE_REGISTER_H_
#define GIE_REGISTER_H_


#define SREG		*((volatile u8*)0x5F)			/*Status register*/
#define SREG_I		 7								/*Global Interrupt enable bit*/

#endif
