/************************************************************************/
/************************************************************************/
/***********************	author: Ahmed wagih	    *********************/
/***********************	Layer:  MCAL	        *********************/
/***********************	SWC:	PORT	        *********************/
/***********************	Version:1.00	        *********************/
/************************************************************************/
/************************************************************************/


#include "STD_Types.h"
#include "PORT_config.h"
#include "PORT_private.h"
#include "PORT_interface.h"
#include "PORT_register.h"


void PORT_VoidInit(void){

	DDRB = PORTB_DIR ;
	DDRC = PORTC_DIR ;
	DDRD = PORTD_DIR ;


	PORTB = PORTB_INITIAL_VALUE ;
	PORTC = PORTC_INITIAL_VALUE ;
	PORTD = PORTD_INITIAL_VALUE ;

}

