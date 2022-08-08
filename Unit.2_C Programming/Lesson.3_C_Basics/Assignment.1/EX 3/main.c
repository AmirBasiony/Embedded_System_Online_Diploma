/*
 ============================================================================
 Name        : EX_3.c
 Author      : Amir Elbasiony
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//C Program to Add Two Integers

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int x ,y;
		printf("Enter Two  Integers : ");
		fflush(stdout); fflush(stdin);
		scanf("%d ,\n %d",&x ,&y);
		printf("Sum : %d", x+y );

	return 0;
}
