/*
 * main.c
 *
 *  Author: Amir Elbasiony
 *  Subject:C Program to Add Two Complex Numbers by passing Structure to a function
 */

#include<stdio.h>
struct SComplex
{
	float m_real;
	float m_Imag;
};
struct SComplex Read_num()
{
	struct SComplex data;
	printf("For 1st Complex Number\n\n");
	printf("Enter Real and Inmaginary respectively: ");
	fflush(stdout);
	scanf("%f %f",&data.m_real,&data.m_Imag);
	return data;
}
void Complex_Add(struct SComplex num1,struct SComplex num2)
{
	float re_sum,im_sum;
	re_sum=num1.m_real + num2.m_real;
	im_sum=num1.m_Imag + num2.m_Imag;
	printf("Sum = %.1f+%.1fi",re_sum,im_sum);
}
int main()
{
	struct SComplex num1= Read_num();
	struct SComplex num2= Read_num();
	Complex_Add(num1,num2);
	return 0;
}
