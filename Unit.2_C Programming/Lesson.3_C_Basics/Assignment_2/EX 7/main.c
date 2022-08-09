/*
 ============================================================================
 Name        : EX7.c
 Author      : Amir Elbasiony
 Version     :
 Copyright   : Your copyright notice
 Description :C Program to caculate the factorial , Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{   int n;
unsigned  long int factorial=1;
printf("Enter an integer number : ");
fflush(stdout); fflush(stdin);
scanf("%d",&n);
if(n<0)
{
	printf("Error!!! Factorial number dosen't exist.");
}
else{
	for(int i=n;i>=1;--i)
	{
		factorial *=i;
	}
	printf("Factorial = %lu",factorial);
}
return 0;
}
