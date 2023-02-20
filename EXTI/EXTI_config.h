/************************************************************************/
/************************************************************************/
/***********************	author: Ahmed wagih	    *********************/
/***********************	Layer:  MCAL	        *********************/
/***********************	SWC:	EXTI            *********************/
/***********************	Version:1.00	        *********************/
/************************************************************************/
/************************************************************************/
#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_


/*options:
 * 1-LOW_LEVEL
 * 2-ON_CHANGE
 * 3-RISING_EDGE
 * 4-FALING_EDGE
 *
 * */
#define INT0_SENSE  		FALLING_EDGE
#define INT1_SENSE  		FALLING_EDGE

/*
 * 1-ENABLED
 * 2-DISABLED */
#define INT0_INITIAL_STATE  ENABLED
#define INT1_INITIAL_STATE  ENABLED




#endif
