//program to detect loop in the linked list and return starting point of the loop

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

void Insert(PPNODE Head,int iNo)
{
	PNODE newn = NULL;
	
	newn = (PNODE) malloc (sizeof(NODE));
	newn->data = iNo;
	newn->next = NULL;
	
	newn->next = *Head;
	*Head = newn;
	//printf("Inserted element : %d\n",iNo);
}

void PrintLinkedList(PNODE Head)
{
	while(Head != NULL)
	{
		printf("%d \t", Head->data);
		Head = Head->next;
	}
	printf("\n");
}

PNODE DetectLoop(PNODE Head)
{
  PNODE slow_ptr = Head;
  PNODE fast_ptr = Head;

  while(slow_ptr && fast_ptr && fast_ptr->next)
  {
     slow_ptr = slow_ptr->next;
	 fast_ptr = fast_ptr->next->next;
	 
	 if(slow_ptr == fast_ptr)
	 {
		 return slow_ptr;
	 }
  }	  
  return NULL;
}

void Start_Loop(PNODE Head)
{
   PNODE fast_ptr = Head;
   PNODE slow_ptr = NULL;
   slow_ptr = DetectLoop(Head);
   
   while(slow_ptr != fast_ptr)
   {
	   slow_ptr = slow_ptr->next;
	   fast_ptr = fast_ptr->next;
   }
   printf("Starting point of the loop is : %d\n",slow_ptr->data);
   printf("adress of Starting point of the loop is : %d\n",slow_ptr);
}

int main()
{
	PNODE First = NULL;
	int iRet = 0;
	
	//creating linked list
	Insert(&First,20);
	Insert(&First,4);
	Insert(&First,15);
	Insert(&First,10);
	
	 // Create a loop for testing       (last element(20) pointes to first element(10)
	First->next->next->next->next = First;

	Start_Loop(First);

	return 0;
}

/*
output

Starting point of the loop is : 10
adress of Starting point of the loop is : 12456976

*/