/*
 ============================================================================
 Name        : EX1.c
 Author      : Amir ELbasiony
 Version     :
 Copyright   : Your copyright notice
 Description : C Program to Find the Frequency of characters in a String, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void)
{
	char x[50];
	char c;
	char freq=0;
	int i;
	printf("Enter a string: ");
	fflush(stdout);
	gets(x);
	printf("\n\nEnter a character to find frequency: ");
	fflush(stdout);
	scanf("%c",&c);
	for(i=0;i<sizeof(x)&& x[i]!=0;i++)
	{
		if(x[i]==c)
		{
			freq++;
		}
	}
	printf("\n\nFrequency of %c = %d",c,freq);
	return 0;
}

