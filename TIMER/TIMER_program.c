/************************************************************************/
/************************************************************************/
/***********************	author: Ahmed wagih	    *********************/
/***********************	Layer:  MCAL	        *********************/
/***********************	SWC:	TIMER	        *********************/
/***********************	Version:1.00	        *********************/
/************************************************************************/
/************************************************************************/


#include"STD_Types.h"
#include "BIT_MATH.h"
#include"TIMER_config.h"
#include"TIMER_interface.h"
#include"TIMER_private.h"
#include"TIMER_register.h"
static void (*TIMER0_pvCallBackFunc)(void) = NULL ;

void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value){

OCR0B = Copy_u8Value ;


}

void TIMER0_voidInit(){

	/*choose FastPwm mode*/
	SET_BIT(TCCR0A,TCCR0A_WGM00);
	SET_BIT(TCCR0A,TCCR0A_WGM01);
	SET_BIT(TCCR0B,TCCR0B_WGM02);

	/*output compare match interrupt enable
	 * 	SET_BIT(TIMSK0,TIMSK0_OCIE0A);
	 * */

	/*set compare match value 125
	 * OCR0A = 125 ;
	 * */

/*non inverting mode */
	CLR_BIT(TCCR0A,4);
	SET_BIT(TCCR0A,5);

	/*prescaler division by 64 */
	SET_BIT(TCCR0B,TCCR0B_CS00);
	SET_BIT(TCCR0B,TCCR0B_CS01);
	CLR_BIT(TCCR0B,TCCR0B_CS02);


}

u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void)){
	u8 Local_u8ErrorStatus = OK ;
	if(Copy_pvCallBackFunc!=NULL ){
		TIMER0_pvCallBackFunc = Copy_pvCallBackFunc ;


	}
	else{

		Local_u8ErrorStatus = NULL_POINTER ;
	}





return Local_u8ErrorStatus ;

}




void __vector_14(void)__attribute__((signal));
void __vector_14(void){

	if(TIMER0_pvCallBackFunc != NULL){

		TIMER0_pvCallBackFunc() ;

	}



}
