
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "GIE_REG.h"
#include "GIE_INT.h"


void GIE_voidEnableGlobal()
{
	//SET_BIT(SREG,SREG_I);
	SET_BIT(SREG,SREG_I);
}

void GIE_voidDisableGlobal()
{
	CLR_BIT(SREG,SREG_I);
}
