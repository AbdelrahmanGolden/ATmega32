/***************************************************************************/
/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : MCAL			************************/
/***********************	SWC     : DIO			************************/
/***********************	Version : 1.00			************************/
/***********************	Date    : 1/8/2024		************************/
/***************************************************************************/
/***************************************************************************/

/**		Libraries		**/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_register.h"
#include "DIO_config.h"
#include "DIO_private.h"
#include "DIO_interface.h"



/**		Functions Implemntation		**/

u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState = OK;
	
	if(Copy_u8Pin <= DIO_u8PIN7)
	{
		if(Copy_u8Direction == DIO_u8PIN_INPUT)
		{
			switch(Copy_u8Port)
			{
				case DIO_u8PORTA: CLR_BIT(DDRA,Copy_u8Pin); break;
				case DIO_u8PORTB: CLR_BIT(DDRB,Copy_u8Pin); break;
				case DIO_u8PORTC: CLR_BIT(DDRC,Copy_u8Pin); break;
				case DIO_u8PORTD: CLR_BIT(DDRD,Copy_u8Pin); break;
				default			: Local_u8ErrorState = NOK  ; break;
			}
		} 
		else if(Copy_u8Direction == DIO_u8PIN_OUTPUT)
		{
			switch(Copy_u8Port)
			{
				case DIO_u8PORTA: SET_BIT(DDRA,Copy_u8Pin); break;
				case DIO_u8PORTB: SET_BIT(DDRB,Copy_u8Pin); break;
				case DIO_u8PORTC: SET_BIT(DDRC,Copy_u8Pin); break;
				case DIO_u8PORTD: SET_BIT(DDRD,Copy_u8Pin); break;
				default			: Local_u8ErrorState = NOK  ; break;
			}
		}
		else
		{
			Local_u8ErrorState = NOK;
		}
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	
	return Local_u8ErrorState;
}

u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{	
	u8 Local_u8ErrorState = OK;
	
	switch(Copy_u8Port)
	{
		case DIO_u8PORTA: DDRA = Copy_u8Direction; break;
		case DIO_u8PORTB: DDRB = Copy_u8Direction; break;
		case DIO_u8PORTC: DDRC = Copy_u8Direction; break;
		case DIO_u8PORTD: DDRD = Copy_u8Direction; break;
		default			: Local_u8ErrorState = NOK ; break;
	}
	
	return Local_u8ErrorState;
}

u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	u8 Local_u8ErrorState = OK;
	
	if(Copy_u8Pin <= DIO_u8PIN7)
	{
		if(Copy_u8Value == DIO_u8PIN_LOW)
		{
			switch(Copy_u8Port)
			{
				case DIO_u8PORTA: CLR_BIT(PORTA,Copy_u8Pin); break;
				case DIO_u8PORTB: CLR_BIT(PORTB,Copy_u8Pin); break;
				case DIO_u8PORTC: CLR_BIT(PORTC,Copy_u8Pin); break;
				case DIO_u8PORTD: CLR_BIT(PORTD,Copy_u8Pin); break;
				default			: Local_u8ErrorState = NOK  ; break;
			}
		}
		else if(Copy_u8Value == DIO_u8PIN_HIGH)
		{
			switch(Copy_u8Port)
			{
				case DIO_u8PORTA: SET_BIT(PORTA,Copy_u8Pin); break;
				case DIO_u8PORTB: SET_BIT(PORTB,Copy_u8Pin); break;
				case DIO_u8PORTC: SET_BIT(PORTC,Copy_u8Pin); break;
				case DIO_u8PORTD: SET_BIT(PORTD,Copy_u8Pin); break;
				default			: Local_u8ErrorState = NOK  ; break;
			}
		}
		else
		{
			Local_u8ErrorState = NOK;
		}
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	
	return Local_u8ErrorState;
}

u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
	u8 Local_u8ErrorState = OK;
	
	switch(Copy_u8Port)
	{
		case DIO_u8PORTA: PORTA = Copy_u8Value  ; break;
		case DIO_u8PORTB: PORTB = Copy_u8Value  ; break;
		case DIO_u8PORTC: PORTC = Copy_u8Value  ; break;
		case DIO_u8PORTD: PORTD = Copy_u8Value  ; break;
		default			: Local_u8ErrorState = NOK; break;
	}
	
	return Local_u8ErrorState;
}

u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_pu8Value)
{
	u8 Local_u8ErrorState = OK;
	
	if((Copy_pu8Value != NULL) && (Copy_u8Pin<=7))
	{
		switch(Copy_u8Port)
		{
			case DIO_u8PORTA: *Copy_pu8Value = GET_BIT(PINA,Copy_u8Pin); break;
			case DIO_u8PORTB: *Copy_pu8Value = GET_BIT(PINB,Copy_u8Pin); break;
			case DIO_u8PORTC: *Copy_pu8Value = GET_BIT(PINC,Copy_u8Pin); break;
			case DIO_u8PORTD: *Copy_pu8Value = GET_BIT(PIND,Copy_u8Pin); break;
			default			: Local_u8ErrorState = NOK				   ; break;
		}
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	
	return Local_u8ErrorState;
}

u8 DIO_u8GetPortValue(u8 Copy_u8Port, u8* Copy_pu8Value)
{
	u8 Local_u8ErrorState = OK;
	
	if(Copy_pu8Value != NULL)
	{
		switch(Copy_u8Port)
		{
			case DIO_u8PORTA: *Copy_pu8Value = PINA ; break;
			case DIO_u8PORTB: *Copy_pu8Value = PINB ; break;
			case DIO_u8PORTC: *Copy_pu8Value = PINC ; break;
			case DIO_u8PORTD: *Copy_pu8Value = PIND ; break;
			default			: Local_u8ErrorState = NOK; break;
		}
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	
	return Local_u8ErrorState;
}