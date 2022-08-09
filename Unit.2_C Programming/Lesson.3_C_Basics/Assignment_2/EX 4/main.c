/*
 ============================================================================
 Name        : EX4.c
 Author      : Amir Elbasiony
 Version     :
 Copyright   : Your copyright notice
 Description : C Program to check whether the number is Positive or Negative, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void)
{
	float x;
	printf("Enter the number: ");
	fflush(stdout); fflush(stdin);

	scanf("%f ",&x);
	if(x>0)
	{

		printf("%.2f is Positive ",x);

	}
	else if(x<0)
	{
		printf("%.2f is Negative ",x);
	}
	else
	{
		printf("%.2f is Zero ",x);
	}


	return 0 ;
}
