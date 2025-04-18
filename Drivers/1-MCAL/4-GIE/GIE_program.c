/***************************************************************************/
/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : MCAL			************************/
/***********************	SWC     : GIE			************************/
/***********************	Version : 1.00			************************/
/***********************	Date    : 30/9/2024		************************/
/***************************************************************************/
/***************************************************************************/

/**		Libraries		**/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GIE_register.h"
#include "GIE_interface.h"


/**		Functions Implemntation		**/

void GIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}

void GIE_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}

u8 GIE_u8IsEnabled(void)
{
	return GET_BIT(SREG, SREG_I);
}