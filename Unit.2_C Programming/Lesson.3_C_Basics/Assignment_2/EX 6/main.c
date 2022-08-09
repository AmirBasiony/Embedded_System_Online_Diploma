/*
 ============================================================================
 Name        : EX6.c
 Author      : Amir Elbasiony
 Version     :
 Copyright   : Your copyright notice
 Description : C Program , Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Enter an integer number: ");
    fflush(stdout); fflush(stdin);
    scanf("%d",&n);
    int sum=0;
    for(int i=1; i<=n;i++)
    {
    	sum += i;
    }
    printf("Sum is: %d",sum );

	return 0 ;
}
