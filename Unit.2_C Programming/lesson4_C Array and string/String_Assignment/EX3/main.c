/*
 ============================================================================
 Name        : EX3.c
 Author      : Amir ELbasiony
 Version     :
 Copyright   : Your copyright notice
 Description : C Program to Reverse string without , Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
int main(void){
	char x[1000];
	int i,j;

	printf("Enter a string: ");
	fflush(stdout);
	gets(x);
	//first method
	for(i=0,j=strlen(x)-1;i<j;i++,j--)
	{
		x[i]=x[i]+x[j];
		x[j]=x[i]-x[j];
		x[i]=x[i]-x[j];
	}
	printf("Reverse string is : %s",x);

	//Second method
	/*for(i=0,j=strlen(x)-1;i<j;i++,j--)
	{
		temp = x[i];
		x[i]=x[j];
		x[j]=temp;
	}
	printf("Reverse string is : %s",x);*/
	return 0;
}
