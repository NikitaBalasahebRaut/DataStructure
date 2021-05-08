//Delete last occurrence of an item from linked list

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
void DeleteLastOcc(PPNODE Head,int x)
{
	PNODE temp = *Head;
	PNODE ptr = NULL;
	
	while(temp)
	{
		// If found key, update
		if(temp->data == x)
		{
			ptr = temp;
		}
		temp = temp->next;
	}
	
	// If the last occurrence is the last node
	if(ptr != NULL && ptr->next == NULL)
	{
		temp = *Head;
		while(temp->next != ptr)
		{
			temp = temp->next;
		}
		temp->next = NULL;
	}
	
	//if it is not the last node
	if(ptr != NULL && ptr->next != NULL)
	{
	  ptr->data = ptr->next->data;
      temp = ptr->next;
      ptr->next = ptr->next->next;
      free(temp);	  
	}
	
	//given node not present in linked list 
	if(ptr == NULL)
	{
		printf("given node not present in Linked List\n");
		return;
	}
}

int main()
{
	PNODE First = NULL;
	int iNode = 0;

	//creating  linked list
    Insert(&First,20);
	Insert(&First,60);
	Insert(&First,50);
	Insert(&First,40);
	Insert(&First,30);
	Insert(&First,20);
	Insert(&First,10);
	
	
	printf("Given Linked List is \n");
	PrintLinkedList(First);
	
	printf("enter node that we want delete last occurrence\n");
	scanf("%d",&iNode);
	
	DeleteLastOcc(&First, iNode);
	
	printf("\n Linked List after deleting last occurrence : \n");
	PrintLinkedList(First);
	
	return 0;
}

/*
output

D:\ProgramTopicWise\DS2>gcc DeleteLastOccOfTheNode.c -o myexe

D:\ProgramTopicWise\DS2>myexe
Inserted element : 20
Inserted element : 60
Inserted element : 50
Inserted element : 40
Inserted element : 30
Inserted element : 20
Inserted element : 10
Given Linked List is
10      20      30      40      50      60      20
enter node that we want delete last occurrence
20

 Linked List after deleting last occurrence :
10      20      30      40      50      60

D:\ProgramTopicWise\DS2>myexe
Inserted element : 20
Inserted element : 60
Inserted element : 50
Inserted element : 40
Inserted element : 30
Inserted element : 20
Inserted element : 10
Given Linked List is
10      20      30      40      50      60      20
enter node that we want delete last occurrence
40

 Linked List after deleting last occurrence :
10      20      30      50      60      20

Inserted element : 20
Inserted element : 60
Inserted element : 50
Inserted element : 40
Inserted element : 30
Inserted element : 20
Inserted element : 10
Given Linked List is
10      20      30      40      50      60      20
enter node that we want delete last occurrence
100
given node not present in Linked List

 Linked List after deleting last occurrence :
10      20      30      40      50      60      20
*/