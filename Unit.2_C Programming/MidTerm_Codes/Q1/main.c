/*
 ============================================================================
 Name        : Q1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : C function to take a number and sum all digits, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int digits_sum(int );
int main(void) {
	int x;
	printf("Enter an integer number: ");
	fflush(stdout);
	scanf("%d",&x);
	printf("sum of digits = %d",digits_sum(x));
	return 0;
}
int digits_sum(int num)
{
   int sum_digit=0;
   int r;
	while(num>0)
		{
			r=num%10;
			sum_digit +=r;
			num /=10;
		}
	return sum_digit;
}
