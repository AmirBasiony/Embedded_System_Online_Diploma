#include<stdio.h>
#include<string.h>
int main()
{
	char alph[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i;
	char* ptr = alph;
	printf("The Alphabets are : \n");
	for(i=0;i<strlen(alph);i++)
	{
		printf("%c   ",*(ptr+i));
	}
	getchar();
	return 0;
}