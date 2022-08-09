/*
 ============================================================================
 Name        : EX3.c
 Author      : Amir Elbasiony
 Version     :
 Copyright   : Your copyright notice
 Description :C Program to Find the largest number among three numbers , Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void)
{
	float x,y,z;
	printf("Enter three number: ");
	fflush(stdout); fflush(stdin);
	scanf("%f %f %f",&x,&y,&z);
	((x>y)&&(x>z)) ?  printf("\nLarge number = %.4f",x) :
			(y>z) ? printf("\nLarge number = %.4f",y) : printf("\nLarge number = %.4f",z) ;


	return 0;
}
