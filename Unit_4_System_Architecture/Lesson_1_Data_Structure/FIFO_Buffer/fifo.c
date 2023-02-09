/*
 * fifo.c
 *
 *  Created on: ٠٥‏/٠٢‏/٢٠٢٣
 *      Author: Amir
 */
#include"stdio.h"
#include"fifo.h"

FIFO_Buf_status_e FIFO_init(FIFO_buf_t* FIFO_buf , element_type* buf , unsigned int buff_length)
{
	if(buf == NULL)
		return FIFO_NULL;

	FIFO_buf->base = buf;
	FIFO_buf->head = buf;
	FIFO_buf->tail = buf;
	FIFO_buf->length = buff_length;
	FIFO_buf->count = 0;

	return FIFO_no_error;
}
FIFO_Buf_status_e FIFO_enqueue(FIFO_buf_t* FIFO_buf , element_type ENQ_data)
{
	//check if FIFO is valid or not
	if(!FIFO_buf->base || !FIFO_buf->head || !FIFO_buf->tail)
		return FIFO_NULL;

	//check if FIFO is Full
	if(FIFO_IS_Buf_Full(FIFO_buf) != FIFO_no_error)
	{
		return FIFO_IS_Buf_Full(FIFO_buf);
	}
	else
	{
		// Enqueue an element
		*(FIFO_buf->head) = ENQ_data;
		FIFO_buf->count++;

		//if(FIFO_buf->count == FIFO_buf->length)
		if(FIFO_buf->head == (FIFO_buf->base + (FIFO_buf->length * sizeof(element_type))))
			FIFO_buf->head = FIFO_buf->base;
		else
			FIFO_buf->head++;

		return FIFO_no_error;
	}
}

FIFO_Buf_status_e FIFO_dequeue(FIFO_buf_t* FIFO_buf , element_type* DEQ_data)
{
	//check if FIFO is valid or not
	if(!FIFO_buf->base || !FIFO_buf->head || !FIFO_buf->tail)
	{
		printf("==========FIFO is Null==========\n");
		return FIFO_NULL;
	}
	//check if FIFO is empty
	if(FIFO_buf->count == 0)
	{
		printf("==========FIFO is empty==========\n");
		return FIFO_empty;
	}

	//Dequeue an element from FIFO
	*DEQ_data = *(FIFO_buf->tail) ;
	FIFO_buf->count-- ;

	//if(FIFO_buf->tail == FIFO_buf->length)
	if(FIFO_buf->tail == (FIFO_buf->base + (FIFO_buf->length * sizeof(element_type))))
		FIFO_buf->tail = FIFO_buf->base;
	else
		FIFO_buf->tail++;

	return FIFO_no_error;
}
FIFO_Buf_status_e FIFO_IS_Buf_Full(FIFO_buf_t* FIFO_buf)
{
	//check if FIFO is valid or not
	if(!FIFO_buf->base || !FIFO_buf->head || !FIFO_buf->tail)
		return FIFO_NULL;

	if(FIFO_buf->count >= FIFO_buf->length)
	{
		printf("==========FIFO is Full==========\n");
		return FIFO_FULL;
	}
	return FIFO_no_error;
}
void FIFO_Display(FIFO_buf_t* FIFO_buf )
{
	element_type* temp ;
	//check if FIFO is valid or not
	if(!FIFO_buf->base || !FIFO_buf->head || !FIFO_buf->tail)
	{
		printf("==========FIFO is NULL==========\n");
		return FIFO_NULL ;
	}

	//check if FIFO is empty or not
	if(FIFO_buf->count == 0)
	{
		printf("==========FIFO is empty==========\n");
		return FIFO_empty;
	}
	temp = FIFO_buf->tail;
	//print FIFO elements
	printf("==========Display FIFO elements==========\n");
	for(int i=0 ; i< FIFO_buf->count ; i++)
	{
		printf("\t %x \n",*temp);
		temp++;
	}
	printf("==========Display FIFO is done==========\n");

}


