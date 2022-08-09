/*
 ============================================================================
 Name        : EX5.c
 Author      : Amir Elbasiony
 Version     :
 Copyright   : Your copyright notice
 Description : C Program to check is alphabet or not, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char x;
	printf("Enter a Character : ");
	fflush(stdout); fflush(stdin);
	scanf("%c",&x);
	if((x >='a' && x <='z') || (x>='A' && x<='Z'))
	{
		printf("%c is an alphabet ",x);
	}
	else{

		printf("%c is not an alphabet ",x);
	}
	return 0;
}
