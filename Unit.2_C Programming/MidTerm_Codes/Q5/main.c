/*
 ============================================================================
 Name        : Q5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
long bin_to_dec(int dec_num);
int check_ones_in_bin(int bin);
int main(void) {
	int num,bin;
	printf("Enter an integer number: ");
	fflush(stdout);
	scanf("%d",&num);
	bin =bin_to_dec(num);
	printf("Frequency of ones in the binary number of "
			"(%d) is: %d",num ,check_ones_in_bin(bin));
	return 0;
}
long bin_to_dec(int dec_num)
{
	long bin_num = 0 , rem ;
	long place = 1 ;

	while(dec_num > 0)
	{
		rem = dec_num % 2 ;
		bin_num = bin_num +  rem * place ;
		place *= 10 ;
		dec_num /= 2 ;
	}
	return bin_num ;

}
int check_ones_in_bin(int bin)
{
	int count=0,b;
	while(bin){
		b=bin%10;
		bin=bin/10;
		if(b == 1)
		{
			count++;
		}
	}
	return count;
}

