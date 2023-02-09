#include"stdio.h"
#include"stdlib.h"
#include"linkedlist.h"

int count;
int Index;
extern int choice;
struct SStudent* gpFirstStudent = NULL;
struct SStudent* PCurrentStudent = NULL;

void Add_Student()
{
	struct SStudent* PNewStudent;
	struct SStudent* PLastStudent;
	
	if(gpFirstStudent == NULL)
	{ 	// List is empty
		PNewStudent = (struct SStudent*)malloc(sizeof(struct SStudent));
		// make gpFirstStudent points to the first node
		gpFirstStudent = PNewStudent;
	}
	else
	{	// List contains records
		PNewStudent = (struct SStudent*)malloc(sizeof(struct SStudent));
		PLastStudent = gpFirstStudent;
		// traverse  all elements in the list until reaching the last element  
		while(PLastStudent->PNext_Student)
			PLastStudent = PLastStudent->PNext_Student;
		// make last element points to new node
		PLastStudent->PNext_Student = PNewStudent;
	}
	// fill records of the student
	fill_record(PNewStudent);
	
	// Check if adding done or not
	if(!PNewStudent)
		printf("\t***adding student failed***\n");
	else
		printf("\t***adding student done***\n");	
}
void fill_record(struct SStudent* newStudent)
{
		
	printf("Enter The ID: ");
	scanf("%d",&newStudent->Student_info.id);

	printf("Enter your name: ");
	scanf("%s",newStudent->Student_info.name);
	
	printf("Enter your height: ");
	scanf("%f",&newStudent->Student_info.height);
	
	// make last element in the list points to NULL
	newStudent->PNext_Student = NULL;

}
void Displey_Student()
{
	PCurrentStudent = gpFirstStudent;
	count=0;
	
	if(!gpFirstStudent)
	{
		// List is empty
		printf("=========Empty List=========\n\n");
	}
	else
	{	// List contains records
		while(PCurrentStudent)
		{
			printf("=========Student Number (%d)========= \n",++count);
			printf("ID: %d\n",PCurrentStudent->Student_info.id);
			printf("Name: %s\n",PCurrentStudent->Student_info.name);
			printf("Height: %.2f\n\n",PCurrentStudent->Student_info.height);
			
			PCurrentStudent = PCurrentStudent->PNext_Student;
		}
		printf("=========All student record are listed=========\n\n");
	}
}
void Delete_Student()
{ 
	int id;
		
	if(!gpFirstStudent)
	{
		// List is empty
		printf("=========Empty List=========\n\n");
	}
	else //List contains records
	{
		PCurrentStudent = gpFirstStudent;
		struct SStudent* pPrevStudent = NULL;
		
		printf("Enter The student id: ");
		scanf("%d",&id);
		// Iterate along the list until the id is found or the end of the list is reached
		while(PCurrentStudent && PCurrentStudent->Student_info.id != id)
		{
			pPrevStudent = PCurrentStudent;
			PCurrentStudent = PCurrentStudent->PNext_Student;
		}		
		if(!PCurrentStudent)
		{
			printf("\t***Student ID is not exit***\n\n");
		}
		else // if(PCurrentStudent->Student_info.id == id)
		{
			printf("\n\t***Deleting student (%s) is done***\n",PCurrentStudent->Student_info.name);
			if(!pPrevStudent) 
			{
				// delete first node in the list
				gpFirstStudent=PCurrentStudent->PNext_Student;
			}
			else
			{
				pPrevStudent->PNext_Student = PCurrentStudent->PNext_Student;
			}
			free(PCurrentStudent);
		}
	}	
}
void Delete_All_Student()
{
	PCurrentStudent = gpFirstStudent;
	
	if(!gpFirstStudent)
	{
		// List is empty
		printf("=========Empty List=========\n\n");
	}
	while(gpFirstStudent)
	{
		PCurrentStudent = PCurrentStudent ->PNext_Student;
		free(gpFirstStudent);
		gpFirstStudent = PCurrentStudent;
	}	
}
void Get_Nth_Student()
{
	count = 1;
	PCurrentStudent = gpFirstStudent;
	
	if(!gpFirstStudent)
	{
		// List is empty
		printf("\n=========Empty List=========\n\n");
	}
	else // List contains records
	{	
		printf("Enter the Index: ");
		scanf("%d",&Index);
		while(PCurrentStudent &&  count != Index)
		{
			PCurrentStudent = PCurrentStudent->PNext_Student;
			count++;
		}
		
		if(!PCurrentStudent)
		{
			printf("\nIndex is not exit\n\n");
		}
		else
		{
			printf("=========Student Number (%d)========= \n",count);
			printf("ID: %d\n",PCurrentStudent->Student_info.id);
			printf("Name: %s\n",PCurrentStudent->Student_info.name);
			printf("Height: %.2f\n\n",PCurrentStudent->Student_info.height);
		}
	}
}
void Find_Num_of_Student_1() // using iterative method 
{
	count = 0;
	PCurrentStudent = gpFirstStudent;
	if(gpFirstStudent)// if list contains records
	{
		// List contains records
		while(PCurrentStudent)
		{
			PCurrentStudent = PCurrentStudent->PNext_Student;
			count++;
		}
	}
}
int Find_Num_of_Student_2(struct SStudent* gpFirstStudent)  // using recursive method 
{
	PCurrentStudent = gpFirstStudent;
	if(!gpFirstStudent) // List is empty
		return 0;
	else // List contains records
		return (1 + Find_Num_of_Student_2(PCurrentStudent->PNext_Student));
}
void GET_the_Nth_STUDENT_DATA_FROM_THE_END()
{
	count = 0;
	PCurrentStudent = gpFirstStudent;
	struct SStudent* PReferenceStudent = gpFirstStudent;
	
	if(!gpFirstStudent)
	{
		// List is empty
		printf("\n=========Empty List=========\n\n");
	}
	else // List contains records
	{
		printf("Enter the Index: ");
		scanf("%d",&Index);
		
		while(PReferenceStudent && count != Index)
		{
			PReferenceStudent = PReferenceStudent->PNext_Student;
			count++;
		}
		if(count != Index)
		{
			// Index is not found in List
			printf("\n=====Index is not exit in List=====\n\n");
		}
		else // Index is found in List
		{
			while(PReferenceStudent)
			{
				PCurrentStudent = PCurrentStudent->PNext_Student;
				PReferenceStudent = PReferenceStudent->PNext_Student;
			}
			printf("=========Student Number (%d)========= \n",count);
			printf("ID: %d\n",PCurrentStudent->Student_info.id);
			printf("Name: %s\n",PCurrentStudent->Student_info.name);
			printf("Height: %.2f\n\n",PCurrentStudent->Student_info.height);
		}
	}
}
void Middle_of_List()
{
	count = 0;
	PCurrentStudent =gpFirstStudent;
	while(PCurrentStudent)
	{
		PCurrentStudent = PCurrentStudent->PNext_Student;
		count++;
	}
	// Check odd or even
	
	if(count%2 == 1) 
	{
		// Number of nodes is odd
		count = 0;	
		struct SStudent* PFastStudent = gpFirstStudent , * PSlowStudent = gpFirstStudent;
		while(PFastStudent->PNext_Student)
		{
			PFastStudent = PFastStudent->PNext_Student->PNext_Student;
			PSlowStudent = PSlowStudent->PNext_Student;
			count++;
		}
		printf("=========Middle is Number (%d)========= \n",count);
		printf("ID: %d\n",PSlowStudent->Student_info.id);
		printf("Name: %s\n",PSlowStudent->Student_info.name);
		printf("Height: %.2f\n\n",PSlowStudent->Student_info.height);
	}
	else
	{
		
		Index = 1;
		// Number of nodes is even
		PCurrentStudent =gpFirstStudent;	
		while(Index != ((count/2) + 1) ) // PCurrentStudent->PNext_Student &&
		{
			PCurrentStudent = PCurrentStudent->PNext_Student;
			Index++;
		}
		printf("=========Middle Student is Number (%d)========= \n",Index);
		printf("ID: %d\n",PCurrentStudent->Student_info.id);
		printf("Name: %s\n",PCurrentStudent->Student_info.name);
		printf("Height: %.2f\n\n",PCurrentStudent->Student_info.height);
	}
}
int Detect_List_Loop()
{
	struct SStudent* PFastStudent = gpFirstStudent , * PSlowStudent = gpFirstStudent;
	
	while(PSlowStudent && PFastStudent && PFastStudent->PNext_Student)
	{
		PSlowStudent = PSlowStudent->PNext_Student;
		PFastStudent = PFastStudent->PNext_Student->PNext_Student;
		if(PSlowStudent == PFastStudent)
		{
			printf("\n***Found Loop***\n");
			return 1;
		}
	}
	printf("\nNo loop found\n");
	return 0;
}
void Reverse_List()
{
	PCurrentStudent = NULL;
	struct SStudent* PrevStudent = NULL;
	while(gpFirstStudent)
	{
		PCurrentStudent = gpFirstStudent->PNext_Student;
		gpFirstStudent->PNext_Student = PrevStudent;
		PrevStudent = gpFirstStudent;
		gpFirstStudent = PCurrentStudent;
	}
	gpFirstStudent = PrevStudent;
	printf("====Reversing the list done===\n");
}
