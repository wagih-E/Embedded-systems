/************************************************************************/
/************************************************************************/
/***********************	author: Ahmed wagih	    *********************/
/***********************	Layer:  MCAL	        *********************/
/***********************	SWC:	DIO	            *********************/
/***********************	Version:1.00	        *********************/
/************************************************************************/
/************************************************************************/


#include "STD_Types.h"
#include "BIT_MATH.h"
#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_register.h"

static u8 ADC_u8ChainIndex = 0  ;
static u8 *ADC_u8gChainId = NULL ;
static u8 ADC_u8gChain_Size  ;
static void (*ADC_pvgNotFun)(void)=NULL;
static u16 *ADC_u8gResult=NULL   ;

static u8* ADC_pu8Reading= NULL ;
static void (*ADC_pvCallBackNotificationFunc)(void)= NULL;

u8 ADC_u8BusyState = IDLE ;


void ADC_voidInit(){

	/*AVCC as ref voltage */
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

	//activate left adjust result

	SET_BIT(ADMUX,ADMUX_ADLAR);

	/*set prescaler to divide by 128 */
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS0);

	/*Enable peripheral */
	SET_BIT(ADCSRA,ADCSRA_ADEN);




}
u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel ,u8* Copy_pu8Reading){

	u32 Local_u32Counter = 0 ;
	u8 Local_u8ErrorState = OK ;
	if(ADC_u8BusyState == IDLE){

		ADC_u8BusyState = BUSY ;
		/*clear the ,mux bits in admux reg 4BITS IN ATMEGA328P*/
		ADMUX &= 0b11110000;

		/*set the req channel to the mux bits */
		ADMUX|=Copy_u8Channel 	;

		/*start conversion */
		SET_BIT(ADCSRA,ADCSRA_ADSC);

		/*polling until the conversion flag is set*/

		while((GET_BIT(ADCSRA,ADCSRA_ADIF))==0  && Local_u32Counter != ADC_u32TimeOut){
			Local_u32Counter++ ;


		}
		if(Local_u32Counter==ADC_u32TimeOut){

			//break the loop becase timeout is reached
			Local_u8ErrorState = NOK;
		}
		else {
			//loop broken becase flag is raised

			/*clear the conversion */

			SET_BIT(ADCSRA,ADCSRA_ADIF);
			/*return reading*/
			*Copy_pu8Reading =  ADCH ;

			ADC_u8BusyState = IDLE ;


		}
	}
	else{
		Local_u8ErrorState = BUSY_FUNC ;

	}
	return Local_u8ErrorState ;

}

u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel,u8* Copy_pu8Reading, void(*Copy_pvNotifiationFunc)(void)){

	u8 Local_u8ErrorState = OK ;
	if(ADC_u8BusyState == IDLE){
		if((Copy_pu8Reading == NULL) || (Copy_pvNotifiationFunc == NULL) ){
			Local_u8ErrorState = NULL_POINTER ;

		}
		else{
			//make adc busy to not work until being idle
			ADC_u8BusyState = BUSY ;
			//initialize the reading variable globally
			ADC_pu8Reading = Copy_pu8Reading ;
			//initiate the Call Back Notification Func globally
			ADC_pvCallBackNotificationFunc = Copy_pvNotifiationFunc ;
			/*clear the ,mux bits in admux reg 4BITS IN ATMEGA328P*/
			ADMUX &= 0b11110000;

			/*set the req channel to the mux bits */
			ADMUX|=Copy_u8Channel 	;

			/*start conversion */
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			//ADC int enabled //
			SET_BIT(ADCSRA,ADCSRA_ADIE);


		}
	}
	else {
		Local_u8ErrorState = BUSY_FUNC;
	}

	return Local_u8ErrorState ;

}
u8	ADC_u8StartChainConversion(ADC_Chain_Type* Copy_pStruct){
	u8 Local_u8ErrorState = OK;
	if(Copy_pStruct !=NULL ){
		if(ADC_u8BusyState == IDLE){
		//make adc busy to not work until being idle
		ADC_u8BusyState = CHAIN ;

		/*making global varibles */
		ADC_pvgNotFun		= Copy_pStruct ->ADC_pvNotFun ;
		ADC_u8gChainId  	= Copy_pStruct ->ADC_u8ChainId;
		ADC_u8gChain_Size 	= Copy_pStruct ->ADC_u8Chain_Size;
		ADC_u8gResult 		= Copy_pStruct -> ADC_u8Result ;
		ADC_u8ChainIndex	= 0 ; //initiate conversion index
		/*clear the ,mux bits in admux reg 4BITS IN ATMEGA328P*/
		ADMUX &= 0b11110000;
		/*set the req channel to the mux bits */
		ADMUX|=ADC_u8gChainId[ADC_u8ChainIndex] 	;
		/*start conversion */
		SET_BIT(ADCSRA,ADCSRA_ADSC);

		//ADC int enabled //
		SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
		else{

			Local_u8ErrorState = BUSY_FUNC ;
		}


	}
	else{
		Local_u8ErrorState = NULL_POINTER ;

	}
	return Local_u8ErrorState ;

}

void __vector_21(void)__attribute__((signal));
void __vector_21(void){


	if (ADC_u8BusyState ==CHAIN){
		//read adc result
		ADC_u8gResult[ADC_u8ChainIndex]= ADCH;
		/*increment Chain Index */
		ADC_u8ChainIndex++ ;

		if(ADC_u8ChainIndex == ADC_u8gChain_Size){
			//invoke the callback notification func
			ADC_u8BusyState = IDLE ;
			ADC_pvgNotFun();
			//make adc_state idel
			//disable adc conversion complete interrupt

			CLR_BIT(ADCSRA,ADCSRA_ADIE);
		}
		else{
			/*clear the ,mux bits in admux reg 4BITS IN ATMEGA328P*/
			ADMUX &= 0b11110000;
			/*set next channel*/
			ADMUX|=ADC_u8gChainId[ADC_u8ChainIndex] 	;



			/*Start Conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);




		}
	}
	else{
		//read adc result
		*ADC_pu8Reading = ADCH ;


		//make adc_state idel
		ADC_u8BusyState = IDLE ;

		//invoke the callback notification func
		ADC_pvCallBackNotificationFunc() ;


		//disable adc conversion complete interrupt

		CLR_BIT(ADCSRA,ADCSRA_ADIE);

	}
}
