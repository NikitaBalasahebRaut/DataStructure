//program to remove duplicate elements from sorted linked list

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

void RemoveDuplicates(PNODE Head)
{
   PNODE current = Head;

   if(current == NULL)            //if linked list empty
   {
      return;
   }	
   
  while(current != NULL && current->next != NULL)
  {
    //compare current node with next node
	if(current->data == current->next->data)
	{
		current->next = current->next->next ;
	}
	else
	{
	   current = current->next;
	}

  }	  
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
	
	printf("Linked List Before Duplicate Removel \n");
    PrintLinkedList(First);
	
	RemoveDuplicates(First);
	
	printf("Linked List After Removeing Duplicate Element\n");
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
Linked List Before Duplicate Removel
11      11      11      13      13      20
Linked List After Removeing Duplicate Element
11      13      20

*/