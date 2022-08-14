/*
 ============================================================================
 Name        : EX3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void)
{
	int i,j,r,c;
	int x[10][10];
	int y[10][10];
	printf("Enter the number rows of the matrix:");
	fflush(stdout);
	scanf("%d",&r);
	if(r<=0)
	{
		printf("Error!! the numbers must be positive number and not equal (0)\n");
		printf("Enter the data again: ");
		fflush(stdout);
		scanf("%d",&r);
	}
	printf("\nEnter the number columns of the matrix:");
	fflush(stdout);
	scanf("%d",&c);
	if(c<=0)
	{
		printf("Error!! the numbers must be positive number and not equal (0)\n");
		printf("Enter the data again: ");
		fflush(stdout);
		scanf("%d",&c);
	}
	printf("\n===================================\n");
	printf("\nEnter the elements of  matrix \n");
	fflush(stdout);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("Enter element a%d%d:  ",i+1,j+1);
			fflush(stdout);
			scanf("%d",&x[i][j]);

		}
	}
	printf("\n\nEntered Matrix:\n");
	fflush(stdout);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",x[i][j]);

		}
		printf("\n");
	}

	printf("\n\nTranspose of Matrix:\n");
	fflush(stdout);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			y[j][i] =x[i][j];

		}
	}
	//first method to display transpose matrix
	for(j=0;j<c;j++)
	{
		for(i=0;i<r;i++)
		{
			printf("%d\t",y[j][i]);

		}
		printf("\n");
	}

	//second method to display transpose matrix
	/*
   for(i=0;i<c;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("%d\t",y[i][j]);

		}
		printf("\n");
	}
	 */



	return 0;
}
