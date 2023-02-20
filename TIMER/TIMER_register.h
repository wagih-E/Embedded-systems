/************************************************************************/
/************************************************************************/
/***********************	author: Ahmed wagih	    *********************/
/***********************	Layer:  MCAL	        *********************/
/***********************	SWC:	TIMER	        *********************/
/***********************	Version:1.00	        *********************/
/************************************************************************/
/************************************************************************/

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define TCCR0A			*((volatile u8*)0x44)		 /*Timer0 Control register*/
#define TCCR0A_WGM00	0							 /*waveform generation mode bit0 */
#define TCCR0A_WGM01	1							 /*waveform generation mode bit1 */


#define TCCR0B			*((volatile u8*)0x45)		 /**/
#define TCCR0B_CS00		0							 /*prescaler bit0*/
#define TCCR0B_CS01		1					         /*prescaler bit1*/
#define TCCR0B_CS02		2							 /*prescaler bit2*/
#define TCCR0B_WGM02 	3							 /*waveform generation mode bit1*/


#define OCR0A			*((volatile u8*)0x47)		/*output compare register*/
#define OCR0B			*((volatile u8*)0x48)

#define TIMSK0			*((volatile u8*)0x6E)
#define TIMSK0_TOIE0	0
#define TIMSK0_OCIE0A	1
#define TIMSK0_OCIE0B	2

#define TIMSK1			*((volatile u8*)0x6F)		/*Timer mask*/
#define TIMSK0_TOIE1	0							/*output compare 0 interrupt enable*/
#define TIMSK0_OCIE1A	1
#define TIMSK0_OCIE1B	2
#define TIMSK0_ICIE1	5

#define TIMSK2			*((volatile u8*)0x70)
#define TIMSK0_TOIE2	0
#define TIMSK0_OCIE2A	1
#define TIMSK0_OCIE2B	2




#endif
