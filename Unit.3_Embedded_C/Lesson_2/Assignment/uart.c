#include "uart.h"

#define UART0DR   *((volatile unsigned char *)((unsigned char *)0x101f1000))

void Uart_Send_String(unsigned char * ptr_tx_string)
{
	// Loop until end of string 
	while(*ptr_tx_string != '\0')
	{
		UART0DR = (unsigned int)(*ptr_tx_string); // transmit char
		ptr_tx_string++ ; // next char
	}
}