/*program to display smallest node from linked list
steps
minNode() will display minimum value node:

    1] Define a variable min and initialize it with head's data.
    2]Node current will point to head.
    3]Iterate through the list by comparing each node's data with min.
    4]If min is greater than current's data then, min will hold current's data.
    5]At the end of the list, variable min will hold minimum value node.
    6]Display the min value.
*/
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

int MinValueNode(PNODE Head)
{
  PNODE current = Head;
  int iMin = Head->data
  ;
  while(current != NULL)
  {
     if(iMin > current->data)
	 {
	     iMin = current->data;
	 }
	 current = current->next;
  }
  return iMin;
}

int main()
{
	PNODE First = NULL;
	int iMin = 0;
	
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
	
	
	printf("Given Linked List is \n");
	PrintLinkedList(First);
	
	iMin = MinValueNode(First);
	printf("\n smallest value node from Linked List is %d: \n",iMin);
	
	return 0;
}

/*
output
D:\ProgramTopicWise\DS2\LLInterviewQuetions>myexe
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
Given Linked List is
1       2       3       4       5       6       7       8       9       10

 smallest value node from Linked List is 1:


*/