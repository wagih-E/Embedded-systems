/*
 * main.c
 *
 *  Created on: Feb 9, 2023
 *      Author: WAGIH
 */
#include <util/delay.h>
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "ADC_interface.h"
#include "GIE_interface.h"

void ADCNotification (void);


u8  Local_u8ADCReading;
u16 Local_u16mvReading;
u8  Local_u8Temp ;

void main(void){



	PORT_VoidInit();
	CLCD_voidInit();
	ADC_voidInit();
	GIE_voidEnable();
	while(1){
		ADC_u8StartConversionAsynch(0, &Local_u8ADCReading,&ADCNotification);
		_delay_ms(1);
		/* ADC_u8StartConversionSynch(0,&Local_u8ADCReading);
		 Local_u16mvReading = (u16)((u32)Local_u8ADCReading*5000)/256;
		 	Local_u8Temp = Local_u16mvReading/10;

		 	CLCD_voidSendInt(Local_u8Temp);
		 	CLCD_VoidSendString("C");
		 	_delay_ms(1000);

		 	CLCD_voidSendCommand(1);*/
	}



}


void ADCNotification (void){
	Local_u16mvReading = (u16)((u32)Local_u8ADCReading*5000)/256;
	Local_u8Temp = Local_u16mvReading/10;

	CLCD_voidSendInt(Local_u8Temp);
	CLCD_VoidSendString("C");
	_delay_ms(2000);

	CLCD_voidSendCommand(1);

}
