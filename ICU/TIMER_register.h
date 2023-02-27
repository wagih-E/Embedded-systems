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

#define TCNT1 			*((volatile u16*)0x84)
#define TIMSK1			*((volatile u8*)0x6F)		/*Timer mask*/
#define TIMSK1_TOIE1	0							/*output compare 0 interrupt enable*/
#define TIMSK1_OCIE1A	1
#define TIMSK1_OCIE1B	2
#define TIMSK1_ICIE1	5

#define TIMSK2			*((volatile u8*)0x70)
#define TIMSK2_TOIE2	0
#define TIMSK2_OCIE2A	1
#define TIMSK2_OCIE2B	2

#define TCCR1A			*((volatile u8*)0x80)		 /*Timer1 Control register*/
#define TCCR1A_WGM10	0							 /*waveform generation mode bit0 */
#define TCCR1A_WGM11	1							 /*waveform generation mode bit1 */
#define TCCR1A_COM1B0	4							 /*waveform generation mode bit1 */
#define TCCR1A_COM1B1	5							 /*waveform generation mode bit1 */
#define TCCR1A_COM1A0	6							 /*waveform generation mode bit1 */
#define TCCR1A_COM1A1	7							 /*waveform generation mode bit1 */

#define TCCR1B			*((volatile u8*)0x81)		 /*Timer1 Control register*/
#define TCCR1B_CS10		0							 /*prescaler bit0*/
#define TCCR1B_CS11		1					         /*prescaler bit1*/
#define TCCR1B_CS12		2							 /*prescaler bit2*/
#define TCCR1B_WGM12 	3							 /*waveform generation mode bit1*/
#define TCCR1B_WGM13 	4							 /*waveform generation mode bit1*/

#define OCR1A			*((volatile u16*)0x88)		/*output compare register*/
#define OCR1B			*((volatile u16*)0x8A)

#define ICR1			*((volatile u16*)0x86)

#define PRESCALER_MASK 	0b11111000
#define DEV_0			0
#define DEV_1			1
#define DEV_8			2
#define DEV_64			3
#define DEV_256			4
#define DEV_1024		5

#endif
