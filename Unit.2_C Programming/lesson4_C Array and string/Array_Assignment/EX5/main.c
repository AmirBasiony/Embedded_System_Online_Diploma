/*
 ============================================================================
 Name        : test5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : C Program to search in an element in Array , Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void)
{
	int arr[30];
	int n , i  , element ;
	printf("Enter the number of elements in range(0,30): ");
	fflush(stdout);
	scanf("%d",&n);
	while(n<=0 || n>30)
	{
		printf("Error!! the numbers must be in range (0,30)\n");
		printf("Enter the data again: ");
		fflush(stdout);
		scanf("%d",&n);
	}

	for(i=0;i<n ;i++)
	{
		printf("\nEnter the element %d: ",i+1);
		fflush(stdout);
		scanf("%d",&arr[i]);
	}
	printf("\nElement is\n");
	for(i=0;i<n ;i++)
	{
		printf("%d  ",arr[i]);
	}

	printf("\n\nEnter the element to search  : ");
	fflush(stdout);
	scanf("%d",&element);


	for(i=0;i<n ;i++)
	{
		if(arr[i]== element)
		{
			printf("\n\nNumber found at location = %d",i+1);
			break;
		}
	}
	if(i==n)
	{
		printf("\nWe are Sorry ,Number is not in the list \n");

	}

	return 0;
}
