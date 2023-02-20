/************************************************************************/
/************************************************************************/
/***********************	author: Ahmed wagih	    *********************/
/***********************	Layer:  MCAL	        *********************/
/***********************	SWC:	ADC	            *********************/
/***********************	Version:1.00	        *********************/
/************************************************************************/
/************************************************************************/

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_




#define ADMUX		    *((volatile u8*)0x7C)           //ADC mux selection register
#define ADMUX_REFS1     7                               //reference selection bit0
#define ADMUX_REFS0     6                               //reference selection bit1
#define ADMUX_ADLAR     5                               //ADC LEft Adjust Result


#define ADCSRA		    *((volatile u8*)0x7A)           //ADC ctrl and status register
#define ADCSRA_ADEN      7                              //ADC enable
#define ADCSRA_ADSC      6                              //Start conversion
#define ADCSRA_ ADATE    5                              //Auto trigger ena
#define ADCSRA_ADIF      4                              //Int flag
#define ADCSRA_ADIE      3                              //Int Enable
#define ADCSRA_ADPS2     2                              //prescaler bit2
#define ADCSRA_ADPS1     1                              //prescaler bit1
#define ADCSRA_ADPS0     0                              //prescaler bit0


#define ADCH		*((volatile u8*)0x79)               //ADC High register
#define ADCL		*((volatile u8*)0x78)               //ADC LOw register







#endif // ADC_REGISTER_H_
