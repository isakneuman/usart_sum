#ifndef _MY_USART
#define _MY_USART
	
	#include "global.h"
	
	#define TX_pin		9
	#define RX_pin		10
	
	#define	rbuff_size		16
	#define	tbuff_size		16
	
	#define TRUE			1
	#define FALSE			0
	
	static 	uint16_t	r_data[rbuff_size];
	static	uint8_t 	r_data_count;
	static	uint8_t 	r_data_position;
	
	static 	uint16_t	t_data[tbuff_size];
	static	uint8_t 	t_data_count;
	static	uint8_t 	t_data_position;
	
	static	uint8_t 	flag_for_TXE;
	static	uint8_t		flag_for_RXNE;
	
	uint16_t BRR(uint16_t);
	
	void 	init_usart(uint16_t brr);
	void	USART1_IRQHandler(void);
	
	void	recieve_function	(void);
	void	transfer_function	(void);
	
#endif