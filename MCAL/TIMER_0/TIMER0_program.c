/*************************************************************************/
/*	Author:  AbdelRahman Ra'fat Hegazy									*/
/*	Date: 	 29/4/2022													*/
/*	Version: V01														*/
/*************************************************************************/


#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"


#include "avr/interrupt.h"

#include "TIMER0_config.h"
#include "TIMER0_interface.h"
#include "TIMER0_private.h"


u32 num_of_cm = 0;
static u32  num_of_ovf = 0;
static u32  total_ticks = 0;
void (*TIMER0_CALL_BACK)(void);
void (*TIMER0_CALL_BACK_1)(void);
void (*TIMER0_CALL_BACK_2)(void);

void TIMER0_voidInit(void)
{
	#if TIMER0_MODE	== NORMAL_MODE
	//to select Normal Mode
	CLR_BIT(TCCR0_REG,WGM00);
	CLR_BIT(TCCR0_REG,WGM01);
	//to enable OVF Interrupt
	SET_BIT(TIMSK_REG,0);
	#elif TIMER0_MODE == CTC_MODE
	CLR_BIT(TCCR0_REG,WGM00);
	SET_BIT(TCCR0_REG,WGM01);
	//to enable CTC Interrupt
	SET_BIT(TIMSK_REG,1);
	#endif
	//to enable Global Interrupt
	SET_BIT(SREG_REG,GIE);	
}

void TIMER0_voidSetTime(u32 copy_u32DesiredTime)
{
	u32 tick_time = (TIMER0_PRESCALAR/CRYSTAL_FREQ);
	total_ticks   = ((copy_u32DesiredTime*1000)/tick_time); 
	#if TIMER0_MODE == NORMAL_MODE
	num_of_ovf = total_ticks/256;
	if(total_ticks%256 !=0)
	{
		TCNT0_REG = (256 - (total_ticks%256));
		num_of_ovf++;
	}
	#elif TIMER0_MODE == CTC_MODE
	u8 ocr_value = 255 ;
	while(total_ticks%ocr_value != 0)
	{
		ocr_value--;
	}
	num_of_cm = total_ticks/ocr_value;
	OCR0_REG = ocr_value-1;
	#endif
}

void TIMER0_voidStart(void)
{
	SET_BIT(TCCR0_REG,CS00);
	CLR_BIT(TCCR0_REG,CS01);
	SET_BIT(TCCR0_REG,CS02);
}

void TIMER0_voidStop(void)
{
	CLR_BIT(TCCR0_REG,CS00);
	CLR_BIT(TCCR0_REG,CS01);
	CLR_BIT(TCCR0_REG,CS02);
}

void PWM0_voidInit(void)
{
	//set pwm pin to be output
	//DIO_voidSetPinMode(DIO_PIN3,DIO_PORTC,OUTPUT);
	#if PWM0_MODE == FAST_PWM_MODE
	//select fast pwm mode
	SET_BIT(TCCR0_REG,WGM00);
	SET_BIT(TCCR0_REG,WGM01);
	#elif PWM0_MODE == PHASE_CORRECT_PWM_MODE
	SET_BIT(TCCR0_REG,WGM00);
	CLR_BIT(TCCR0_REG,WGM01);
	#endif
	#if COMPARE_OUTPUT_MODE == INVERTED_MODE
	//select inverted mode
	SET_BIT(TCCR0_REG,COM00);
	SET_BIT(TCCR0_REG,COM01);
	#elif COMPARE_OUTPUT_MODE == NON_INVERTED_MODE
	//select non-inverted mode
	CLR_BIT(TCCR0_REG,COM00);
	SET_BIT(TCCR0_REG,COM01);
	#endif
}

void PWM0_voidSetDutyCycle(u32 copy_u32DutyCycle)
{
	#if COMPARE_OUTPUT_MODE == INVERTED_MODE
		#if PWM0_MODE == FAST_PWM_MODE
		OCR0_REG = 255 - ((copy_u32DutyCycle*256)/100);
		#elif PWM0_MODE == PHASE_CORRECT_PWM_MODE
		OCR0_REG = 255 - ((255*copy_u32DutyCycle)/100);
		#endif
	#elif COMPARE_OUTPUT_MODE == NON_INVERTED_MODE
		#if PWM0_MODE == FAST_PWM_MODE
		OCR0_REG = (((256*copy_u32DutyCycle)/100))-1;
		#elif PWM0_MODE == PHASE_CORRECT_PWM_MODE
		OCR0_REG = (255*copy_u32DutyCycle)/100;
		#endif
	#endif
}


void PWM0_voidStart(void)
{
	TIMER0_voidStart();
}

void PWM0_voidStop(void)
{
	TIMER0_voidStop();
}


void TIMER0_voidSetCallBack(void(*ptr)(void))
{
	TIMER0_CALL_BACK = ptr ;
}

void TIMER0_voidSetCallBack_2(void(*ptr1)(void) , void(*ptr2)(void))
{
	TIMER0_CALL_BACK_1 = ptr1 ;
	TIMER0_CALL_BACK_2 = ptr2 ;
}

ISR(TIMER0_COMP_vect)
{
	static u32 counter_CTC = 0;
	counter_CTC++;
	if(counter_CTC == num_of_cm)
	{
		TIMER0_CALL_BACK();
		counter_CTC = 0;
	}
}

ISR(TIMER0_OVF_vect)
{
	static u32 counter_OVF = 0;
	counter_OVF++;
	if(counter_OVF == num_of_ovf)
	{
		TIMER0_CALL_BACK();
		counter_OVF = 0;
		TCNT0_REG = 256 - (total_ticks%256);
	}
}

