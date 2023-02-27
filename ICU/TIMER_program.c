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
static void (*TIMER1_pvCallBackFunc)(void) = NULL ;

void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value){

OCR0B = Copy_u8Value ;


}

void TIMER0_voidInit(){

	/*choose FastPwm mode*/
	SET_BIT(TCCR0A,TCCR0A_WGM00);
	SET_BIT(TCCR0A,TCCR0A_WGM01);
	CLR_BIT(TCCR0B,TCCR0B_WGM02);

	/*output compare match interrupt enable
	 * 	SET_BIT(TIMSK0,TIMSK0_OCIE0A);
	 * */

	/*set compare match value 64*/
	  OCR0A = 64;


/*non inverting mode */
	CLR_BIT(TCCR0A,6);
	SET_BIT(TCCR0A,7);

	/*prescaler division by 8 */
	CLR_BIT(TCCR0B,TCCR0B_CS00);
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
u8 TIMER1_u8SetCallBack(void (*Copy_pvCallBackFunc)(void)){
	u8 Local_u8ErrorStatus = OK ;
	if(Copy_pvCallBackFunc!=NULL ){
		TIMER1_pvCallBackFunc = Copy_pvCallBackFunc ;


	}
	else{

		Local_u8ErrorStatus = NULL_POINTER ;
	}





return Local_u8ErrorStatus ;

}
void TIMER1_voidInit(){
	/*choose normal mode*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

	/*output compare match interrupt enable
	 * 	SET_BIT(TIMSK0,TIMSK0_OCIE0A);
	 * */

	/*set compare match value 125
	 * OCR0A = 125 ;
	 * */

/*non inverting mode */
	CLR_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);

	/*prescaler division by 8 */
TCCR1B&= PRESCALER_MASK ;
TCCR1B|= DEV_8;

}
u16  TIMER1_u16ReadTimerValue(void){
	return TCNT1 ;

}

void TIMER1_voidSetICR(u16 copy_u16TOP){

	ICR1 = copy_u16TOP ;
}

void TIMER1_voidSetCompMatchValue(u16 Copy_u16Value){
	OCR1B = Copy_u16Value ;
}

void TIMER1_voidSetTimerValue(u16 Copy_u16Value){

	TCNT1 = Copy_u16Value ;
}

void SERVO_voidAngle(u8 Copy_u8Angle){
u16 Local_u16ICRValue = (22.2*Copy_u8Angle) + 1000 ;
TIMER1_voidSetCompMatchValue(Local_u16ICRValue);
}



void __vector_14(void)__attribute__((signal));
void __vector_14(void){

	if(TIMER0_pvCallBackFunc != NULL){

		TIMER0_pvCallBackFunc() ;

	}
	else if(TIMER1_pvCallBackFunc != NULL){

		TIMER1_pvCallBackFunc() ;

	}


}
