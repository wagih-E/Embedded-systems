/*
 * main.c
 *
 *  Created on: Oct 26, 2022
 *      Author: ahmed
 */

#include "STD_Types.h"
#include "DIO_interface.h"

void main(){
	u8 Local_u8InputValue = 1 ;
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_INPUT);
	DIO_u8SetPinValue(DIO_u8PORTB , DIO_u8PIN1 ,DIO_u8PIN_HIGH );


	while(1){
		DIO_u8GetPinValue(DIO_u8PORTB,DIO_u8PIN1 ,&Local_u8InputValue  );
		if(Local_u8InputValue == 0){
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN2 ,DIO_u8PIN_HIGH );
		}

	}
}

