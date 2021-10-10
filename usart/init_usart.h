#ifndef _USART
#define _USART
	
	#include "global.h"
	
	#define TX_pin		9
	#define RX_pin		10
	#define buff_size	2
	
	static uint8_t count_element;
	
	uint16_t BRR(uint16_t);
	uint16_t	sum(void);
	void init_usart(uint16_t brr);
	void send(void);
	void USART1_IRQHandler(void);
	
#endif