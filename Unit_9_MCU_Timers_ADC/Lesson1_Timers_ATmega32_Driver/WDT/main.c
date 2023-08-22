/*
 * WDT.c
 *
 * Created: 19/08/2023 09:39:25 م
 * Author : Amir
 */ 


#include "WDT.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include <util/delay.h>

#define F_CPU	8000000UL
#define LED_PORT					PORTC
#define LED_Direction				DDRC
#define LED_PIN			 			0

int main(void)
{
	SET_BIT(LED_Direction , LED_PIN);
	_delay_ms(500);
	while (1)
	{
		WDT_ON(WDT_PRESCALER_TimeOut_1s);
		TOGGLE_BIT(LED_PORT , LED_PIN);
		_delay_ms(2000);
		WDT_OFF();
		
	}
}


