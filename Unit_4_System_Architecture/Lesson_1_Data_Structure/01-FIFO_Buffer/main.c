/*
 * main.c
 *
 *  Created on: ٠٥‏/٠٢‏/٢٠٢٣
 *      Author: Amir
 */
#include"stdio.h"
#include"fifo.h"
/*
#define printf(...)    fflush(stdin);\
						fflush(stdout);\
						printf(va_agras);\
						fflush(stdin);\
						fflush(stdout);\
*/
//create static buffer
#define buffer_length 5

element_type buffer1[buffer_length];

void main()
{
	unsigned char i;
	element_type data = 0;
	FIFO_Buf_status_e check;
	FIFO_buf_t Uart_buffer;
	
	// initialize FIFO  Buffer
	check = FIFO_init(&Uart_buffer, buffer1, buffer_length);
	switch(check)
	{
	case FIFO_NULL:
		printf("==========initialize FIFO failed!!==========\n");
		break;
	case FIFO_no_error:
		printf("==========initialize FIFO is done==========\n");
		break;
	}
	
	//display FIFO Buffer 
	FIFO_Display(&Uart_buffer);
	
	// Enqueue The Elements in FIFO
	for(i = 0 ; i< buffer_length ; i++)
	{
		check = FIFO_enqueue(&Uart_buffer, i);
		switch(check)
		{
		case FIFO_NULL:
			printf("\t FIFO is NULL!!\n");
			break;
		case FIFO_FULL:
			printf("\t Overload , LIFO is Full!!\n");
			break;
		case FIFO_no_error:
			printf("UART_FIFO Enqueue : %d\n",i);
			break;
		}
	}

	FIFO_Display(&Uart_buffer);

	//dequeue an element
	if(FIFO_dequeue(&Uart_buffer, &data) == FIFO_no_error)
		printf("UART_FIFO Dequeue :%X\n",data);
	//dequeue an element
	if(FIFO_dequeue(&Uart_buffer, &data) == FIFO_no_error)
		printf("UART_FIFO Dequeue :%X\n",data);

	//display FIFO Buffer
	FIFO_Display(&Uart_buffer);
}

