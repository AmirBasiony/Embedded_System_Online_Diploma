#include<stdio.h>
#include<string.h>

int main()
{
	char str[50];
	char* ptr = str;
	int i,size;
	printf("Input a string : ");
	gets(str);	
	
	printf("Reverse of the string is : ");
	for(i=strlen(str)-1;i>=0;i--)
		printf("%c",*(ptr+i));
	
	return 0;
}
