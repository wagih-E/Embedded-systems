/************************************************************************/
/************************************************************************/
/***********************	author: Ahmed wagih	    *********************/
/***********************	Layer:  MCAL	        *********************/
/***********************	SWC:	ADC	            *********************/
/***********************	Version:1.00	        *********************/
/************************************************************************/
/************************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
typedef struct ADC_Chains_Type{
	u8 *ADC_u8ChainId ;
	u8 ADC_u8Chain_Size ;
	void (*ADC_pvNotFun)(void);
	u16 *ADC_u8Result ;

}ADC_Chain_Type;
 void ADC_voidInit();

 u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel,u8* Copy_pu8Reading);

 u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel,u8* Copy_pu8Reading, void(*Copy_pvNotifiationFunc)(void));

 u8	ADC_u8StartChainConversion(ADC_Chain_Type* Copy_pStruct);








#endif
