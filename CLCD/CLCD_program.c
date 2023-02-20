/************************************************************************/
/************************************************************************/
/***********************	author: Ahmed wagih	    *********************/
/***********************	Layer:  MCAL	        *********************/
/***********************	SWC:	DIO	            *********************/
/***********************	Version:1.00	        *********************/
/************************************************************************/
/************************************************************************/
#include "STD_Types.h"
#include "DIO_interface.h"
#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"
#include <util/delay.h>


void CLCD_voidSendCommand(u8 Copy_u8Command){
	/*set RS pin to low*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);/*sent enable pulse*/
	_delay_ms(5);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);/*sent enable pulse*/



}


void CLCD_voidSendData(u8 Copy_u8Data){
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);/*sent enable pulse*/
	_delay_ms(5);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);/*sent enable pulse*/

}



void CLCD_voidInit(void){
	//wait for more than 15 ms
	_delay_ms(25);

	//function set command : 2lines , 5*8
	CLCD_voidSendCommand(0b00111000);

//display on off control : display enable , dis cursor , no blink
	CLCD_voidSendCommand(0b00001100);
	// clear display
	CLCD_voidSendCommand(1);


}
void CLCD_VoidSendString(const char* Copy_pcString){
	for(u8  Local_u8Counter = 0 ; Copy_pcString[Local_u8Counter]!='\0' ;Local_u8Counter++ ){
		CLCD_voidSendData(Copy_pcString[Local_u8Counter]);


	}


}

void CLCD_VoidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos){
	u8 Local_u8Address ;
	if(Copy_u8XPos==0){
		Local_u8Address = Copy_u8YPos ;

	}
	else if(Copy_u8XPos==1){
		Local_u8Address = Copy_u8YPos + 0x40  ;

	}
	CLCD_voidSendCommand(Local_u8Address + 128);


}


void CLCD_VoidWriteSpecialCha(u8* copy_pu8Pattern , u8 Copy_u8PatternNumber ,u8 Copy_u8XPos ,u8 Copy_u8YPos){
	u8 Local_u8CGRAMAddress=0 , Local_u8Iterator   ;
	//add = block num * 8 "each block 8 bytes "//
	Local_u8CGRAMAddress = Copy_u8PatternNumber * 8 ;
	//send CG ram address command
	CLCD_voidSendCommand(Local_u8CGRAMAddress + 64);
	//write the pattern into cg ram //
	for(Local_u8Iterator = 0 ; Local_u8Iterator <8 ; Local_u8Iterator++ ){

		CLCD_voidSendData(copy_pu8Pattern[Local_u8Iterator]);


	}
	//go back to DDRam
	CLCD_VoidGoToXY(Copy_u8XPos , Copy_u8YPos);

	//Display the pattern written in the cg ram //
	CLCD_voidSendData(Copy_u8PatternNumber);



}
