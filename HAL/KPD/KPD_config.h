/*
 * KPD_config.h
 *
 *  Created on: May 14, 2022
 *      Author: Adel Khaled
 */

#ifndef HAL_KPD_KPD_CONFIG_H_
#define HAL_KPD_KPD_CONFIG_H_

#define KPD_PORT DIO_PORTA

#define KPD_BUTTONS_VALUES   {{'1','2','3'},{'4','5','6'},{'c','d','e'}}


// OUTPUT PINS
// INITIAL HIGH
#define KPD_COLUMN_PIN0      DIO_PIN2
#define KPD_COLUMN_PIN1      DIO_PIN3
#define KPD_COLUMN_PIN2      DIO_PIN4
//#define KPD_COLUMN_PIN3      DIO_PIN3

// INPUT PINS
// PULL UP
#define KPD_ROW_PIN0         DIO_PIN5
#define KPD_ROW_PIN1         DIO_PIN6
#define KPD_ROW_PIN2         DIO_PIN7
//#define KPD_ROW_PIN3         DIO_PIN7


#endif /* HAL_KPD_KPD_CONFIG_H_ */
