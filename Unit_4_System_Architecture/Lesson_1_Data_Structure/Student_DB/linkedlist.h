#ifndef __LINKEDLIST__
#define __LINKEDLIST__

//Effective Data
struct Sdata{
	int id;
	char name[40];
	float height;
};

//Linked list
struct SStudent{
	struct Sdata Student_info;
	struct SStudent* PNext_Student;
};


void Add_Student();
void Delete_Student();
void Displey_Student();
void Delete_All_Student();
void fill_record(struct SStudent* newStudent);
void Get_Nth_Student();
void Find_Num_of_Student();
void Find_Num_of_Student_1(); // using iterative method 
int Find_Num_of_Student_2(struct SStudent* gpFirstStudent);  // using recursive method 
void GET_the_Nth_STUDENT_DATA_FROM_THE_END();
void Middle_of_List();
int Detect_List_Loop();
void Reverse_List();
#endif /* __LINKEDLIST__ */
