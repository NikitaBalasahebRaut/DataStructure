/*
program to find max value node from the linked list

maxNode() will display maximum value node:

    Define a variable max and initialize it with head's data.
    Node current will point to head.
    Iterate through the list by comparing each node's data with max.
    If max is less than current's data then, max will hold current's data.
    At the end of the list, variable max will hold maximum value node.
    Display the max value.
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

int MaxValueNode(PNODE Head)
{
  PNODE current = Head;
  int iMax = Head->data;
  
  while(current != NULL)
  {
     if(iMax < current->data)
	 {
	     iMax = current->data;
	 }
	 current = current->next;
  }
  return iMax;
}

int main()
{
	PNODE First = NULL;
	int iMax = 0;
	
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
	
	iMax = MaxValueNode(First);
	printf("\n largest value node from Linked List is %d: \n",iMax);
	
	return 0;
}

/*
output

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

 largest value node from Linked List is 10:
 */