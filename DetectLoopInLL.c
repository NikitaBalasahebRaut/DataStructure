//program to detect loop in the linked list

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

int DetectLoop(PNODE Head)
{
  PNODE slow_ptr = Head;
  PNODE fast_ptr = Head;

  while(slow_ptr && fast_ptr && fast_ptr->next)
  {
     slow_ptr = slow_ptr->next;
	 fast_ptr = fast_ptr->next->next;
	 
	 if(slow_ptr == fast_ptr)
	 {
		 return 1;
	 }
  }	  
  return 0;
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

	
	iRet = DetectLoop(First);
	
	if(iRet == 1)
	{
		printf("Loop found In linked list\n");
	}
	else
	{
		printf("No Loop in the linked list\n");
	}
	
	return 0;
}

//output Loop found In linked list