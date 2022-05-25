/*************************************************************************/
/*	Author:  AbdelRahman Ra'fat Hegazy									*/
/*	Date: 	 29/4/2022													*/
/*	Version: V01														*/
/*************************************************************************/

#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#define NORMAL_MODE				1
#define CTC_MODE				2
#define PHASE_CORRECT_PWM_MODE	3
#define FAST_PWM_MODE			4	

#define NON_INVERTED_MODE	0
#define INVERTED_MODE		1


/*
	Function Name:   TIMER0_voidInit
	Input arguments: it takes No parameter (void)
	Return:		     it returns void 
	Description: 	 this function is used to Initialate TIMER0 Peripheral.
*/
void TIMER0_voidInit(void);

/*
	Function Name:   TIMER0_voidSetTime
	Input arguments: it takes 1 parameter (time to interrupt)
	Return:		     it returns void 
	Description: 	 this function is used to Set counter Time.
*/
void TIMER0_voidSetTime(u32 copy_u32DesiredTime);

/*
	Function Name:   TIMER0_voidStart
	Input arguments: it takes No parameter (void)
	Return:		     it returns void 
	Description: 	 this function is used to start Timer0.
*/
void TIMER0_voidStart(void);

/*
	Function Name:   TIMER0_voidStop
	Input arguments: it takes No parameter (void)
	Return:		     it returns void 
	Description: 	 this function is used to Stop Timer0.
*/
void TIMER0_voidStop(void);

/*
	Function Name:   PWM0_voidInit
	Input arguments: it takes No parameter (void)
	Return:		     it returns void 
	Description: 	 this function is used to Initialate PWM0.
*/
void PWM0_voidInit(void);

/*
	Function Name:   PWM0_voidSetDutyCycle
	Input arguments: it takes 1 parameter (u32 Duty_Cycle)
	Return:		     it returns void 
	Description: 	 this function is used to Set Duty_Cycle for PWM0.
*/
void PWM0_voidSetDutyCycle(u32 copy_u32DutyCycle);

/*
	Function Name:   PWM0_voidStart
	Input arguments: it takes No parameter (void)
	Return:		     it returns void 
	Description: 	 this function is used to Start PWM0.
*/
void PWM0_voidStart(void);

/*
	Function Name:   PWM0_voidStop
	Input arguments: it takes No parameter (void)
	Return:		     it returns void 
	Description: 	 this function is used to Stop PWM0.
*/
void PWM0_voidStop(void);

/*
	Function Name:   TIMER0_voidSetCallBack
	Input arguments: it takes 1 parameter (pointer to void function)
	Return:		     it returns void 
	Description: 	 this function is used to call void function when Timer interrupt occur.
*/
void TIMER0_voidSetCallBack(void(*ptr)(void));
void TIMER0_voidSetCallBack_2(void(*ptr1)(void) , void(*ptr2)(void));

#endif
