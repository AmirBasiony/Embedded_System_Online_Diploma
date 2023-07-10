/*
 * DIO_Interface.h
 *
 * Created: 10/07/2023 03:39:30 ص
 *  Author: Amir
 */ 



#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#define PORTD  *((volatile unsigned char *)0x32)
#define DDRD   *((volatile unsigned char *)0x31)
#define PIND   *((volatile unsigned char *)0x30)

#endif /* DIO_INTERFACE_H_ */