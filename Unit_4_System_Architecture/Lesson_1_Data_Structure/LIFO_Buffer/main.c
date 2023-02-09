/*
 * main.c
 *
 *  Created on: ٠٥‏/٠٢‏/٢٠٢٣
 *      Author: Amir
 */
#include<stdio.h>
#include"lifo.h"
#include<stdlib.h>

//create static buffer
#define buffer_length 5

element_type buffer1[buffer_length];

int main()
{
	int i ,check;
	unsigned temp = 0;
	LIFO_Buf_t uart_lifo , I2C_lifo ;
	//static allocation
	//initialization of UART LIFO
	check = LIFO_init(&uart_lifo, buffer1, 5);
	switch(check)
	{
	case LIFO_Null:
		printf("Error , LIFO is NULL\n");
		break;
	case LIFO_no_error:
		printf("UART_LIFO is initialized successfully \n");
	}
	//dynamic allocation
	unsigned int* buffer2 = (unsigned int*)malloc(buffer_length * sizeof(unsigned int));
	//Initialization of I2C LIFO
	check = LIFO_init(&I2C_lifo, buffer2, 5);
	switch(check)
	{
	case LIFO_Null:
		printf("Error , LIFO is NULL\n");
		break;
	case LIFO_no_error:
		printf("I2C_LIFO is initialized successfully \n");
	}

	// Push Elements in LIFO
	for(i = 0; i < 7 ; i++)
	{
		check =LIFO_add_item(&uart_lifo, i);
		switch(check)
		{
		case LIFO_Null:
			printf("Error , LIFO is NULL\n");
			break;
		case LIFO_full:
			printf("Overload , LIFO is Full\n");
			break;
		case LIFO_no_error:
			printf("UART_LIFO add : %d\n",i);
			break;
		}
	}
	// Display LIFO Element
	LIFO_Display(&uart_lifo);
	
	// Pop Elements from LIFO
	for(i = 0; i < 7 ; i++)
	{
		check = LIFO_get_item(&uart_lifo, &temp);
		switch(check)
		{
		case LIFO_Null:
			printf("Error , LIFO is NULL\n");
			break;
		case LIFO_empty:
			printf("underload , LIFO is Empty\n");
			break;
		case LIFO_no_error:
			printf("UART_LIFO get : %d\n",temp);
			break;
		}
	}
	// Display LIFO Element
	LIFO_Display(&uart_lifo);
	return 0;
}







