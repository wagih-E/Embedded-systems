#include<avr/io.h>
#include<util/delay.h>
#include"STD_types.h"
#include"bitwise.h"
void main(){
	DDRD=0xff;
		u8 arr[10]= {0b0111111,0b0000110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b0100111,0b1111111,0b1101111};

CLR_BIT(DDRC,0);
SET_BIT(PORTC,0);
u8 count = 0 ;
while(1){
u8 x = GET_BIT(PINC,0);
_delay_ms(300);
if(x==1){
PORTD=arr[count];}

if (x==0 ){
	PORTD=arr[count+1];
	count++;

}










}
}
