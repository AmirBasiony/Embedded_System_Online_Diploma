/*
 * main.c
 *
 *  Created on: ٠٦‏/٠٢‏/٢٠٢٣
 *      Author: Amir
 */
#include"stdio.h"
#include"stdlib.h"
#include"linkedlist.h"

extern struct SStudent* gpFirstStudent;
extern int count;
int choice;
int main()
{	
	int result;
	do{
		printf("\t Choose on of the following options\n\n");
		printf("1: Add Student\n");
		printf("2: Delete Student\n");
		printf("3: View Student\n");
		printf("4: Delete All\n");
		printf("5: Find Student Data by its Index in the list\n");
		printf("6: Find the Number of Students\n");
		printf("7: Find the Student Data From the End\n");
		printf("8: Find the middle of the List\n");
		printf("9: Find If There is a Loop\n");
		printf("10: Reverse the List\n");
		printf("\nEnter Option Number (1,2,3,4,....,10): ");
		scanf("%d",&choice);
		printf("Your choice is number: %d  \n\n",choice);
		switch(choice)
		{
		case 1:
			Add_Student();
			break;
		case 2:
			Delete_Student();
			break;
		case 3:
			Displey_Student();
			break;
		case 4:
			Delete_All_Student();
			break;
		case 5:
			Get_Nth_Student();
			break;
		case 6:
		//	Find_Num_of_Student_1(); // using iterative method 
			result = Find_Num_of_Student_2(gpFirstStudent); // using recursive method 
		
		//	if(!count) // using iterative method 
			if(!result)	// using recursive method 
				printf("\n=========Empty List=========\n\n");
			else
				printf("\nNumber of the Student is: (%d) Student\n\n",result); 
			break;
		case 7:
			GET_the_Nth_STUDENT_DATA_FROM_THE_END();
			break;
		case 8:
			 Middle_of_List();
			break;
		case 9:
			Detect_List_Loop();
			break;
		case 10:
			Reverse_List();
			break;
		default :
			printf("\n========Your choice isn't in the list========\n");
			break;
		}
		printf("\n-------------------------------\n");
		printf("Choose any thing again or exit?\n");
		printf("1: Yes.\n");
		printf("2: No.\n");
		printf("-------------------------------\n");
		scanf("%d",&choice);
	}while(choice == 1);

	return 0;
}
