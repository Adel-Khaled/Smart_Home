/*
 * EXTI_INT.h
 *
 *  Created on: May 14, 2022
 *      Author: Adel Khaled
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI_INT0		0
#define EXTI_INT1		1
#define EXTI_INT2		2

#define LOW_LEVEL			1
#define ON_CHANGE			2
#define FALLING_EDGE		3
#define RISING_EDGE			4

void EXTI_voidINT0Init();
void EXTI_voidINT1Init();
void EXTI_voidINT2Init();

/*Description: Change sense control of the require Interrupt
 * Inputs:	1- EXTI_u8Number : the required interrupt number to change sense control
 * 				Options: 1- EXTI_INT0
 * 						 2- EXTI_INT1
 * 						 3- EXTI_INT2
 * 			2- EXTI_u8Sense: The required sense control for the external interrupt
 * 				Options: 1- LOW_LEVEL
 * 				         2- ON_CHANGE
 * 				         3- FALLING_EDGE
 * 				         4- RISING_EDGE
 *
 **/
void EXTI_u8SetSenseControl(u8 EXTI_u8Number, u8 EXTI_u8Sense);

void EXTI_u8EnableInterrupt(u8 EXTI_u8Number);
void EXTI_u8DisableInterrupt(u8 EXTI_u8Number);

void EXTI_u8INTSetCallBack(void (*Copy_pvCallBackFunc)(void), u8 EXTI_u8Number);

#endif
