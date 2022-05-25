/*************************************************************************/
/*	Author:  AbdelRahman Ra'fat Hegazy									*/
/*	Date: 	 29/4/2022													*/
/*	Version: V01														*/
/*************************************************************************/

#ifndef TIMER1_INTERFACE_H
#define TIMER1_INTERFACE_H

#define NORMAL_MODE				1
#define CTC_MODE				2
#define PHASE_CORRECT_PWM_MODE	3
#define FAST_PWM_MODE			4	

#define NON_INVERTED_MODE	0
#define INVERTED_MODE		1


/*
	Function Name:   TIMER1_voidInit
	Input arguments: it takes No parameter (void)
	Return:		     it returns void 
	Description: 	 this function is used to Initialate TIMER1 Peripheral.
*/
void TIMER1_voidInit(void);

/*
	Function Name:   TIMER1_voidSetTime
	Input arguments: it takes 1 parameter (time to interrupt)
	Return:		     it returns void 
	Description: 	 this function is used to Set counter Time.
*/
void TIMER1_voidSetTime(u32 copy_u32DesiredTime);

/*
	Function Name:   TIMER1_voidStart
	Input arguments: it takes No parameter (void)
	Return:		     it returns void 
	Description: 	 this function is used to start Timer1.
*/
void TIMER1_voidStart(void);

/*
	Function Name:   TIMER1_voidStop
	Input arguments: it takes No parameter (void)
	Return:		     it returns void 
	Description: 	 this function is used to Stop Timer1.
*/
void TIMER1_voidStop(void);

/*
	Function Name:   PWM1_voidInit
	Input arguments: it takes No parameter (void)
	Return:		     it returns void 
	Description: 	 this function is used to Initialate PWM1.
*/
void PWM1_voidInit(void);

/*
	Function Name:   PWM1_voidSetDutyCycle
	Input arguments: it takes 1 parameter (u32 Duty_Cycle)
	Return:		     it returns void 
	Description: 	 this function is used to Set Duty_Cycle for PWM1.
*/
void PWM1_voidSetDutyCycle(u32 copy_u32DutyCycle);

/*
	Function Name:   PWM1_voidStart
	Input arguments: it takes No parameter (void)
	Return:		     it returns void 
	Description: 	 this function is used to Start PWM1.
*/
void PWM1_voidStart(void);

/*
	Function Name:   PWM1_voidStop
	Input arguments: it takes No parameter (void)
	Return:		     it returns void 
	Description: 	 this function is used to Stop PWM1.
*/
void PWM1_voidStop(void);

/*
	Function Name:   TIMER1_voidSetCallBack
	Input arguments: it takes 1 parameter (pointer to void function)
	Return:		     it returns void 
	Description: 	 this function is used to call void function when Timer interrupt occur.
*/
void TIMER1_voidSetCallBack(void(*ptr)(void));

void PWM1_voidSetFrequency(u32 copy_u32frq);

#endif
