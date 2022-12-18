#include "uart.h"
unsigned char string_buffer[100] = "learn_in_depth:Amir";
unsigned char const string_buffer2[100] = "learn_in_depth:Amir";
void main (void)
{
	Uart_Send_string (string_buffer);	
}