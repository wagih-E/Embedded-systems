/*
 * main.c
 *
 *  Created on: Jan 23, 2023
 *      Author: WAGIH
 */
#include "STD_Types.h"
#include "PORT_interface.h"
#include "DIO_interface.h"

#include "EXTI_interface.h"
#include "GIE_interface.h"
void INT0_ISR(void);

void main(void){
	PORT_VoidInit();
	EXTI_IntEnable(INT0);
	EXTI_u8IntSetSenseControl(FALLING_EDGE,INT0);
	EXTI_Int0SetCallBack(&INT0_ISR);
	GIE_voidEnable();




	while(1){





	}

}

void INT0_ISR(void){


	u8 pnt ;
	DIO_u8GetPinValue(DIO_u8PORTB,DIO_u8PIN0,&pnt);

if (DIO_u8PIN_LOW==pnt){
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);
}
else{
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);

}
}
//ISR0 function
/*void __vector_1 (void) __attribute__((signal));
void __vector_1 (void){

	u8 pnt ;
	DIO_u8GetPinValue(DIO_u8PORTB,DIO_u8PIN0,&pnt);

if (DIO_u8PIN_LOW==pnt){
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);}
else{
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);

}
}
*/
