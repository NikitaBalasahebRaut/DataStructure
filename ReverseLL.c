//program to reverse the linked list 

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
	printf("Inserted element : %d\n",iNo);
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

void ReverseList(PPNODE Head)
{
   PNODE prevnode = 0;
   PNODE currnode = *Head;
   PNODE nextnode = *Head;
   
   while(nextnode != NULL)
   {
	   nextnode = nextnode->next;
	   currnode->next = prevnode;
	   prevnode = currnode;
	   currnode = nextnode;
   }
   *Head = prevnode;
}

int main()
{
	PNODE First = NULL;
	
	//creating linked list
	Insert(&First,20);
	Insert(&First,13);
	Insert(&First,13);
	Insert(&First,11);
	Insert(&First,11);
	Insert(&First,11);
	
	printf("Linked List  \n");
    PrintLinkedList(First);
	
	ReverseList(&First);
	
	printf("\nLinked List After Reverse\n");
	PrintLinkedList(First);
	return 0;
}

/*
output

D:\ProgramTopicWise\DS2>myexe
Inserted element : 20
Inserted element : 13
Inserted element : 13
Inserted element : 11
Inserted element : 11
Inserted element : 11
Linked List
11      11      11      13      13      20

Linked List After Reverse
20      13      13      11      11      11

*/