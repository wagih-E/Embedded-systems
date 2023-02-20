/*
 * main.c
 *
 *  Created on: Nov 2, 2022
 *      Author: ahmed
 */
#include <util/delay.h>
#include "STD_Types.h"
#include "CLCD_interface.h"
#include "DIO_interface.h"

void main(void){
	u8  arrw[8]= {0b00000000,0b00001110,0b00001010,0b00001110,0b00000010,0b00000100,0b00001000,0b00010000};

	u8  arrg[8]= {0b00000000,0b00000000,0b00000111,0b00000001,0b00011111,0b00000000,0b00000010,0b00000000};

	u8  arry[8]= {0b00000000,0b00000000,0b00000000,0b00000100,0b00011111,0b00000000,0b00001100,0b00000000};

	u8 arrh[8]=  {0b00000000,0b00011100,0b00010100,0b00011100,0b00000111,0b00000000,0b00000000,0b00000000};
	/*init lcd pins dirction*/

	DIO_u8SetPortDirection(DIO_u8PORTD,DIO_u8PORT_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_OUTPUT);


	CLCD_voidInit();



	while(1){

		CLCD_VoidWriteSpecialCha(arrw, 0,0,3);
		CLCD_VoidWriteSpecialCha(arrg, 1,0,2);
		CLCD_VoidWriteSpecialCha(arry, 2,0,1);
		CLCD_VoidWriteSpecialCha(arrh, 3,0,0);

		_delay_ms(1000);
		CLCD_voidSendCommand(1);

		CLCD_VoidWriteSpecialCha(arrw, 0,1,7);
		CLCD_VoidWriteSpecialCha(arrg, 1,1,6);
		CLCD_VoidWriteSpecialCha(arry, 2,1,5);
		CLCD_VoidWriteSpecialCha(arrh, 3,1,4);



		_delay_ms(1000);
		CLCD_voidSendCommand(1);


		CLCD_VoidWriteSpecialCha(arrw, 0,0,11);
		CLCD_VoidWriteSpecialCha(arrg, 1,0,10);
		CLCD_VoidWriteSpecialCha(arry, 2,0,9);
		CLCD_VoidWriteSpecialCha(arrh, 3,0,8);



		_delay_ms(1000);

		CLCD_voidSendCommand(1);

		CLCD_VoidWriteSpecialCha(arrw, 0,1,15);
		CLCD_VoidWriteSpecialCha(arrg, 1,1,14);
		CLCD_VoidWriteSpecialCha(arry, 2,1,13);
		CLCD_VoidWriteSpecialCha(arrh, 3,1,12);



		_delay_ms(1000);

		CLCD_voidSendCommand(1);

	}



}
