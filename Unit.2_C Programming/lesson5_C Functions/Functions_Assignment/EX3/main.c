/*
 * EX3.c
 * Author: Amir Elbasiony
 * Description: C program to reverse a sentence using recursion
 */
#include <stdio.h>

void Reverse();

int main()
{
	printf("Please enter a sentence: ");
	fflush(stdout);
	printf("The reversed sentence: ");
	Reverse();
	return 0;
}
void Reverse()
{
	char c;
	scanf("%c", &c);
	if (c != '\n')
	{
		{
			Reverse();
		}
		printf("%c", c);
	}
}
