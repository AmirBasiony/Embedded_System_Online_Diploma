/**
 ******************************************************************************
 * @file           : main.c
 * Subject		   : TOGGLE_LED
 * Author		   : Amir ELbasiony
******************************************************************************
 */
#include <stdio.h>

#define RCC_BASE 	0x40021000
#define GPIO_BASE 	0x40010800
#define RCC_APB2ENR		*(volatile uint32_t *)(RCC_BASE + 0x18)
#define GPIO_CRH		*(volatile uint32_t *)(GPIO_BASE + 0x04)
#define GPIO_ODR		*(volatile uint32_t *)(GPIO_BASE + 0x0C)

#define SET_PIN_REG(REG,NO_PIN)		(REG |= 1<<NO_PIN)
#define CLR_PIN_REG(REG,NO_PIN)		(REG &= ~(1<<NO_PIN))

typedef union{
	volatile unsigned int	all_fields;
	struct{	
		volatile unsigned int	reserved:13;
		volatile unsigned int	p_13:1;
	}pin;
}R_ODR_t;
  
volatile R_ODR_t* R_ODR	=(volatile R_ODR_t *)(GPIO_BASE + 0x0C);
unsigned char g_variable[3] = {1,2,3,};
unsigned char  const  const_variable[3] ={1,2,3};
volatile unsigned char bss_var;
int main(void) 
{
	SET_PIN_REG(RCC_APB2ENR,2);	// Make GPIO Enable (by set pin2)

	GPIO_CRH &= 0xff0fffff;
	GPIO_CRH |= 0x00200000;	// Set pin13 in GPIO_CRH  (Direction)

	while(1)
	{
		//SET_PIN_REG(GPIO_ODR,13);
		R_ODR->pin.p_13 = 1;
		for(int i=0;i<5000;i++);	// delay
		//CLR_PIN_REG(GPIO_ODR,13);
		R_ODR->pin.p_13 = 0;
		for(int i=0;i<5000;i++);	// delay
	}
}
