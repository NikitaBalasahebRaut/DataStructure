//program to delete middle of a linked list and return that middle element

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

int DeleteMidd(PPNODE Head)
{
   PNODE slow_ptr = *Head;
   PNODE fast_ptr = *Head;
   PNODE temp = NULL;
   int node = 0;
   
   if(fast_ptr == NULL)          //LL contain 0 element
   {
	   printf("Linked list is empty\n");
	   return -1;
   }
   if(fast_ptr->next == NULL)     //LL contain 1 element
   {
     free(fast_ptr);
	 *Head = NULL;
   }
   
   while(fast_ptr != NULL && fast_ptr->next != NULL)    //loop iterate until less than midd (midd chaya ek ghar adogar)
   {
     fast_ptr = fast_ptr->next->next;
	 temp = slow_ptr;
	 slow_ptr = slow_ptr->next;
   }
   
   node = slow_ptr->data;
   
   temp->next = slow_ptr->next;
   free(slow_ptr);
   
   return node;                       //retu midd 
}

int main()
{
	PNODE First = NULL;
	int delNode = 0;
	//creating linked list
	Insert(&First,6);
	Insert(&First,5);
	Insert(&First,4);
	Insert(&First,3);
	Insert(&First,2);
	Insert(&First,1);
	
	printf("Linked List before midd delete \n");
    PrintLinkedList(First);
	
	delNode = DeleteMidd(&First);
	printf("deleted node is : %d\n", delNode);
	
    printf("Linked List after midd delete \n");
    PrintLinkedList(First);
	return 0;
}

/*
output

Inserted element : 6
Inserted element : 5
Inserted element : 4
Inserted element : 3
Inserted element : 2
Inserted element : 1
Linked List before midd delete
1       2       3       4       5       6
deleted node is : 4
Linked List after midd delete
1       2       3       5       6


*/