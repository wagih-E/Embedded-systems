/************************************************************************/
/************************************************************************/
/***********************	author: Ahmed wagih	    *********************/
/***********************	Layer:  MCAL	        *********************/
/***********************	SWC:	DIO	            *********************/
/***********************	Version:1.00	        *********************/
/************************************************************************/
/************************************************************************/

#include"STD_Types.h"
#include"SSD_interface.h"
#include"DIO_interface.h"


u8 SSD_u8ArrCathode[SSD_u8Numbers]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00100111,0b01111111,0b01101111};
u8 SSD_u8ArrAnode[SSD_u8Numbers] = {};


u8 SSD_u8SetNum(u8 SSD_u8Number ,SSD_t* SSD_P){
	u8 SDD_u8Error = 0 ;

	if(SSD_P != NULL ){
	if(SSD_P->Comm_Type == SSD_ComAnode){
		DIO_u8SetPortValue(SSD_P->Port , ~SSD_u8ArrCathode[SSD_u8Number]);



	}
	else if (SSD_P->Comm_Type == SSD_ComCathode){
		DIO_u8SetPortDirection(SSD_P->Port ,DIO_u8PORT_OUTPUT );

		/*switch(SSD_u8Number){

		case SSD_u8Zero : DIO_u8SetPortValue(SSD_P->Port,SSD_u8ArrCathode[SSD_u8Zero]) ; break  ;
		case SSD_u8One : DIO_u8SetPortValue(SSD_P->Port,SSD_u8ArrCathode[SSD_u8One]) ; break  ;
		case SSD_u8Two : DIO_u8SetPortValue(SSD_P->Port,SSD_u8ArrCathode[SSD_u8Two]) ; break  ;
		case SSD_u8Three : DIO_u8SetPortValue(SSD_P->Port,SSD_u8ArrCathode[SSD_u8Three]) ; break  ;
		case SSD_u8Four : DIO_u8SetPortValue(SSD_P->Port,SSD_u8ArrCathode[SSD_u8Four]) ; break  ;
		case SSD_u8Five : DIO_u8SetPortValue(SSD_P->Port,SSD_u8ArrCathode[SSD_u8Five]) ; break  ;
		case SSD_u8Six : DIO_u8SetPortValue(SSD_P->Port,SSD_u8ArrCathode[SSD_u8Six]) ; break  ;
		case SSD_u8Seven : DIO_u8SetPortValue(SSD_P->Port,SSD_u8ArrCathode[SSD_u8Seven]) ; break  ;
		case SSD_u8Eight : DIO_u8SetPortValue(SSD_P->Port,SSD_u8ArrCathode[SSD_u8Eight]) ; break  ;
		case SSD_u8Nine : DIO_u8SetPortValue(SSD_P->Port , SSD_u8ArrCathode[SSD_u8Nine]) ; break  ;
		default : SDD_u8Error  = 1 ; break ; }*/
		DIO_u8SetPortValue(SSD_P->Port , SSD_u8ArrCathode[SSD_u8Number]);



	}
	}
	else{
		SDD_u8Error  = 1 ;
	}
	return SDD_u8Error ;
}

u8 SSD_u8Enable(SSD_t* SSD_P){
u8 SDD_u8Error =0 ;
if(SSD_P != NULL ){
	if(SSD_P->Comm_Type == SSD_ComCathode){
		DIO_u8SetPinDirection(SSD_P->EnablePort ,SSD_P->EnablePin , DIO_u8PIN_OUTPUT );
		DIO_u8SetPinValue(SSD_P->EnablePort ,SSD_P->EnablePin , DIO_u8PIN_LOW);

	}

	else if (SSD_P->Comm_Type == SSD_ComAnode){

	}
}
	else {
		SDD_u8Error = 1;
	}
	return SDD_u8Error ;
}

u8 SSD_u8Disable(SSD_t* SSD_P){
	u8 SDD_u8Error =0 ;
	if(SSD_P != NULL ){
	if(SSD_P->Comm_Type == SSD_ComCathode){
		DIO_u8SetPinDirection(SSD_P->EnablePort ,SSD_P->EnablePin , DIO_u8PIN_OUTPUT );
		DIO_u8SetPinValue(SSD_P->EnablePort ,SSD_P->EnablePin , DIO_u8PIN_HIGH);

	}

	else if (SSD_P->Comm_Type == SSD_ComAnode){

	}
	}
	else {
		SDD_u8Error = 1;
	}
	return SDD_u8Error ;
}
