/*
 ============================================================================
 Name        : EX6.c
 Author      : Amir Elbasiony
 Version     :
 Copyright   : Your copyright notice
 Description :  C Program to Swap Two Numbers, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float a,b,z;
	printf(" Enter value of a: ");
	fflush(stdout); fflush(stdin);
	scanf("%f",&a);
	printf("\n Enter value of b: ");
	fflush(stdout); fflush(stdin);
	scanf("%f",&b);
	z=a;  a=b;	b=z;
	printf("\n After swapping, value of a = %.2f",a);
	printf("\n After swapping, value of b = %.2f",b);
	return 0;
}
