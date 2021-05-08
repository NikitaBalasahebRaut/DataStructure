// Rotate a Linked List
// C program to rotate a linked list counter clock wise
 //I/p  10->20->30->40->50->60 
// k is 4
//O/P 50->60->10->20->30->40

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

void Rotate(PPNODE Head, int k)
{
	PNODE current = *Head;
	
	//k is smaller than the size of linked list
	//It doesn't modify the list if k is greater than or equal to size
	if(k == 0)
	{
		return;
	}
	
	int iCount = 1;
	while(iCount < k && current != NULL)
	{
		current = current->next;
		iCount++;
	}
	
	//if current is NULL (ie we reach at end of LL) and k is greter than or equal to count then dont change the LL
	if(current == NULL)
	{
		return;
	}
	
	// current points to kth node. Store it in a variable.
    // kthNode points to node 40 in the above example
	PNODE kthNode = current;
	
	 // current will point to last node after this loop
    // current will point to node 60 in the above example
	while(current->next != NULL)
	{
	   current = current->next;
	}
	
	// Change next of last node to previous head
    // Next of 60 is now changed to node 10
     current->next = *Head;	
	 
	// Change head to (k+1)th node
    // head is now changed to node 50
	*Head =  kthNode->next;
	
	// change next of kth node to NULL
    // next of 40 is now NULL
	kthNode->next = NULL;
  
}

int main()
{
	PNODE First = NULL;
	int k = 4;
	//creating first linked list

	Insert(&First,60);
	Insert(&First,50);
	Insert(&First,40);
	Insert(&First,30);
	Insert(&First,20);
	Insert(&First,10);
	
	
	printf("Given Linked List is \n");
	PrintLinkedList(First);
	
	Rotate(&First, k);
	
	printf("\n Linked List after rotate : \n");
	PrintLinkedList(First);
	
	return 0;
}

/*
output
Inserted element : 60
Inserted element : 50
Inserted element : 40
Inserted element : 30
Inserted element : 20
Inserted element : 10
Given Linked List is
10      20      30      40      50      60

 Linked List after rotate :
50      60      10      20      30      40
*/