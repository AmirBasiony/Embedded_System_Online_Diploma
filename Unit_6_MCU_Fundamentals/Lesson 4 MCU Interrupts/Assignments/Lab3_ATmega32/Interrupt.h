/*
 * Interrupt.h
 *
 * Created: 10/07/2023 03:28:37 ص
 *  Author: Amir
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#define NULL 0
#define GICR  (*(volatile unsigned char *)(0x5B))
#define GIFR  (*(volatile unsigned char *)(0x5A))
#define SREG  (*(volatile unsigned char *)(0x5F))
#define MCUCR  (*(volatile unsigned char *)(0x55))

void ENT0_init();
void Clear_GIFR_Pin6();
void Logical_Change_Edge();
void Falling_Edge();
void Rising_Edge();
void INT0_CallBack(void (* func)(void));

#endif /* INTERRUPT_H_ */