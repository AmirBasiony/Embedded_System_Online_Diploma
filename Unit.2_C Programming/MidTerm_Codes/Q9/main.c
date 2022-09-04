#include <stdio.h>
#include <string.h>
void reverse_String(char str[])
{
	int i, j,len, startIndex, endIndex;
	len = strlen(str);
	endIndex = len - 1;

	printf("\nReversed String is: ");
	for(i = len - 1; i >= 0; i--)
	{
		if(str[i] == ' ' || i == 0)
		{
			if(i == 0)
				startIndex = 0;
			else
				startIndex = i + 1;
			for(j = startIndex; j <= endIndex; j++)
				printf("%c", str[j]);
			endIndex = i - 1;
			printf(" ");
		}
	}
}
int main()
{
	char str[100];
	printf("Please Enter any String: ");
	fflush(stdout);
	gets(str);

	reverse_String(str);


	return 0;
}
