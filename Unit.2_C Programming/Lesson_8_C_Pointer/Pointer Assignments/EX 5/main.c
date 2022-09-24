#include<stdio.h>

struct emplyee
{
	char* m_name;
	int  m_id;
};

int main()
{
	struct emplyee emp1={"ahmed",1001},emp2={"Amir",1002},emp3={"Osama",1003};
	struct emplyee(*arr[]) = {&emp1,&emp2,&emp3};
    struct emplyee(*(*pt)[3]) = &arr; 	
	int i; 
	// printing the contents of the structure.
	for (i=0;i<3;i++)
	{
		printf("Emplyee Name : %s\n",(**(*pt+i)).m_name);
    	printf("Employee ID : %d\n",(*(*pt+i))->m_id);
		printf("=======================================\n");
	}
	//Equivalent to >> printf("Employee ID : %d",(**(*pt+1)).m_id);
	/*
	 Explaination:
	 (*(*pt+1))->m_id                           , pt >> address of arr[]
	 (**(*pt+1)).m_id     Rule :  -> == (*).	,    
 	 (**(*&arr+1)).m_id   Rule :  ptr = &arr  	,   *&arr >>base address of arr[] 
     (**(arr+1)).m_id	  Rule :*&arr = arr     ,   *{arr+1) >> points toarr[1]
	 (*arr[1]).m_id      Rule : *(arr+1) = arr[1] ,  arr[1] >>  address of emp2
 	 (*&emp2).m_id       Rule :  arr[1] = &emp2   ,  *&emp2 >>  vlaue of emp2  
	  emp2.m_id         Rule :*&emp2 =emp2        ,  emp2.m_id >> value of m_id of emp2 variable
	*/
	
	return 0;
}
 