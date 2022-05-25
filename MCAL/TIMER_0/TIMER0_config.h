/*************************************************************************/
/*	Author:  AbdelRahman Ra'fat Hegazy									*/
/*	Date: 	 29/4/2022													*/
/*	Version: V01														*/
/*************************************************************************/

#ifndef TIMER0_CONFIG_H
#define TIMER0_CONFIG_H


#define TIMER0_MODE				NORMAL_MODE //option to select[1-NORMAL_MODE 2-CTC_MODE	3-PHASE_CORRECT_PWM_MODE 4-FAST_PWM_MODE]

#define PWM0_MODE				PHASE_CORRECT_PWM_MODE	//option to select[1-PHASE_CORRECT_PWM_MODE 2-FAST_PWM_MODE]

#define COMPARE_OUTPUT_MODE		NON_INVERTED_MODE //option to select[1-INVERTED_MODE 2-NON_INVERTED_MODE]

#define TIMER0_PRESCALAR		1024 //option to select[1-1024	2-512	3-256	4-128	5-64	6-32	7-16	8-8		9-4		10-2]

#define CRYSTAL_FREQ			16	//option to select[1-20		2-16	3-8]

//#define TIMER0_ISR_vect = TIMER0_OVF_vect
//#define TIMER0_ISR_vect = TIMER0_COMP_vect


#endif 