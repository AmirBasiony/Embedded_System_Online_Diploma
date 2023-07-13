/*
 * Lab2_Buzzer.c
 *
 * Created: 11/07/2023 08:56:09 م
 * Author : Amir
 */ 
#include <avr/io.h>
#include <avr/delay.h>

#define PORTD *((volatile unsigned char *)(0x32))
#define DDRD  *((volatile unsigned char *)(0x31))

int main(void)
{
	DDRD = 0x0FF; // Output Direction
	PORTD = 0x00;
     while (1) 
    {
		// Led 1
		PORTD |= (1<<5); // ON
		_delay_ms(5000);	
		PORTD &= ~(1<<5);// OFF
		_delay_ms(5000);
		// Led 2
		PORTD |= (1<<6);// ON
		_delay_ms(5000);
		PORTD &= ~(1<<6);// OFF
		// Led 3
		_delay_ms(5000);
		PORTD |= (1<<7);// ON
		_delay_ms(2000);
		PORTD &= ~(1<<7);// OFF
		// Buzzer
		_delay_ms(5000);
		PORTD |= (1<<4);// Buzzer ON
		_delay_ms(5000);
		PORTD &= ~(1<<4);// OFF
		PORTD = 0x00;
		_delay_ms(5000);
    }
}

