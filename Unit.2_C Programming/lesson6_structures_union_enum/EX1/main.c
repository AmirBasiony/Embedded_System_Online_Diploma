/*
 * main.c
 *
 *  Author: Amir Elbasiony
 *  Subject:C Program to store information(name,rolland marks)of student by passing Structure to a function
 */

#include<stdio.h>
struct Sstudent
{
	char m_name[50];
	int m_roll;
	float m_marks;
};
struct Sstudent Read_Data()
{
	struct Sstudent info;
	printf("Enter information of students:\n\n");
	printf("Enter name: ");
	fflush(stdout);
	scanf("%s",info.m_name);
	printf("Enter roll number: ");
	fflush(stdout);
	scanf("%d",&info.m_roll);
	printf("Enter marks: ");
	fflush(stdout);
	scanf("%f",&info.m_marks);
	return info;
}
void print_Data(struct Sstudent data)
{
	printf("\nDisplaying Information\n\n");
	printf("Name: %s\n",data.m_name);
	printf("Roll: %d\n",data.m_roll);
	printf("Marks: %.2f\n",data.m_marks);
}
int main()
{
	struct Sstudent student = Read_Data();
    print_Data(student);
	return 0;
}
