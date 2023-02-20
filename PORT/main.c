/*
 * main.c
 *
 *  Created on: Oct 26, 2022
 *      Author: ahmed
 */

#include "STD_Types.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include <util/delay.h>

void main(){



	PORT_VoidInit();
	while(1){
		DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN_HIGH);

	_delay_ms(1000);
		DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN_LOW);

		_delay_ms(1000);
	}

	}


