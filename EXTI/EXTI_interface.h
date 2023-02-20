/************************************************************************/
/************************************************************************/
/***********************	author: Ahmed wagih	    *********************/
/***********************	Layer:  MCAL	        *********************/
/***********************	SWC:	EXTI            *********************/
/***********************	Version:1.00	        *********************/
/************************************************************************/
/************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define LOW_LEVEL		1
#define ON_CHANGE  	    2
#define FALLING_EDGE    3
#define RISING_EDGE     4

void EXTI_voidInt0Init(void);

void EXTI_voidInt1Init(void);


/*descripe :function to set sense ctrl of int using post build conf
options : * 1-LOW_LEVEL
 	 	  * 2-ON_CHANGE
          * 3-RISING_EDGE
          * 4-FALING_EDGE

output : error state with state u8
*/
u8 EXTI_u8IntSetSenseControl(u8 Copy_u8Sense,u8 Copy_u8IntPin);
#define INT0 0
#define INT1 1


u8 EXTI_IntEnable(u8 Copy_u8Int);
u8 EXTI_IntDisable(u8 Copy_u8Int);

u8 EXTI_Int0SetCallBack(void(*Copy_pvInt0Func)(void));

u8 EXTI_Int1SetCallBack(void(*Copy_pvInt1Func)(void));










#endif // EXTI_INTERFACE_H_




