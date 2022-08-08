/*
 ============================================================================
 Name        : EX4.c
 Author      : Amir Elbasiony
 Version     :
 Copyright   : Your copyright notice
 Description : C Program to Multiply two Floating Point Numbers
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
int main()
{    	float x ,y;
printf("Enter Two  Integers : ");
fflush(stdout); fflush(stdin);
scanf("%f  %f",&x ,&y);
printf("Sum : %f", x*y );

return 0;
}
