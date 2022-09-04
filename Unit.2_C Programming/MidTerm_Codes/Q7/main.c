#include <stdio.h>

int sum_num(unsigned int n)
{
	static int sum;
    if(n > 0)
    {
    	sum += n;

    	sum_num(--n);

    }
    return sum;
}

int main()
{
    printf("%d",sum_num(100));

    return 0;
}
