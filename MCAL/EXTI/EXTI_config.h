/*
 * EXTI_config.h
 *
 *  Created on: May 14, 2022
 *      Author: Adel Khaled
 */

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*Choose INT0 and INT1 Sense control(interrupt trigger)
 * Options:		1- LOW_LEVEL
 * 				2- ON_CHANGE
 * 				3- FALLING_EDGE
 * 				4- RISING_EDGE
 * */
#define EXTI_INT0_SENSE				ON_CHANGE
#define EXTI_INT1_SENSE				FALLING_EDGE

//For INT2 there are just Falling edge and Rising edge
#define EXTI_INT2_SENSE				FALLING_EDGE

/*Choose INT0, INT1 and INT2 peripheral interrupt enable initial state
 * Options:		1- ENABLED
 * 				2- DISABLED
 * 									*/
#define EXTI_INT0_INITIAL_STATE		DISABLED
#define EXTI_INT1_INITIAL_STATE		ENABLED
#define EXTI_INT2_INITIAL_STATE		DISABLED

#endif
