/************************************************************************/
/************************************************************************/
/***********************	author: Ahmed wagih	    *********************/
/***********************	Layer:  MCAL	        *********************/
/***********************	SWC:	EXTI            *********************/
/***********************	Version:1.00	        *********************/
/************************************************************************/
/************************************************************************/


#ifndef EXTI_REGESTER_H_
#define EXTI_REGESTER_H_


#define SREG       *((volatile u8*)0x5F)
#define MCUCR      *((volatile u8*)0x69)
#define MCUCR_ISC00 0
#define MCUCR_ISC01 1
#define MCUCR_ISC10 2
#define MCUCR_ISC11 3

#define GICR       *((volatile u8*)0x3D)
#define GICR_INT0 0
#define GICR_INT1 1

#define GIFR       *((volatile u8*)0x3C)
//#define MCUCSR     *((volatile u8*)0x54)








#endif // EXTI_REGESTER_H_
