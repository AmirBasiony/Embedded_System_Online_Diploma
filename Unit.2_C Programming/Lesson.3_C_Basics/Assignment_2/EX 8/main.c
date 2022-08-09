/*
 ============================================================================
 Name        : EX8.c
 Author      : Amir ELbasiony
 Version     :
 Copyright   : Your copyright notice
 Description : C Program to make Simple Calculator, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float x,y,z;
	char op;

	printf("Enter two operands: ");
	fflush(stdout); fflush(stdin);
	scanf("%f  %f", &x,&y);
	printf("Enter operator either + or - or * or divide : ");
	fflush(stdout); fflush(stdin);
    scanf("%c", &op);
	switch (op)
	{
	case '+':
	{
		z = x+y;
		printf("%.1f + %.1f = %.1f ",x,y,z);
	}
	break;
	case '-':
	{
		z = x-y;
		printf("%.1f - %.1f = %.1f ",x,y,z);
	}
	break;
	case '*':
	{
		z = x*y;
		printf("%.1f * %.1f = %.1f ",x,y,z);
	}
	break;
	case '/':
	{
		z = x/y;
		printf("%.1f / %.1f = %.1f ",x,y,z);
	}
	break;
	default:
	{
		printf("Error!!!");
	}

	}
	return 0;
}
