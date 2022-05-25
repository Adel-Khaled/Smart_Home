/*************************************************************************/
/*	Author:  AbdelRahman Ra'fat Hegazy									*/
/*	Date: 	 29/4/2022													*/
/*	Version: V01														*/
/*************************************************************************/

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"


#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"



void ADC_voidInit(void)
{
	/*Select ADC Reference Voltage*/
	#if    ADC_VREF == ADC_VCC
		SET_BIT(ADMUX_REG,REFS0);
		CLR_BIT(ADMUX_REG,REFS1);
	#elif  ADC_VREF == ADC_INTERNAL_REF
		SET_BIT(ADMUX_REG,REFS0);
		SET_BIT(ADMUX_REG,REFS1);
	#elif  ADC_VREF == ADC_EXTRNAL_VREF
		CLR_BIT(ADMUX_REG,REFS0);
		CLR_BIT(ADMUX_REG,REFS1);
	#endif
	
	/*Select ADC ADJUST Result*/
	#if   ADC_ADJUST == ADC_LEFT
		SET_BIT(ADMUX_REG,ADLAR);
	#elif ADC_ADJUST == ADC_RIGHT
		CLR_BIT(ADMUX_REG,ADLAR);
	#endif
	
	/*Select ADC Prescaler*/
	#if   ADC_PRESCALER == DivisionFactorBy128
		SET_BIT(ADCSRA_REG,ADPS2);
		SET_BIT(ADCSRA_REG,ADPS1);
		SET_BIT(ADCSRA_REG,ADPS0);
	#elif ADC_PRESCALER == DivisionFactorBy64
		SET_BIT(ADCSRA_REG,ADPS2);
		SET_BIT(ADCSRA_REG,ADPS1);
		CLR_BIT(ADCSRA_REG,ADPS0);
	#elif ADC_PRESCALER == DivisionFactorBy32
		SET_BIT(ADCSRA_REG,ADPS2);
		CLR_BIT(ADCSRA_REG,ADPS1);
		SET_BIT(ADCSRA_REG,ADPS0);
	#elif ADC_PRESCALER == DivisionFactorBy16
		SET_BIT(ADCSRA_REG,ADPS2);
		CLR_BIT(ADCSRA_REG,ADPS1);
		CLR_BIT(ADCSRA_REG,ADPS0);
	#elif ADC_PRESCALER == DivisionFactorBy8
		CLR_BIT(ADCSRA_REG,ADPS2);
		SET_BIT(ADCSRA_REG,ADPS1);
		SET_BIT(ADCSRA_REG,ADPS0);
	#elif ADC_PRESCALER == DivisionFactorBy4
		CLR_BIT(ADCSRA_REG,ADPS2);
		SET_BIT(ADCSRA_REG,ADPS1);
		CLR_BIT(ADCSRA_REG,ADPS0);
	#elif ADC_PRESCALER == DivisionFactorBy2
		CLR_BIT(ADCSRA_REG,ADPS2);
		CLR_BIT(ADCSRA_REG,ADPS1);
		CLR_BIT(ADCSRA_REG,ADPS0);
	#endif
	/*disable auto trigger*/
	CLR_BIT(ADCSRA_REG,ADATE);
	/*Enable ADC*/
	ADC_voidEnabled();
}

u16 ADC_u16Read(u8 copy_u8PinId)
{
	ADCDATA_REG = 0x00;
	ADMUX_REG &= 0b1110000;
	copy_u8PinId = copy_u8PinId & 0b00001111;
	/*Select ADC Channel*/
	switch(copy_u8PinId)
	{
		case ADC_CH0:CLR_BIT(ADMUX_REG,MUX0);CLR_BIT(ADMUX_REG,MUX1);CLR_BIT(ADMUX_REG,MUX2);break;//000
		case ADC_CH1:SET_BIT(ADMUX_REG,MUX0);CLR_BIT(ADMUX_REG,MUX1);CLR_BIT(ADMUX_REG,MUX2);break;//001
		case ADC_CH2:CLR_BIT(ADMUX_REG,MUX0);SET_BIT(ADMUX_REG,MUX1);CLR_BIT(ADMUX_REG,MUX2);break;//010
		case ADC_CH3:SET_BIT(ADMUX_REG,MUX0);SET_BIT(ADMUX_REG,MUX1);CLR_BIT(ADMUX_REG,MUX2);break;//011
		case ADC_CH4:CLR_BIT(ADMUX_REG,MUX0);CLR_BIT(ADMUX_REG,MUX1);SET_BIT(ADMUX_REG,MUX2);break;//100
		case ADC_CH5:SET_BIT(ADMUX_REG,MUX0);CLR_BIT(ADMUX_REG,MUX1);SET_BIT(ADMUX_REG,MUX2);break;//101
		case ADC_CH6:CLR_BIT(ADMUX_REG,MUX0);SET_BIT(ADMUX_REG,MUX1);SET_BIT(ADMUX_REG,MUX2);break;//110
		case ADC_CH7:SET_BIT(ADMUX_REG,MUX0);SET_BIT(ADMUX_REG,MUX1);SET_BIT(ADMUX_REG,MUX2);break;//111
	}
	/*Start Conversion*/
	SET_BIT(ADCSRA_REG,ADSC);
	/*Wait until the flag bit is switched to 1 (Conversion Complete)*/
	while(GET_BIT(ADCSRA_REG,ADIF) == 0);
	/*clear flag*/
	SET_BIT(ADCSRA_REG,ADIF);
	/*Return 16 bits in ADCDATA Register */
	return ADCDATA_REG;
}

void ADC_voidEnabled(void)
{
	SET_BIT(ADCSRA_REG,ADEN);
}

void ADC_voidDisabled(void)
{
	CLR_BIT(ADCSRA_REG,ADEN);
}
