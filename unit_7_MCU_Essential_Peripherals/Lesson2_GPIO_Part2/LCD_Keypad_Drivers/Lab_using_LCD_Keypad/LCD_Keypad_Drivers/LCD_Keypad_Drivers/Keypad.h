/*
 * Keypad.h
 *
 * Created: 15/07/2023 10:59:04 م
 *  Author: Amir
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO_Interface.h"

#define  KEYPAD_PORT PORTD
#define  DataDir_KEYPAD_PORT DDRD
#define  KEYPAD_PIN PIND
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

void KEYPAD_Init();
char KEYPAD_Get_Char();

#endif /* KEYPAD_H_ */