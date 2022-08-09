/*
 ============================================================================
 Name        : EX2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : C Program to check vowel or consonant, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char x;
	printf("Enter an alphabet: ");
	fflush(stdout); fflush(stdin);
	scanf("%c",&x);
	((x=='a')||(x=='A')||(x=='i')||(x=='I')||(x=='o')||(x=='O')||(x=='u')||(x=='U')||
			(x=='y')||(x=='Y') ? printf("%c is vowel",x):printf("%c is consonant",x));

	return 0 ;
}
