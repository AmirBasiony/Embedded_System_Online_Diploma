/*
 * Lab2InterruptATmega32.c
 *
 * Created: 10/07/2023 03:26:14 ص
 * Author : Amir
 */ 

#include <avr/io.h>
#include <avr/delay.h>

#include "DIO_interface.h"
#include "Interrupt.h"


void ISR0()
{
	PORTD |= (1<<6); // Make The LED HIGH
	_delay_ms(10000);	
	Clear_GIFR_Pin6(); 
}
int main(void)
{
	ENT0_init();
	INT0_CallBack(ISR0);
    
	DDRD &= ~(1<<2); //INTPUT >> 0	 For INT0
	DDRD |= (1<<6); //OUTPUT >> 1    For LED
	
	
	/* Replace with your application code */
    while (1) 
    {
		PORTD &= ~(1<<6); // Make The LED LOW
		_delay_ms(1000);
    }
}

