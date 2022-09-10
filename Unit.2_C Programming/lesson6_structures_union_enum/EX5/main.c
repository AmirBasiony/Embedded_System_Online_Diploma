/*
 * main.c
 *
 *  Author: Amir Elbasiony
 *  Subject:C Program to find the area of circle,passing arguments of macros
 */
#include<stdio.h>
#define PI 3.1415
#define area(r)  PI*(r)*(r)
int main()
{
	int radius;
	float Area;
	printf("Enter the rasius of the circle: ");
	fflush(stdout);
	scanf("%d",&radius);
    Area = area(radius);
    printf("Area = %.2f",Area);
	return 0;
}
