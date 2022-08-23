/*
 * EX4.c
 * Author: Amir Elbasiony
 * Description: C program to caculate the power of a number using recursion
 */
#include <stdio.h>
int power_num(int base,int exp);
int main()
{
	int base , exp;
	printf("Enter base number: ");
	fflush(stdout);
	scanf("%d",&base);
	printf("\nEnter power number(positive integer): ");
	fflush(stdout);
	scanf("%d",&exp);
	printf("\n%d^%d = %d",base,exp,power_num(base,exp));
	return 0;
}
int power_num(int base,int exp)
{
	static int result=1;
	if(exp!=0)
	{
		result=base*power_num( base,exp-1);
	}

	return result;
}
