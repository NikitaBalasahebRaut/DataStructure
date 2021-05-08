//program to delete a linked list

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

void DeleteList(PPNODE Head)
{
   PNODE current = *Head;
   PNODE temp = NULL;
   
   while(current != NULL)
   {
      temp = current->next;
	  free(current);
	  current = temp;
   }
   *Head = NULL;
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
	
	printf("\nDeleting linked list");
	DeleteList(&First);
	
	printf("\nLinked List deleted\n");
	return 0;
}

/*
output

Inserted element : 20
Inserted element : 13
Inserted element : 13
Inserted element : 11
Inserted element : 11
Inserted element : 11
Linked List
11      11      11      13      13      20

Deleting linked list
Linked List deleted

*/