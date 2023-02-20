/************************************************************************/
/************************************************************************/
/***********************	author: Ahmed wagih	    *********************/
/***********************	Layer:  MCAL	        *********************/
/***********************	SWC:	DIO	            *********************/
/***********************	Version:1.00	        *********************/
/************************************************************************/
/************************************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

typedef struct{
	u8 Comm_Type ;
	u8 Port ;
	u8 EnablePort ;
	u8 EnablePin ;
}SSD_t;

#define SSD_ComAnode 1
#define SSD_ComCathode 0

#define SSD_u8Zero 0
#define SSD_u8One 1
#define SSD_u8Two 2
#define SSD_u8Three 3
#define SSD_u8Four 4
#define SSD_u8Five 5
#define SSD_u8Six 6
#define SSD_u8Seven 7
#define SSD_u8Eight 8
#define SSD_u8Nine 9

#define SSD_u8Numbers 10
u8 SSD_u8SetNum(u8 SSD_u8Number ,SSD_t* SSD_P);
u8 SSD_u8Enable(SSD_t* SSD_P);
u8 SSD_u8Disable(SSD_t* SSD_P);


#endif /* SSD_INTERFACE_H_ */
