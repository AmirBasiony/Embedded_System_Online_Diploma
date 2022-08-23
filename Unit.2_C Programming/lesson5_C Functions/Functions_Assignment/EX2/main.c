/*
 * EX2.c
 * Author: Amir Elbasiony
 * Description: C program to calculate factorial of a number using recursion
 */
#include <stdio.h>
 int factorial(int num)
{
     static int fact=1;
     fact *=num;
     num--;
     if(num>0)
     {
    	factorial(num);
     }
     return fact;
}
int main()
{
	int x;
	printf("Enter an positive integer: ");
	fflush(stdout);
	scanf("%d",&x);
    printf("\nFactorial of %d = %d",x,factorial(x));
	return 0;
}
