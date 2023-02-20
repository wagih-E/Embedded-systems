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
u8 ADC_u8GetChanelReading(u8 Copy_u8Channel){

/*clear the ,mux bits in admux reg 4BITS IN ATMEGA328P*/
	ADMUX &= 0b11110000;

/*set the req channel to the mux bits */
			ADMUX|=Copy_u8Channel 	;

/*start conversion */
SET_BIT(ADCSRA,ADCSRA_ADSC);

/*polling until the conversion flag is set*/

while((GET_BIT(ADCSRA,ADCSRA_ADIF))==0);

/*clear the conversion */

SET_BIT(ADCSRA,ADCSRA_ADIF);
/*return reading*/
return ADCH ;


}
