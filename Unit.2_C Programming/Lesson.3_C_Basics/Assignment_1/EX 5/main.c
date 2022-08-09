/*
 ============================================================================
 Name        : EX5.c
 Author      : Amir Elbasiony
 Version     :
 Copyright   : Your copyright notice
 Description : C Program to Find ASCII Value of a Character , Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char x ;
	printf("Enter a character: ");
	fflush(stdout); fflush(stdin);
	scanf("%c",&x);
	printf("ASCII value of %c = %d ",x,x);
	return 0;
}
