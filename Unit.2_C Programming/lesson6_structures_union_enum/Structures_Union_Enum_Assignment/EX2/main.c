/*
 * main.c
 *
 *  Author: Amir Elbasiony
 *  Subject:C Program to Two Distances(in inch-feet)System Using Structure
 */

#include<stdio.h>
#define conv_inch  (1/12.0)
struct SDistance
{
	float m_inch;
	float m_feet;
}d1,d2,sum;

int main()
{
	float sum =0.0;
	printf("Enter information for 1st distance :\n\n");
	printf("Enter feet: ");
	fflush(stdout);
	scanf("%f",&d1.m_inch);
	printf("Enter inch: ");
	fflush(stdout);
	scanf("%f",&d1.m_feet);
	printf("Enter information for 2nd distance :\n\n");
	printf("Enter feet: ");
	fflush(stdout);
	scanf("%f",&d2.m_inch);
	printf("Enter inch: ");
	fflush(stdout);
	scanf("%f",&d2.m_feet);
	sum+=(d1.m_inch) + (d1.m_feet)+(conv_inch*d2.m_inch) + (d2.m_feet);
	printf("\nSum of Distance = %.2f feet\n",sum);

	return 0;
}




