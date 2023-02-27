/*
  * main.c
 *
 *  Created on: Feb 9, 2023
 *      Author: WAGIH
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "TIMER_interface.h"
#include "GIE_interface.h"
#include <util/delay.h>

void ICU_SW (void);
void LED(void);
static u16 PeridTicks =0 ;
static u16 ONTicks =0 ;

void main(void)
{

	PORT_VoidInit();
	EXTI_Int1SetCallBack(&ICU_SW);
	EXTI_voidInt1Init();
	TIMER1_voidInit();
	TIMER0_voidInit();
	CLCD_voidInit();
	GIE_voidEnable();
	//CLCD_VoidSendString("PeriodTicks= ");
	while(1){


		while(PeridTicks == 0 && ONTicks == 0 ) ;
		CLCD_VoidGoToXY(0,0);
		CLCD_VoidSendString("PeriodTicks=");
		CLCD_voidSendInt(PeridTicks);
		CLCD_VoidGoToXY(1,0);
		CLCD_VoidSendString("ONTicks=");
		CLCD_voidSendInt(ONTicks);

}
}
void ICU_SW (void){
	DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN5,DIO_u8PIN_HIGH);
static u8 Local_u8Counter  = 0 ;
Local_u8Counter ++ ;
if (Local_u8Counter ==1 ){
/*first rising edge*/
TIMER1_voidSetTimerValue(0);


}
else if (Local_u8Counter == 2 ){

/*second rising edge*/
PeridTicks = TIMER1_u16ReadTimerValue();

/*change trigger to falling edge */
EXTI_u8IntSetSenseControl(FALLING_EDGE, INT1);

}
else if (Local_u8Counter==3){

ONTicks = TIMER1_u16ReadTimerValue();
ONTicks -= PeridTicks;
/*disable int0 */
EXTI_IntDisable(INT1);

}

}
