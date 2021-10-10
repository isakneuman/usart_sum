#include "I2C.h"

uint8_t init_I2C(void){
	
	RCC->APB1ENR 	|=	RCC_APB1ENR_I2C1EN;
	I2C1->OAR2		&=	~I2C_OAR2_ENDUAL;
	I2C1->CR1			&=	~I2C_CR1_ENGC;
	I2C1->CR1			&=	~I2C_CR1_NOSTRETCH;
	I2C1->CR1			&=	~I2C_CR1_PE;
	MODIFY_REG(I2C1->CR2,I2C_CR2_FREQ,36);
	MODIFY_REG(I2C1->TRISE, I2C_TRISE_TRISE, 36 + 1);
	MODIFY_REG(I2C1->CCR, (I2C_CCR_FS | I2C_CCR_DUTY | I2C_CCR_CCR), 180);
	
	
	return 0;
}
