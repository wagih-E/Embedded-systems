/************************************************************************/
/************************************************************************/
/***********************	author: Ahmed wagih	    *********************/
/***********************	Layer:  MCAL	        *********************/
/***********************	SWC:	DIO	            *********************/
/***********************	Version:1.00	        *********************/
/************************************************************************/
/************************************************************************/
#ifndef CLDC_INTERFACE_H_
#define CLDC_INTERFACE_H_

void CLCD_voidSendCommand(u8 Copy_u8Command);

void CLCD_voidSendData(u8 Copy_u8Data);

void CLCD_voidInit(void);

void CLCD_VoidSendString(const char* Copy_pcString);

void CLCD_VoidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos);

void CLCD_VoidWriteSpecialCha(u8* copy_pu8Pattern , u8 Copy_u8PatternNumber ,u8 Copy_u8XPos ,u8 Copy_u8YPos);
void CLCD_voidsendnumber(u32 copy_u32number);
void CLCD_voidSendInt(u8 Copy_u8Int);
#endif
