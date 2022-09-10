/*
 * main.c
 *
 *  Author: Amir Elbasiony
 *  Subject:C Program to store information of students using structure
 */
#include<stdio.h>
struct Sstudent
{
	char m_name[50];
	float m_marks;
}info[10];
void print_Data()
{
	int i;
	printf("Displaying information of students:\n");
	for(i=0;i<10;i++)
	{
		printf("\nFor roll number %d.\n",i+1);
		printf("Name: %s\n",info[i].m_name);
		printf("Marks: %.2f\n",info[i].m_marks);
	}
}
void Read_print_Students_Data()
{
	int i;
	printf("Enter information of students:\n");
	for(i=0;i<10;i++)
	{
		printf("\nFor roll number %d:\n",i+1);
		printf("Enter name: ");
		fflush(stdout);
		scanf("%s",info[i].m_name);
		printf("Enter marks: ");
		fflush(stdout);
		scanf("%f",&info[i].m_marks);
	}
	print_Data();
}

int main()
{
	Read_print_Students_Data();
	return 0;
}
