/*
 * Interrupt.c
 *
 * Created: 10/07/2023 03:28:17 ص
 *  Author: Amir
 */ 
#include "DIO_interface.h"
#include "Interrupt.h"


void ENT0_init()
{
	Logical_Change_Edge();
	//Enable GICR For ENT0 >> Pin6
	GICR |= (1<<6);
	
	//Enable SREG For Global Interrupt 
	SREG |= (1<<7);
}
void Logical_Change_Edge()
{
	MCUCR |= (01<<0);
}
void Rising_Edge()
{
	MCUCR |= (11<<0);
}
void Falling_Edge()
{
	MCUCR |= (10<<0);
}

void Clear_GIFR_Pin6()
{
	//Enable GIFR For Disable The General Interrupt Flag Register
	GIFR |= (1<<6);	
}

void (* INT0_ISR) (void) = NULL;

void INT0_CallBack(void (* func)(void))
{
	if(func != NULL)
	{
		INT0_ISR = func;
	}
}

void __vector_1 (void)__attribute__((signal));
void __vector_1 (void)
{
	INT0_ISR();
}