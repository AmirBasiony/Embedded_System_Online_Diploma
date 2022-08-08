/*
 ============================================================================
 Name        : firstProg.c
 Author      : Amir Elbasiony
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//C Program to Print a Integer Entered by a User

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int x;
	printf("Enter an integer : ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&x);
	printf("You entered : %d",x);
	return 0;
}
