/*
 * EX1.c
 *
 * Author: Amir Elbasiony
 * Description: C program to find prime numbers between two intervals entered by user
 */

#include <stdio.h>
int check_prime(int min);
int main()
{
	int min,max,i,count;
	printf("Enter min , max numbers of(the interval): ");
	fflush(stdout);
	scanf("%d %d",&min,&max);
	printf("Prime numbers between %d and %d are: ",min,max);
	for(i=min;i<max;++i)
	{
		count=check_prime(i);
		if(count==2)
		{
			printf("%d ",i);
		}
	}
	return 0;
}
int check_prime(int num)
{
	int j,count=0;
	for(j=1;j<=num;++j)
	{
		if(num%j==0)
		{
			count++;
		}
	}

	return count;
}
