/*
 * lifo.c
 *
 *  Created on: 05/02/2023
 *      Author: Amir
 */
#include<stdio.h>
#include"lifo.h"

LIFO_status_e LIFO_init(LIFO_Buf_t* lifo_buf , element_type* buf , unsigned int length)
{
	//check LIFO valid
	if(buf == NULL)
		return LIFO_Null;

	lifo_buf->base = buf;
	lifo_buf->head = buf;
	lifo_buf->length = length;
	lifo_buf->count = 0;

	return LIFO_no_error;
}

LIFO_status_e LIFO_add_item(LIFO_Buf_t* lifo_buf , element_type item)
{
	//check if LIFO is valid
	if(!lifo_buf->base || !lifo_buf->head)
		return LIFO_Null;

	//check if LIFO is full
	//if(lifo_buf->head >= (lifo_buf->base + (lifo_buf->length * 4)))
	if(lifo_buf->count == lifo_buf->length)
		return LIFO_full;

	// Add/Push an item
	*(lifo_buf->head) = item;
	lifo_buf->head++;
	lifo_buf->count++;

	return LIFO_no_error;
}
LIFO_status_e LIFO_get_item(LIFO_Buf_t* lifo_buf , element_type *item)
{
	//check if LIFO is valid
	if(!lifo_buf->base || !lifo_buf->head)
		return LIFO_Null;

	//check if LIFO is empty
	//if(lifo_buf->head == lifo_buf->base)
	if(lifo_buf->count == 0)
		return LIFO_empty;

	// get/Pop an item
	lifo_buf->head--;
	*item = *(lifo_buf->head);
	lifo_buf->count--;

	return LIFO_no_error;
}
void LIFO_Display(LIFO_Buf_t* lifo_buf)
{
	element_type* temp = lifo_buf->head - 1;
	//check if LIFO is valid
	if(!lifo_buf->base || !lifo_buf->head)
	{
		printf("\n==========FIFO is NULL==========\n");
		return LIFO_Null;
	}
	if(lifo_buf->count == 0)
	{
		printf("\n==========FIFO is empty==========\n");
		return LIFO_empty;
	}
	//print FIFO elements
	printf("\n==========Display FIFO elements==========\n");
	for(int i = 0  ; i < lifo_buf->count ; i++)
	{
		printf("\t %X \n",*temp);
		temp--;
	}
	printf("\n==========Display FIFO is done==========\n");

}
