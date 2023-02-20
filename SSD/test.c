/*
 * main.c
 *
 *  Created on: Oct 29, 2022
 *      Author: ahmed
 */
#include "STD_Types.h"
#include "SSD_interface.h"
#include"DIO_interface.h"
#include <util/delay.h>

void main(){

	SSD_t SSD1 = {SSD_ComCathode , DIO_u8PORTD , DIO_u8PORTB ,DIO_u8PIN0 };
	SSD_t SSD2 = {SSD_ComCathode , DIO_u8PORTD , DIO_u8PORTB ,DIO_u8PIN1 };

	SSD_t *SSD_Pointer=&SSD1;
	SSD_t *SSD_Pointer2=&SSD2;

	while(1){
		SSD_u8Enable(SSD_Pointer);
		SSD_u8SetNum(SSD_u8One ,SSD_Pointer);
		_delay_ms(20);
		SSD_u8Disable(SSD_Pointer);
		SSD_u8Enable(SSD_Pointer2);
		SSD_u8SetNum(SSD_u8Two ,SSD_Pointer);
		_delay_ms(20);
		SSD_u8Disable(SSD_Pointer2);

	}

}
