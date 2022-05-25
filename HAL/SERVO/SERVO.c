/*
 * SERVO.c
 *
 * Created: 2/23/2022 10:53:04 AM
 *  Author: aaa
 */ 


#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"


#include "../../MCAL/TIMER_1/TIMER1_interface.h"
#include "../../MCAL/TIMER_1/TIMER1_private.h"
#include "SERVO.h"


void SERVO_INIT(u16 angle)
{
	SET_BIT(TCCR1A_REG,1);
	CLR_BIT(TCCR1A_REG,0);
	SET_BIT(TCCR1B_REG,4);
	SET_BIT(TCCR1B_REG,3);

	SET_BIT(TCCR1A_REG,7);
	CLR_BIT(TCCR1A_REG,6);

	ICR1_REG = 19999;

	OCRA1_REG = angle;

	CLR_BIT(TCCR1B_REG,2);
	SET_BIT(TCCR1B_REG,1);
	CLR_BIT(TCCR1B_REG,0);
}


void SET_SERVO_ANGLE(u16 angle)
{
	PWM1_voidSetDutyCycle(((5*angle)/180)+5);
}
void SERVO_START()
{
	PWM1_voidStart();
}

void SERVO_STOP()
{
	PWM1_voidStop();
}
