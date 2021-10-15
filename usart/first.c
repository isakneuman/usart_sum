#include "first.h"

void magic_function(void){
	//	r_data_position
	//	0		1		2		
	//	x		x		
	if(r_data_position==1){
		
		uint8_t count	=	r_data_count/2;
		for(uint8_t i = 0, j = 0; i <= count; i=i+2){
			t_data_position	=	j;
			t_data[j++]	=	(uint16_t)sum_of_array((r_data+i),SUM_element);
			t_data_count		=	j;
		}
		if(r_data_count%2!=0){
			r_data[0]	=	r_data[r_data_position];	
			r_data_position	=	0;
			r_data_count		=	1;
		}
		else{
			r_data_position	=	r_data_count	=	0;
		}
		flag_for_TXE	=		TRUE;
	}
}
