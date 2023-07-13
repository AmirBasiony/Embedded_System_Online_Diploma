/*
 * TreeLEDsSwitchControl.c
 *
 * Created: 13/07/2023 08:20:27 م
 * Author : Amir
 */ 

#include <avr/delay.h>
#include "DIO_Interface.h"

int main(void)
{
	DDRD = 0xE0;
	char LED_CountUP = 0,LED_CountDOWN=0;
    while(1) 
    {		
		//More LEDs ON
		if( (((PIND>>0)&1) == 1) && (LED_CountUP < 3) )
		{
			switch(LED_CountUP)
			{
				case 0:
					PORTD |= (1<<5);
					LED_CountUP++;
				break;
				case 1:
					PORTD |= (1<<6);
					LED_CountUP++;
				break;
				case 2:
					PORTD |= (1<<7);
					LED_CountUP++;
				break;
			}
			LED_CountDOWN = LED_CountUP - 1;
			while(((PIND>>0)&1) == 1 );
		}
		//More LEDs OFF
		if( ( ((PIND>>1)&1) == 1) && (LED_CountDOWN >= 0))
		{
			switch(LED_CountDOWN)
			{
				case 0:
				PORTD &= ~(1<<5);
				LED_CountDOWN--;
				break;
				case 1:
				PORTD &= ~(1<<6);
				LED_CountDOWN--;
				break;
				case 2:
				PORTD &= ~(1<<7);
				LED_CountDOWN--;
				break;
			}
			LED_CountUP = LED_CountDOWN + 1;
			while(((PIND>>1)&1) == 1 );
		}
	}
}
