/*
 * Tree_LEDs.c
 *
 * Created: 13/07/2023 08:08:29 م
 * Author : Amir
 */ 

#include <avr/delay.h>
#include "DIO_Interface.h"

int main(void)
{
    DDRD = 0xf0;
    int flag=0;
	while (1) 
    {
		for(flag=5 ; flag<=7 ; flag++)
		{
			PORTD |= (1<<flag);
			_delay_ms(5000);
		}
		for(flag=7 ; flag>=5 ; flag--)
		{
			PORTD &= ~(1<<flag);
			_delay_ms(5000);
		}
    }
}

