/*************************************************************************/
/*	Author:  AbdelRahman Ra'fat Hegazy									*/
/*	Date: 	 29/4/2022													*/
/*	Version: V01														*/
/*************************************************************************/

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"

#include"../../MCAL/DIO/DIO_interface.h"
#include"../../MCAL/DIO/DIO_private.h"

#include "avr/interrupt.h"

#include "TIMER1_config.h"
#include "TIMER1_interface.h"
#include "TIMER1_private.h"

u32 num_of_cm_timer1 = 0;
static u32  num_of_ovf = 0;
static u32  total_ticks = 0;
void (*TIMER1_CALL_BACK)(void);

void TIMER1_voidInit(void)
{
	//to select CTC mode
	CLR_BIT(TCCR1A_REG,WGM10);
	CLR_BIT(TCCR1A_REG,WGM11);
	SET_BIT(TCCR1B_REG,WGM12);
	CLR_BIT(TCCR1B_REG,WGM13);
	
	//to select non-inverted mode
	CLR_BIT(TCCR1A_REG,COM1A0);
	SET_BIT(TCCR1A_REG,COM1A1);
	
	//enable ctc interrupt
	SET_BIT(TIMSK_REG,OCIE1A); 
	//to enable Global Interrupt
	SET_BIT(SREG_REG,GIE);	
}


void TIMER1_voidSetTime(u32 copy_u32DesiredTime)
{
	u32 tick_time = (TIMER1_PRESCALAR/CRYSTAL_FREQ);
	total_ticks   = ((copy_u32DesiredTime*1000)/tick_time);
	u16 ocr_value = 0xFFFF ;
	while(total_ticks%ocr_value != 0)
	{
		ocr_value--;
	}
	num_of_cm_timer1 = total_ticks/ocr_value;
	OCRA1_REG = ocr_value - 1;
}

void TIMER1_voidStart(void)
{
	SET_BIT(TCCR1B_REG,CS10);
	CLR_BIT(TCCR1B_REG,CS11);
	SET_BIT(TCCR1B_REG,CS12);
}

void TIMER1_voidStop(void)
{
	CLR_BIT(TCCR1B_REG,CS10);
	CLR_BIT(TCCR1B_REG,CS11);
	CLR_BIT(TCCR1B_REG,CS12);
}

void PWM1_voidInit(void)
{
	SET_BIT(DDRD_REG,5);
	//to select fast pwm mode
	CLR_BIT(TCCR1A_REG,WGM10);
	SET_BIT(TCCR1A_REG,WGM11);
	SET_BIT(TCCR1B_REG,WGM11);
	SET_BIT(TCCR1B_REG,WGM11);
	
	//to select non-inverted mode
	CLR_BIT(TCCR1A_REG,COM1A0);
	SET_BIT(TCCR1A_REG,COM1A1);
}

void PWM1_voidSetDutyCycle(u32 copy_u32DutyCycle)
{
	OCRA1_REG =(((312*(u32)copy_u32DutyCycle)/100)-1);
}

void PWM1_voidSetFrequency(u32 copy_u32frq)
{
	ICR1_REG = ((CRYSTAL_FREQ*1000000)/TIMER1_PRESCALAR)*copy_u32frq;
}

void PWM1_voidStart(void)
{
	SET_BIT(TCCR1B_REG,CS10);
	CLR_BIT(TCCR1B_REG,CS11);
	SET_BIT(TCCR1B_REG,CS12);	
}

void PWM1_voidStop(void)
{
	CLR_BIT(TCCR1B_REG,CS10);
	CLR_BIT(TCCR1B_REG,CS11);
	CLR_BIT(TCCR1B_REG,CS12);
}


void TIMER1_voidSetCallBack(void(*ptr)(void))
{
	TIMER1_CALL_BACK = ptr ;
}

ISR(TIMER1_COMPA_vect)
{
	static u32 counter = 0;
	counter++;
	if(counter == num_of_cm_timer1)
	{
		TIMER1_CALL_BACK();
		counter = 0;
	}
}
