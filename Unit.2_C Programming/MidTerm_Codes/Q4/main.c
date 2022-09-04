#include <stdio.h>
int reverse_digits(int n);

int main ()
{
	int num;
    printf("Enter an integer value: ");
    fflush(stdout);
    scanf("%d",&num);
	printf("reversed number = %d",reverse_digits(num));
	return 0;
}
int reverse_digits(int n)
{
	int rem,reverse=0;
	while(n)
	{
		rem = n%10;
        reverse = reverse * 10 + rem ;
		n =n /10;
	}
	return reverse;
}
