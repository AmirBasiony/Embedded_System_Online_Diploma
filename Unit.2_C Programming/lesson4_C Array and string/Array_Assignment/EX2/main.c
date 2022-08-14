/*
 ============================================================================
 Name        : EX2.c
 Author      : Amir Elbasiony
 Version     :
 Copyright   : Your copyright notice
 Description : C Program to calculate the average of Array, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void)
{
	float arr[100];
	int n ,i;
	float Avr , sum =0.0;
	printf("Enter the number of data in range(0,100): ");
	fflush(stdout);
	scanf("%d",&n);
	if(n<=0 || n>100)
	{
		printf("Error!! the numbers must be in range (0,100)\n");
		printf("Enter the data again: ");
		fflush(stdout);
		scanf("%d",&n);
	}
	for(i=0;i<sizeof(arr) && i!=n ;i++)
	{

		printf("%d. Enter number: ",i+1);
		fflush(stdout);
		scanf("%f",&arr[i]);
		sum += arr[i];
	}

	Avr=sum/n;
	printf("Average = %.2f",Avr);


	return 0;
}


