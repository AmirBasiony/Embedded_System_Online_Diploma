#include "uart.h"
#define UART0DR    *((volatile unsigned int* const)((unsigned int*)0x101f1000))

void Uart_Send_string(unsigned char* P_tx_string)
{
	while(*P_tx_string != '\0') // if the string not empty
	{
		UART0DR = (unsigned int)(*P_tx_string); // assign the current char in UART0DR
		P_tx_string++; // increment the pointer to point to the next character
	}
}