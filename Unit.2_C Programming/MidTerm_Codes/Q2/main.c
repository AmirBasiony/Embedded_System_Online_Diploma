/*
 ============================================================================
 Name        : Q2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

float sqrt_num(const float m)
{
	float i=0;
	float x1,x2;
	while( (i*i) <= m )
		i+=0.1f;
	x1=i;
	for(int j=0;j<10;j++)
	{
		x2=m;
		x2/=x1;
		x2+=x1;
		x2/=2;
		x1=x2;
	}
	return x2;
}
int main(void)
{
	int num;
	printf("Enter a number to calculate square root: ");
	fflush(stdout);
	scanf("%d",&num);
	printf("square root of %d = %.3f ",num,sqrt_num(num));

	return 0;
}
