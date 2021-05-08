//program to detect loop in the linked list if loop present then remove that loop

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
	//printf("Inserted element : %d\n",iNo);
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

void Remove_Loop(PNODE, PNODE);

int DetectAndRemoveLoop(PNODE Head)
{
  PNODE slow_ptr = Head;
  PNODE fast_ptr = Head;

  while(slow_ptr && fast_ptr && fast_ptr->next)
  {
     slow_ptr = slow_ptr->next;
	 fast_ptr = fast_ptr->next->next;
	 
	 if(slow_ptr == fast_ptr)
	 {
		 Remove_Loop(slow_ptr, Head);
		 return 1;  // /* Return 1 to indicate that loop is found */
	 }
  }	  
  return 0;  // /* Return 0 to indeciate that ther is no loop*/
}

/* Function to remove loop.
 loop_node --> Pointer to one of the loop nodes
 head -->  Pointer to the start node of the linked list */
 
void Remove_Loop(PNODE loop_node, PNODE Head)
{
   PNODE ptr1;
   PNODE ptr2;
   
   ptr1 = Head;
   
   while(1)
   {
	   ptr2 = loop_node;
   while(ptr2->next != loop_node && ptr2->next != ptr1)
	   ptr2 = ptr2->next;
    
	 if(ptr2->next == ptr1)      // /* If ptr2 reahced ptr1 then there is a loop. So   break the loop */
		 break;
	 
	 ptr1 = ptr1->next;
   }

   ptr2->next = NULL;
}

int main()
{
	PNODE Head = NULL;
	PNODE newNode = NULL;
	
	Head  = (PNODE) malloc (sizeof(NODE));
	Head->data = 50;
	
	newNode = (PNODE) malloc (sizeof(NODE));
	newNode->data = 20;
	Head->next = newNode;
	
	newNode = (PNODE) malloc (sizeof(NODE));
	newNode->data = 15;
	Head->next->next = newNode;
	
	newNode = (PNODE) malloc (sizeof(NODE));
	newNode->data = 4;
	Head->next->next->next = newNode;
	
	newNode = (PNODE) malloc (sizeof(NODE));
	newNode->data = 10;
	Head->next->next->next->next = newNode;
	
	Head->next->next->next->next->next = Head->next->next;    
	
	 DetectAndRemoveLoop(Head);
	
	printf("Linked List After removing Loop\n");
	PrintLinkedList(Head);

	return 0;
	
}

/*
output

Linked List After removing Loop
50      20      15      4       10

*/