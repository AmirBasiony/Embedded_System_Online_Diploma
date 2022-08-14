/*
 ============================================================================
 Name        : EX2.c
 Author      : Amir ELbasiony
 Version     :
 Copyright   : Your copyright notice
 Description : C Program to Find the Length of String without using strlen() Function, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void)
{
	char arr[1000];
	int i;
	int count;
	printf("Enter a string: ");
	fflush(stdout);
	gets(arr);
	for(i=0;i<sizeof(arr)&& arr[i]!=0;i++)
	{
		count++;
	}
	printf("\nLength of string: %d",count);
	return 0;
}
