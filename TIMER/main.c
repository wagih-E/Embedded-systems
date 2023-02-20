/*
 * main.c
 *
 *  Created on: Feb 9, 2023
 *      Author: WAGIH
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "TIMER_interface.h"
#include "GIE_interface.h"
#include <util/delay.h>

void TIMER_Notification (void);
void LED(void);

void main(void)
{
	u8 Local_u8Counter ;


	PORT_VoidInit();
	TIMER0_voidInit();
	TIMER0_u8SetCallBack(&LED);
	GIE_voidEnable();

	while(1){
		for(Local_u8Counter =0 ; Local_u8Counter<255 ;Local_u8Counter++ ){

			TIMER0_voidSetCompMatchValue(Local_u8Counter);
			_delay_ms(10);
		}
	}



}
void LED(void){


	static u8 Local_u8Counter=0 ;
	Local_u8Counter++ ;
	if(Local_u8Counter == 15){

		DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN1, DIO_u8PIN_LOW);

	}
	else if(Local_u8Counter == 5){

			DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN5, DIO_u8PIN_LOW);

		}
	else if (Local_u8Counter == 20 ){

		DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN1, DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN5, DIO_u8PIN_HIGH);

		Local_u8Counter = 0 ;
	}



}

void TIMER_Notification (void){


}
