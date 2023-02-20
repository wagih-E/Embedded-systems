/************************************************************************/
/************************************************************************/
/***********************	author: Ahmed wagih	    *********************/
/***********************	Layer:  HAL	        *********************/
/***********************	SWC:	KEYPAD	            *********************/
/***********************	Version:1.00	        *********************/
/************************************************************************/
/************************************************************************/
#include "STD_Types.h"
#include "DIO_interface.h"
#include "KPD_config.h"
#include "KPD_inerface.h"
#include "KPD_private.h"
#include "PORT_interface.h"









u8 KPD_u8GetPressedKey(void){

u8 Local_u8PressedKey = KPD_NO_PRESSED_KEY;

u8 Local_u8RowIndex = 0 ,Local_u8ColumnIndex =0 ;

u8 Local_u8PinState ;

static u8 Local_u8ColumnArr[COLUMN_NUM] = {KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};
static u8 Local_u8RowArr[ROW_NUM] = {KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN} ;

static u8 Local_u8KPDArr[ROW_NUM][COLUMN_NUM]= KPD_ARR_VAL ;

for(Local_u8ColumnIndex = 0 ; Local_u8ColumnIndex < COLUMN_NUM ;Local_u8ColumnIndex++ ){
	//activate current column //
	DIO_u8SetPinValue(KPD_PORT,Local_u8ColumnArr[Local_u8ColumnIndex],DIO_u8PIN_LOW);


	for(Local_u8RowIndex= 0 ;Local_u8RowIndex <ROW_NUM ;Local_u8RowIndex++ ){
		//read current row //


 DIO_u8GetPinValue(KPD_PORT,Local_u8RowArr[Local_u8RowIndex],&Local_u8PinState);

	//check switch is pressed //
 if(DIO_u8PIN_LOW== Local_u8PinState){

	 Local_u8PressedKey = Local_u8KPDArr[Local_u8RowIndex][Local_u8ColumnIndex];
	//polling "busy waiting " untill hte key is pressed //
	 while(DIO_u8PIN_LOW== Local_u8PinState){
		 DIO_u8GetPinValue(KPD_PORT,Local_u8RowArr[Local_u8RowIndex],&Local_u8PinState);

	 }

		 return Local_u8PressedKey ;

 }


	}

	//deactivate current column //
	DIO_u8SetPinValue(KPD_PORT,Local_u8ColumnArr[Local_u8ColumnIndex],DIO_u8PIN_HIGH);




}





return Local_u8PressedKey ;

}
