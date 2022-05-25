/*************************************************************************/
/*	Author:  AbdelRahman Ra'fat Hegazy									*/
/*	Date: 	 29/4/2022													*/
/*	Version: V01														*/
/*************************************************************************/

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/***************************************************************************/
/**************************Private Registers********************************/
/**************************************************************************/

#define ADMUX_REG	*((volatile u8*)0x27)
#define ADCSRA_REG	*((volatile u8*)0x26)
#define ADCDATA_REG	*((volatile u16*)0x24)


/***************************************************************************/
/**************************Private Macros********************************/
/**************************************************************************/

/*ADC Reference Voltage*/
#define ADC_VCC				1
#define ADC_INTERNAL_REF	0
#define	ADC_EXTRNAL_VREF	3

/*ADC Result Adjust macros*/
#define	ADC_RIGHT	0
#define	ADC_LEFT	1

/*ADC Prescaler macros*/
#define DivisionFactorBy2 		0
#define DivisionFactorBy4		1
#define DivisionFactorBy8 		2
#define DivisionFactorBy16 		3
#define DivisionFactorBy32		4
#define DivisionFactorBy64  	5
#define DivisionFactorBy128		6

/*ADMUX Register bits*/
#define	REFS1	7
#define	REFS0	6
#define ADLAR	5
#define	MUX4	4
#define	MUX3	3
#define MUX2	2
#define MUX1	1
#define MUX0	0

/*ADCSRA Register bits*/
#define	ADEN	7
#define	ADSC	6
#define ADATE	5
#define	ADIF	4
#define	ADIE	3
#define ADPS2	2
#define ADPS1	1
#define ADPS0	0

#endif