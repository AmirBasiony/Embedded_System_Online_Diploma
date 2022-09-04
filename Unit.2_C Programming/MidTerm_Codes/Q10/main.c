#include <stdio.h>
long bin_to_dec(int dec_num)
{	long bin_num = 0 , rem ;
long place = 1 ;
while(dec_num > 0){
	rem = dec_num % 2 ;
	bin_num = bin_num +  rem * place ;
	place *= 10 ;
	dec_num /= 2 ;
}
return bin_num ;
}
int num_of_ones(long bin_num)
{
	int counter = 0 , b , max = 0 ;
	while(bin_num > 0){
		b = bin_num % 10 ;
		bin_num /= 10 ;
		if(b == 1){
			counter++;
			if(counter >= max)
				max = counter ;
			else
				counter =0;
		}
	}
	return max ;
}
int main()
{
	int num ;
	long bin_num ;
	printf("Enter a number : ");
	fflush(stdout);
	scanf("%d",&num);
	bin_num = bin_to_dec(num);
	int max_num_of_ones = num_of_ones(bin_num);
	printf("Max number of ones between two zeros = %d",max_num_of_ones);
	return 0 ;
}


