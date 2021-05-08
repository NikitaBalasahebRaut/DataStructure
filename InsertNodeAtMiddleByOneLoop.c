//program to insert node at middle of LL using one loop

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

void InsertAtMidd(PPNODE Head, int iNode)
{
   PNODE slow_ptr = *Head;
   PNODE fast_ptr = *Head;
   PNODE temp = NULL;
   
   PNODE newn = NULL;
   newn = (PNODE) malloc (sizeof(NODE));

   newn->data = iNode;   
   newn->next = NULL;
   
   if(fast_ptr == NULL)          //LL contain 0 element
   {
	   printf("Linked list is empty\n");
	   return ;
   }
   if(fast_ptr->next == NULL)     //LL contain 1 element
   {
	 fast_ptr->next = newn;
   }
   
   while(fast_ptr != NULL && fast_ptr->next != NULL)    //loop iterate until less than midd (midd chaya ek ghar adogar)
   {
     fast_ptr = fast_ptr->next->next;
	 temp = slow_ptr;
	 slow_ptr = slow_ptr->next;
   }
 
    newn->next = temp->next;
	temp->next = newn;
}

int main()
{
	PNODE First = NULL;
	int iNode = 0;
	
	//creating linked list
	Insert(&First,6);
	Insert(&First,5);
	Insert(&First,4);
	Insert(&First,3);
	Insert(&First,2);
	Insert(&First,1);
	
	printf("Linked List before node insert at middle\n");
    PrintLinkedList(First);
	
	printf("enter node to insert at middle\n");
	scanf("%d",&iNode);
    InsertAtMidd(&First,iNode);
	
    printf("Linked List after inserting node at middle \n");
    PrintLinkedList(First);
	return 0;
}

/*output

Inserted element : 6
Inserted element : 5
Inserted element : 4
Inserted element : 3
Inserted element : 2
Inserted element : 1
Linked List before node insert at middle
1       2       3       4       5       6
enter node to insert at middle
100
Linked List after inserting node at middle
1       2       3       100     4       5       6

*/