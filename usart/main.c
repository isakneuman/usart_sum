#include "global.h"

int main(){
	
	SystemInit();
	
	// led init
	init_gpio(GPIOB,0,OUTPUT_PUSH_PULL,OUTPUT_MODE_10MHz);
	init_gpio(GPIOA,7,OUTPUT_PUSH_PULL,OUTPUT_MODE_10MHz);
	
	// button init
	init_button(GPIOA,5);
	init_button(GPIOA,6);
	
	// delay iniy
	init_my_delay();
	
	// usart init
	init_usart(9600);
	
	while(1){
		
		magic_function();
		// button test
		if(r_data_position==1){
			GPIOB->ODR ^= GPIO_ODR_ODR0;
		}
		if(button_state1){
			GPIOA->ODR ^= GPIO_ODR_ODR7;
			button_state1 = 0;
		}
		if(button_state2){
			GPIOB->ODR ^= GPIO_ODR_ODR0;
			button_state2 = 0;
		}
		
	}
}

