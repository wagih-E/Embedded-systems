/************************************************************************/
/************************************************************************/
/***********************	author: Ahmed wagih	    *********************/
/***********************	Layer:  MCAL	        *********************/
/***********************	SWC:	EXTI            *********************/
/***********************	Version:1.00	        *********************/
/************************************************************************/
/************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_register.h"

/*global pointer to function to hold int0 isr address*/
void (*EXTI_pvInt0Func)(void)=NULL ;
/*global pointer to function to hold int1 isr address*/

void (*EXTI_pvInt1Func)(void)=NULL ;




void EXTI_voidInt0Init(void){
/*
	//SET sense control for int0 falling edge
	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);




	//peripheral interrupt enable for int0

SET_BIT(GICR,GICR_INT0);*/
	//check sence control
#if	 INT0_SENSE == LOW_LEVEL
CLR_BIT(MCUCR,MCUCR_ISC01);
CLR_BIT(MCUCR,MCUCR_ISC00);

#elif	 INT0_SENSE == ON_CHANGE
CLR_BIT(MCUCR,MCUCR_ISC01);
SET_BIT(MCUCR,MCUCR_ISC00);

#elif	 INT0_SENSE == FALLING_EDGE
SET_BIT(MCUCR,MCUCR_ISC01);
CLR_BIT(MCUCR,MCUCR_ISC00);
#elif	 INT0_SENSE == RISING_EDGE
SET_BIT(MCUCR,MCUCR_ISC01);
SET_BIT(MCUCR,MCUCR_ISC00);
#else
#error "wrong INT0_SENSE config options"
#endif
//check prepheral int enable initial state
#if INT0_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT0);
#elif INT0_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT0);
#else
#error "wrong int0 intital state"
#endif


}

void EXTI_voidInt1Init(void){
/*
	//SET sense control for int1 falling edge
		SET_BIT(MCUCR,MCUCR_ISC11);
		CLR_BIT(MCUCR,MCUCR_ISC10);




		//peripheral interrupt enable for int1

	SET_BIT(GICR,GICR_INT1);
*/
	//check sence control
#if	 INT1_SENSE == LOW_LEVEL
CLR_BIT(MCUCR,MCUCR_ISC11);
CLR_BIT(MCUCR,MCUCR_ISC10);

#elif	 INT1_SENSE == ON_CHANGE
CLR_BIT(MCUCR,MCUCR_ISC11);
SET_BIT(MCUCR,MCUCR_ISC10);

#elif	 INT1_SENSE == FALLING_EDGE
SET_BIT(MCUCR,MCUCR_ISC11);
CLR_BIT(MCUCR,MCUCR_ISC10);
#elif	 INT1_SENSE == RISING_EDGE
SET_BIT(MCUCR,MCUCR_ISC11);
SET_BIT(MCUCR,MCUCR_ISC10);
#else
#error "wrong INT1_SENSE config options"
#endif
//check prepheral int enable initial state
#if INT1_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT1);
#elif INT1_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT1);
#else
#error "wrong int1 intital state"
#endif

}


u8 EXTI_u8IntSetSenseControl(u8 Copy_u8Sense,u8 Copy_u8IntPin){
	u8 Local_u8ErrorState = OK;
	if(Copy_u8IntPin == INT0){
	switch(Copy_u8Sense){
	case  LOW_LEVEL :
	CLR_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);
	break;
	case ON_CHANGE :
		CLR_BIT(MCUCR,MCUCR_ISC01);
		SET_BIT(MCUCR,MCUCR_ISC00);
		break;

	case FALLING_EDGE :
		SET_BIT(MCUCR,MCUCR_ISC01);
		CLR_BIT(MCUCR,MCUCR_ISC00);
		break;

	case RISING_EDGE :
		SET_BIT(MCUCR,MCUCR_ISC01);
		SET_BIT(MCUCR,MCUCR_ISC00);
		break;
	default: Local_u8ErrorState=NOK ;
		}}

	else if(Copy_u8IntPin==INT1){

		switch(Copy_u8Sense){
			case  LOW_LEVEL :
			CLR_BIT(MCUCR,MCUCR_ISC11);
			CLR_BIT(MCUCR,MCUCR_ISC10);
			break;
			case ON_CHANGE :
				CLR_BIT(MCUCR,MCUCR_ISC11);
				SET_BIT(MCUCR,MCUCR_ISC10);
				break;

			case FALLING_EDGE :
				SET_BIT(MCUCR,MCUCR_ISC11);
				CLR_BIT(MCUCR,MCUCR_ISC10);
				break;

			case RISING_EDGE :
				SET_BIT(MCUCR,MCUCR_ISC11);
				SET_BIT(MCUCR,MCUCR_ISC10);
				break;
			default: Local_u8ErrorState=NOK ;

	}}
		return Local_u8ErrorState ;
}

u8 EXTI_IntEnable(u8 Copy_u8Int){
	u8 Local_u8ErrorState = OK;
	SET_BIT(GICR,Copy_u8Int);

	return Local_u8ErrorState ;

}

u8 EXTI_IntDisable(u8 Copy_u8Int){
	u8 Local_u8ErrorState = OK;
	CLR_BIT(GICR,Copy_u8Int);

	return Local_u8ErrorState ;
}

u8 EXTI_Int0SetCallBack(void(*Copy_pvInt0Func)(void)){
	u8 Local_u8ErrorState = OK;
	if (Copy_pvInt0Func != NULL){
		EXTI_pvInt0Func = Copy_pvInt0Func ;
	}
	else {
		Local_u8ErrorState = NULL_POINTER ;
	}



	return Local_u8ErrorState ;
}
u8 EXTI_Int1SetCallBack(void(*Copy_pvInt1Func)(void)){
	u8 Local_u8ErrorState = OK;
	if (Copy_pvInt1Func != NULL){
		EXTI_pvInt1Func = Copy_pvInt1Func ;
	}
	else {
		Local_u8ErrorState = NULL_POINTER ;
	}



	return Local_u8ErrorState ;
}

/*ISR of INT0 */
void __vector_1 (void)  __attribute__((signal));
void __vector_1 (void){

	if(EXTI_pvInt0Func != NULL){
	EXTI_pvInt0Func();
	}
	else{
		/*do nothing*/
	}
}


/*ISR of INT1 */
void __vector_2 (void)  __attribute__((signal));
void __vector_2 (void){

	if(EXTI_pvInt1Func != NULL){
	EXTI_pvInt1Func();
	}
	else{
		/*do nothing*/
	}
}

