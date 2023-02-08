/*
 * fifo.h
 *
 *  Created on: ٠٥‏/٠٢‏/٢٠٢٣
 *      Author: Amir
 */

#ifndef FIFO_H_
#define FIFO_H_

#include"stdio.h"
#include"stdint.h"

//User configuration
//select the element  type (uint8_t , uint16_t , uint32_t , ......)
#define element_type uint8_t

//FIFO data type
typedef struct {
	unsigned int count;
	unsigned int length;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_buf_t;

typedef enum{
	FIFO_no_error,
	FIFO_NULL,
	FIFO_FULL,
	FIFO_empty
}FIFO_Buf_status_e;


//APIs
FIFO_Buf_status_e FIFO_init(FIFO_buf_t* FIFO_buf , element_type* buf , unsigned int length);
FIFO_Buf_status_e FIFO_dequeue(FIFO_buf_t* FIFO_buf , element_type* DEQ_data);
FIFO_Buf_status_e FIFO_enqueue(FIFO_buf_t* FIFO_buf , element_type ENQ_data);
FIFO_Buf_status_e FIFO_IS_Buf_Full(FIFO_buf_t* FIFO_buf);
void FIFO_Display(FIFO_buf_t* FIFO_buf );


#endif /* FIFO_H_ */



