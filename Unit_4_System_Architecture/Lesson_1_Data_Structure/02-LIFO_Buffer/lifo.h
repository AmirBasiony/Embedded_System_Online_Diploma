/*
 * lifo.h
 *
 *  Created on: ٠٥‏/٠٢‏/٢٠٢٣
 *      Author: Amir
 */

#ifndef LIFO_H_
#define LIFO_H_

#include"stdint.h"
//User configuration
//select the element  type (uint8_t , uint16_t , uint32_t , ......)
#define element_type uint32_t

//Type Definitions
typedef struct {
	unsigned int length;
	unsigned int count;
	element_type* base;
	element_type* head;
}LIFO_Buf_t;

typedef enum{
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_Null
}LIFO_status_e;

//APIs
LIFO_status_e LIFO_add_item(LIFO_Buf_t* lifo_buf , element_type item);
/*
 * LIFO_add_item Function *
 * is used to push the elements in LIFO
 * 1- check if LIFO is valid or not
 * 2- check if LIFO is Full or not
 * 3- Push a new element in The LIFO
 */
LIFO_status_e LIFO_get_item(LIFO_Buf_t* lifo_buf , element_type *item);
/*
 * LIFO_get_item Function *
 * is used to pop the elements from LIFO
 * 1- check if LIFO is valid or not
 * 2- check if LIFO is Full or not
 * 3- Pop  from LIFO an element
 */
LIFO_status_e LIFO_init(LIFO_Buf_t* lifo_buf , element_type* buf , unsigned int length);
/*
 * LIFO_init Function *
 * is used to initialize LIFO
 */
void LIFO_Display(LIFO_Buf_t* lifo_buf);
#endif /* LIFO_H_ */
