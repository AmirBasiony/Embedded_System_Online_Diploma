/*
 ============================================================================
 Name        : EX1.c
 Author      : Amir Elbasiony
 Version     :
 Copyright   : Your copyright notice
 Description :C Program to find sum of two matrix of order 2*2 using 2D Array, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void)
{
	float x[2][2];
	float y[2][2];
	float z[2][2];
	int i,j;
	printf("Enter the elements of 1st matrix \n");
	fflush(stdout);
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("Enter a%d%d:  ",i+1,j+1);
			fflush(stdout);
			scanf("%f",&x[i][j]);

		}
	}
	printf("\nEnter the elements of 2nd matrix \n");
	fflush(stdout);
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("Enter b%d%d:  ",i+1,j+1);
			fflush(stdout);
			scanf("%f",&y[i][j]);

		}
	}
	printf("\nSum of matrix:\n");
	fflush(stdout);
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			z[i][j] = x[i][j] + y[i][j] ;
		}
	}
	fflush(stdout);
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%.1f\t",z[i][j]);
		}
		printf("\n");
	}

	return 0;
}
