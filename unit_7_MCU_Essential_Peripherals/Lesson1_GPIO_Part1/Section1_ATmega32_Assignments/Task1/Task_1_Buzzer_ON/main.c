/*
 * Task_1_Buzzer_ON.c
 *
 * Created: 13/07/2023 07:22:17 م
 * Author : Amir
 */ 

#include <avr/delay.h>

#include "DIO_Interface.h"

int main(void)
{
   DDRD &= ~(1<<0);
   DDRD |= (1<<4);
   
    while (1) 
    {
		if( ((PIND>>0)&1) == 1)
		{
			PORTD |= (1<<4);
			_delay_ms(5000);
			PORTD &= ~(1<<4);
			//_delay_ms(5000); // Multi Press
			while( ((PIND>>0)&1) == 1); // Single Press
		}
		
    }
}

