/*
 ============================================================================
 Name        : EX1.c
 Author      : Amir Elbasiony
 Version     :
 Copyright   : Your copyright notice
 Description : C Program to check the even and odd numbers, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int x;
	printf("Enter an integer number: ");
	fflush(stdout); fflush(stdin);
	scanf("%d" , &x);
	if(x%2 == 0)
	{
		printf("%d is even",x);
	}
	else
	{
		printf("%d is odd",x);
	}
	return 0;
}
