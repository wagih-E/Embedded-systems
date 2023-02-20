/************************************************************************/
/************************************************************************/
/***********************	author: Ahmed wagih	    *********************/
/***********************	Layer:  MCAL	        *********************/
/***********************	SWC:	DIO	            *********************/
/***********************	Version:1.00	        *********************/
/************************************************************************/
/************************************************************************/

#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

/*#define PORTA		*((volatile u8*)0x)
#define DDRA		*((volatile u8*)0x)
#define PINA		*((volatile u8*)0x)
*/

#define PORTB		*((volatile u8*)0x25)
#define DDRB		*((volatile u8*)0x24)
#define PINB		*((volatile u8*)0x23)

#define PORTC		*((volatile u8*)0x28)
#define DDRC		*((volatile u8*)0x27)
#define PINC		*((volatile u8*)0x26)

#define PORTD		*((volatile u8*)0x2B)
#define DDRD		*((volatile u8*)0x2A)
#define PIND		*((volatile u8*)0x29)

#endif
