//Delete N nodes after M nodes of a linked list

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

void SkipMDeleteN(PNODE Head, int M, int N)
{
  PNODE current = Head;
  PNODE t = NULL;
  int i = 0;

    // The main loop that traverses through the whole list
  while(current != NULL)
  {
	  //    // Skip M nodes
    for(i = 1; i < M && current != NULL; i++)
	{
		current = current->next;
	
	   if(current == NULL)
		return;
	}
	
	
    // Start from next node and delete N nodes
	t = current->next;
	
	for(i = 1; i <= N && t != NULL; i++)
	{
		PNODE temp = t;
		t = t->next;
		free(temp);
	}
	
	current->next = t;
	
	//  // Set current pointer for next iteration
	current = t;
	
  }	  
}

int main()
{
	PNODE First = NULL;
	int M = 2, N = 3;
	
	//creating first linked list
	Insert(&First,10);
	Insert(&First,9);
	Insert(&First,8);
	Insert(&First,7);
	Insert(&First,6);
	Insert(&First,5);
	Insert(&First,4);
	Insert(&First,3);
	Insert(&First,2);
	Insert(&First,1);
	
	printf("M = %d, N = %d \n",M,N);
	
	printf("Given Linked List is \n");
	PrintLinkedList(First);
	
	SkipMDeleteN(First,M,N);
	
	printf("\n Linked List after deletion is : \n");
	PrintLinkedList(First);
	
	return 0;
}

/*
output

D:\ProgramTopicWise\DS2>myexe
Inserted element : 10
Inserted element : 9
Inserted element : 8
Inserted element : 7
Inserted element : 6
Inserted element : 5
Inserted element : 4
Inserted element : 3
Inserted element : 2
Inserted element : 1
M = 2, N = 3
Given Linked List is
1       2       3       4       5       6       7       8       9       10

 Linked List after deletion is :
1       2       6       7

*/