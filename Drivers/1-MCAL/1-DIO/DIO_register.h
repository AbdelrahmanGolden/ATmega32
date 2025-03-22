/***************************************************************************/
/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : MCAL			************************/
/***********************	SWC     : DIO			************************/
/***********************	Version : 1.00			************************/
/***********************	Date    : 1/8/2024		************************/
/***************************************************************************/
/***************************************************************************/


/** File Guard **/
#ifndef DIO_REGISTSER_H_ 
#define DIO_REGISTSER_H_ 


#define PINA	*((volatile u8*) 0x39)

#define PINB	*((volatile u8*) 0x36)

#define PINC	*((volatile u8*) 0x33)

#define PIND	*((volatile u8*) 0x30)

#endif