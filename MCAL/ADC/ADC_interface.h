/*************************************************************************/
/*	Author:  AbdelRahman Ra'fat Hegazy									*/
/*	Date: 	 29/4/2022													*/
/*	Version: V01														*/
/*************************************************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

/***************************************************************************/
/**************************public Macros********************************/
/**************************************************************************/
#define ADC_CH0	0
#define ADC_CH1	1
#define ADC_CH2	2
#define ADC_CH3	3
#define ADC_CH4	4
#define ADC_CH5	5
#define ADC_CH6	6
#define ADC_CH7	7

/***************************************************************************/
/**************************public functions********************************/
/**************************************************************************/

/*
	Function Name:   ADC_voidInit
	Input arguments: it takes No parameters (void)
	Return:		     it returns void
	Description: 	 this function is used to Initialate ADC peripheral.
*/
void ADC_voidInit(void);

/*
	Function Name:   ADC_u16Read
	Input arguments: it takes 1 parameter (Pin_number That will read ADC value from it)
	Return:		     it returns u16 Reading value of ADC 
	Description: 	 this function is used to Read ADC Value.
*/
u16 ADC_u16Read(u8 copy_u8PinId);

/*
	Function Name:   ADC_voidEnabled
	Input arguments: it takes No parameter (void)
	Return:		     it returns void 
	Description: 	 this function is used to Enable ADC Peripheral.
*/
void ADC_voidEnabled(void);

/*
	Function Name:   ADC_voidDisabled
	Input arguments: it takes No parameter (void)
	Return:		     it returns void 
	Description: 	 this function is used to Disable ADC Peripheral.
*/
void ADC_voidDisabled(void);



#endif
