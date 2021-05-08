//Reverse a Linked List in groups of given size
/*
example
Input: 1->2->3->4->5->6->7->8->NULL, K = 3 
Output: 3->2->1->6->5->4->8->7->NULL 
Input: 1->2->3->4->5->6->7->8->NULL, K = 5 
Output: 5->4->3->2->1->8->7->6->NULL 
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

PNODE Reverse(PNODE Head,int k)
{
  PNODE current = Head;
  PNODE next = NULL;
  PNODE prev = NULL;
  int iCount = 0;
  
  /*reverse first k nodes of the linked list */
  while(current != NULL && iCount < k)
  {
    next = current->next;
	current->next = prev;
	prev = current;
	current = next;
	iCount++;
  }
      /* next is now a pointer to (k+1)th node Recursively call for the list starting from current.And make rest of the list as next of first node */
	  
	  if(next != NULL)
	  {
	    Head->next = Reverse(next,k);
	  }
	     /* prev is new head of the input list */
		 return prev;
}

int main()
{
	PNODE First = NULL;
	int k = 0;

	//creating  linked list
    Insert(&First,70);
	Insert(&First,60);
	Insert(&First,50);
	Insert(&First,40);
	Insert(&First,30);
	Insert(&First,20);
	Insert(&First,10);
	
	
	printf("Given Linked List  \n");
	PrintLinkedList(First);
	
	printf("Enter the kthNode to display data\n");
	scanf("%d",&k);
	
	First = Reverse(First,k);
	
	printf("Reverse Linked List  \n");
	PrintLinkedList(First);

	return 0;
}
/*
output
Given Linked List
10      20      30      40      50      60      70
Enter the kthNode to display data
2
Reverse Linked List
20      10      40      30      60      50      70

*/