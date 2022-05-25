/*************************************************************************/
/*	Author:  AbdelRahman Ra'fat Hegazy									*/
/*	Date: 	 29/4/2022													*/
/*	Version: V01														*/
/*************************************************************************/

#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/*Select ADC Voltage Reference
 * Range: ADC_VCC / ADC_INTRNAL_VREF / ADC_EXTRNAL_VREF*/
#define ADC_VREF	ADC_VCC

/*Select ADC Adjust Result
 * Range: ADC_RIGHT / ADC_LEFT*/
#define ADC_ADJUST	ADC_RIGHT

/*Select ADC Prescallar
 * Range: DivisionFactorBy2 / DivisionFactorBy4/ DivisionFactorBy8 / DivisionFactorBy16 / DivisionFactorBy32
 * 		  DivisionFactorBy64 / DivisionFactorBy128*/
#define	ADC_PRESCALER	DivisionFactorBy128

#endif 
