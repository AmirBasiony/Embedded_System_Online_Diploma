#include<stdio.h>

int main()
{
	int arr[15],i,size;
	int* ptr=arr;
	printf("Input the number of elements to store in the array (max 15) : ");
	scanf("%d",&size);
	printf("Input %d number of elements in the array : \n",size);
	for(i=0;i<size;i++)
	{
		printf("element - %d : ",i+1);
		scanf("%d",(ptr+i));
	}
	printf("\nThe elements of array in reverse order are : \n");
	for(i=size-1;i>=0;i--)
	{
		printf("element - %d : %d\n",i+1,*(ptr+i));
	}
	getchar();
	return 0;
}