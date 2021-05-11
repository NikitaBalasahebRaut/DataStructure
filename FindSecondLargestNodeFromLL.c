/*
program to find max value node from the linked list
time complexity is 0(N)

steps
    1]Store the maximum of first two nodes in a variable max.
    2]Store the minimum of first two nodes in a variable second_max.
    3]Iterate over the remaining linked list. For each node: 
        If current node value is greater than max, then set second_max as max and max as current node’s value.
        Else if current node value is greater than second_max, then set second_max as current node’s value.

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

int SecondMaxValueNode(PNODE Head)
{
  PNODE current = Head;
  int iMax = Head->data;
  int iMax2 = Head->data;
  
  while(current != NULL)
  {
     if(iMax < current->data)
	 {
	     iMax2 = iMax;
	     iMax = current->data;
	 }
	 else if(iMax2 < current->data)   //without else if also code will work
	 {
		 iMax2 = current->data;
	 }
	 current = current->next;
  }
  return iMax2;
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
	
	iMax = SecondMaxValueNode(First);
	printf("\n second largest value node from Linked List is %d: \n",iMax);
	
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

 second largest value node from Linked List is 9:


 */