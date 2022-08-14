/*
 ============================================================================
 Name        : EX4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description :C Program to insert an element in an Array, Ansi-style
 ============================================================================
 */

#include <stdio.h>
int main(void) {
	int arr[30];
	int n , i , location , element ;
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
	printf("\nelement is\n");
	for(i=0;i<n ;i++)
	{
		printf("%d  ",arr[i]);
	}

	printf("\nEnter the element to be inserted: ");
	fflush(stdout);
	scanf("%d",&element);

	printf("\nEnter the location: ");
	fflush(stdout);
	scanf("%d",&location);
	//make space to the new element with specified location
	for(i=n ; i>=location ; i--)
	{
		arr[i]=arr[i-1];
	}
	//now i = location - 1
	n++;
	arr[i]=element; //arr[location-1]=element
	for(i=0;i<n ;i++)
	{
		printf("%d  ",arr[i]);
	}

	return 0;
}
