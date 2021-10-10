#include "init_usart.h"

static uint16_t array[buff_size];

void USART1_IRQHandler(void){
	
	if (USART1->SR & USART_SR_RXNE){
		array[count_element++]	=		(USART1->DR);
	}
	if (USART1->SR & USART_SR_TXE){
		if( count_element==buff_size ){
			USART1->DR		=	sum();
			count_element	=	0;
		}
	}
}

uint16_t	sum(void){
	uint16_t buff = 0;
	for(uint8_t i = 0; i<buff_size; i++){
		USART1->DR	=	buff;
		buff += array[i];
	}
	return buff;
}

uint16_t BRR(uint16_t BAUDR){
	uint16_t DIV_Mantissa			=	( (SystemCoreClock/BAUDR/16)	<<4 );
	uint16_t DIV_Fraction			=	( ((SystemCoreClock/BAUDR)%16)*16	);
	return ( (uint16_t)(DIV_Mantissa|DIV_Fraction) );
}

void init_usart(uint16_t brr){

	RCC->APB2ENR	|= 	RCC_APB2ENR_USART1EN;
	USART1->BRR		= 	BRR(brr);
	USART1->CR1  |= USART_CR1_UE | USART_CR1_TE | USART_CR1_RE | USART_CR1_RXNEIE;
	NVIC_EnableIRQ (USART1_IRQn);
	init_gpio(GPIOA,TX_pin,OUTPUT_ALLTER_PUSH_PULL,OUTPUT_MODE_10MHz);
	init_gpio(GPIOA,RX_pin,INPUT_FLOAT,INPUT_MODE);
	
}
