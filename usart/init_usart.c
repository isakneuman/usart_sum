#include "init_usart.h"
	
void USART1_IRQHandler(void){
	
	if ( USART1->SR & USART_SR_RXNE ){
		if(r_data_count == rbuff_size){
			r_data_count	=	0;
		}
		r_data_position		=	r_data_count;
		if(r_data_position==1){
			GPIOA->BSRR = GPIO_BSRR_BS7;
		}else{
			GPIOA->BRR = GPIO_BRR_BR7;
		}
		r_data[r_data_count++]	=	USART1->DR;
	}
	if ( USART1->SR & USART_SR_TXE	&& flag_for_TXE ){
		GPIOA->ODR ^= GPIO_ODR_ODR7;
		USART1->DR	=	t_data[t_data_position++];
		if(t_data_position == t_data_count){
			flag_for_TXE	=		FALSE;
			t_data_position	=	t_data_count	=	0;
		}
	}
	
}
//	END USART1_IRQHandler



uint16_t BRR(uint16_t BAUDR){
	uint16_t DIV_Mantissa			=	( (SystemCoreClock/BAUDR/16)	<<4 );
	uint16_t DIV_Fraction			=	( ((SystemCoreClock/BAUDR)%16)*16	);
	return ( (uint16_t)(DIV_Mantissa|DIV_Fraction) );
}
//	END BRR

void init_usart(uint16_t brr){

	RCC->APB2ENR	|= 	RCC_APB2ENR_USART1EN;
	USART1->BRR		= 	BRR(brr);
	USART1->CR1  |= USART_CR1_UE | USART_CR1_TE | USART_CR1_RE | USART_CR1_RXNEIE;
	NVIC_EnableIRQ (USART1_IRQn);
	init_gpio(GPIOA,TX_pin,OUTPUT_ALLTER_PUSH_PULL,OUTPUT_MODE_10MHz);
	init_gpio(GPIOA,RX_pin,INPUT_FLOAT,INPUT_MODE);
	
}
//	END init_usart


