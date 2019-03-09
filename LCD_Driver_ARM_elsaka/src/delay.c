
#include "../include/STD_TYPES.h"

void delay_millisecond (u16 u16Time)
{
	u16 i,j ;
	for(j=0;j<u16Time;j++){
		for(i=0;i<295;i++){
			asm("NOP");
			asm("NOP");
			asm("NOP");
			asm("NOP");
			asm("NOP");
			asm("NOP");
			asm("NOP");
			asm("NOP");
		}
	}

}
