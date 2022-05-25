
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"

#include "EXTI_INT.h"
#include "EXTI_REG.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

/*Define Global array of 3 pointers to functions to carry ISR application addresses*/
static void (*EXTI_pvINTCallBackFunc[3])(void) = {NULL};

void EXTI_voidINT0Init()
{
	/*Check on INT0 Sense control*/
#if EXTI_INT0_SENSE == LOW_LEVEL
	CLR(MCUCR,MCUCR_ISC00);
	CLR(MCUCR,MCUCR_ISC01);

#elif EXTI_INT0_SENSE == ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif EXTI_INT0_SENSE == FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#elif EXTI_INT0_SENSE == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#else
#error "Wrong EXTI_INT0_SENSE configuration option"
#endif

	/*Check INT0 PIE initial state*/
#if EXTI_INT0_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT0);
#elif EXTI_INT0_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT0);
#else
#error " Wrong EXTI_INT0_INITIAL_STATE configuration option"
#endif
}
void EXTI_voidINT1Init()
{
	/*Check on INT1 Sense control*/
#if EXTI_INT0_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

#elif EXTI_INT0_SENSE == ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

#elif EXTI_INT0_SENSE == FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);

#elif EXTI_INT0_SENSE == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);

#else
	#error "Wrong EXTI_INT1_SENSE configuration option"
#endif

	/*Check INT1 PIE initial state*/
#if EXTI_INT1_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT1);
#elif EXTI_INT1_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT1);
#else
	#error " Wrong EXTI_INT1_INITIAL_STATE configuration option"
#endif
}
void EXTI_voidINT2Init()
{
	//CLR(GICR,GICR_INT2);
	/*Check on INT2 Sense control*/
#if EXTI_INT2_SENSE == FALLING_EDGE
	CLR_BIT(MCUCSR,MCUCSR_ISC2);

#elif EXTI_INT2_SENSE == RISING_EDGE
	SET_BIT(MCUCSR,MCUCSR_ISC2);

#else
	#error "Wrong EXTI_INT2_SENSE configuration option"
#endif
	//SET_BIT(GIFR,GIFR_INTF2);
	/*Check INT2 PIE initial state*/
#if EXTI_INT2_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT2);

#elif EXTI_INT2_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT2);
#else
	#error " Wrong EXTI_INT2_INITIAL_STATE configuration option"
#endif
}
void EXTI_u8SetSenseControl(u8 EXTI_u8Number, u8 EXTI_u8Sense)
{
	switch (EXTI_u8Number)
	{
	case EXTI_INT0:		/*In case INT0*/
		switch(EXTI_u8Sense)
		{
			case LOW_LEVEL:   CLR_BIT(MCUCR,MCUCR_ISC00); CLR_BIT(MCUCR,MCUCR_ISC01); break;
			case ON_CHANGE:   SET_BIT(MCUCR,MCUCR_ISC00); CLR_BIT(MCUCR,MCUCR_ISC01); break;
			case FALLING_EDGE:CLR_BIT(MCUCR,MCUCR_ISC00); SET_BIT(MCUCR,MCUCR_ISC01); break;
			case RISING_EDGE: SET_BIT(MCUCR,MCUCR_ISC00); SET_BIT(MCUCR,MCUCR_ISC01); break;
			default:  break;
		}
		break;			/*Break INT0 case*/
	case EXTI_INT1:	/*In case of INT1*/
		switch(EXTI_u8Sense)
		{
			case LOW_LEVEL:   CLR_BIT(MCUCR,MCUCR_ISC10); CLR_BIT(MCUCR,MCUCR_ISC11); break;
			case ON_CHANGE:   SET_BIT(MCUCR,MCUCR_ISC10); CLR_BIT(MCUCR,MCUCR_ISC11); break;
			case FALLING_EDGE:CLR_BIT(MCUCR,MCUCR_ISC10); SET_BIT(MCUCR,MCUCR_ISC11); break;
			case RISING_EDGE: SET_BIT(MCUCR,MCUCR_ISC10); SET_BIT(MCUCR,MCUCR_ISC11); break;
			default: break;
		}
		break;		/*Break INT1 case*/
	case EXTI_INT2:	/*In case of INT2*/
		switch(EXTI_u8Sense)
		{
			case RISING_EDGE: SET_BIT(MCUCSR,MCUCSR_ISC2);  break;
			case FALLING_EDGE: CLR_BIT(MCUCSR,MCUCSR_ISC2);  break;
			default: break;
		}
		break;		/*Break INT2 case*/
	default: break;
	}

}

void EXTI_u8INTSetCallBack(void (*Copy_pvCallBackFunc)(void), u8 EXTI_u8Number)
{
	if(Copy_pvCallBackFunc != NULL)
	{
		EXTI_pvINTCallBackFunc[EXTI_u8Number]= Copy_pvCallBackFunc;
	}
}

/*ISR of INT0*/
void  __vector_1 (void)	__attribute__((signal));
void  __vector_1 (void)
{
	if(EXTI_pvINTCallBackFunc[EXTI_INT0] != NULL)
	{
		EXTI_pvINTCallBackFunc[EXTI_INT0]();
	}

}
/*ISR of INT1*/
void  __vector_2 (void)	__attribute__((signal));
void  __vector_2 (void)
{
	if(EXTI_pvINTCallBackFunc[EXTI_INT1] != NULL)
	{
		EXTI_pvINTCallBackFunc[EXTI_INT1]();
	}
}
/*ISR of INT2*/
void  __vector_3 (void)	__attribute__((signal));
void  __vector_3 (void)
{
	if(EXTI_pvINTCallBackFunc[EXTI_INT2] != NULL)
	{
		EXTI_pvINTCallBackFunc[EXTI_INT0]();
	}

}

