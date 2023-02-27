/************************************************************************/
/************************************************************************/
/***********************	author: Ahmed wagih	    *********************/
/***********************	Layer:  MCAL	        *********************/
/***********************	SWC:	TIMER	        *********************/
/***********************	Version:1.00	        *********************/
/************************************************************************/
/************************************************************************/


#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H
void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value);
void TIMER0_voidInit();

void TIMER1_voidSetICR(u16 copy_u16TOP);

void TIMER1_voidInit();
void TIMER1_voidSetCompMatchValue(u16 Copy_u16Value);
void SERVO_voidAngle(u8 Copy_u8Angle);
void TIMER1_voidSetTimerValue(u16 Copy_u16Value);
u16  TIMER1_u16ReadTimerValue(void);

u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));


#endif
