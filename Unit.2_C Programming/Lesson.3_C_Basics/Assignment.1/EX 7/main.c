/*
 ============================================================================
 Name        : EX7.c
 Author      : Amir Elbasiony
 Version     :
 Copyright   : Your copyright notice
 Description :  C Program Code to Swap Two Numbers without temp variable., Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void) {
	float a,b;
	printf(" Enter value of a: ");
	fflush(stdout); fflush(stdin);
	scanf("%f",&a);
	printf("\n Enter value of b: ");
	fflush(stdout); fflush(stdin);
	scanf("%f",&b);
    b=a-b; //Subtract the first number (a) from the second number(b) and store it in (b)
    a=a-b; //Subtract the first number (a) from the difference between the two numbers (b) and store it in (a)
    b=a+b; //Add the first number(a) with the difference between the two numbers (b) and store it in (b)
	printf("\n After swapping, value of a = %.2f",a);
	printf("\n After swapping, value of b = %.2f",b);
	return 0;
}
