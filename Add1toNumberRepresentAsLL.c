//c program to add 1 to a Linked list

#include<stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

PNODE Insert(int data)
{
 PNODE newn = NULL;
 newn = (PNODE) malloc (sizeof(NODE));
 newn->data = data;
 newn->next = NULL;
 return newn;
}

PNODE Reverse(PNODE Head)
{
  PNODE prev = NULL;
  PNODE current = Head;
  PNODE next = NULL;
  
  while(current != NULL)
  {
     next = current->next;
	 current->next = prev;
	 prev = current;
	 current = next;
  }
  return prev;
}

/* Adds one to a linked lists and return the head node of resultant list */

PNODE addOneUtil(PNODE Head)
{
  PNODE res = Head;
  PNODE temp,prev = NULL;
  
  int carry = 1,sum;
  
  while(Head != NULL)
  {
	     // Calculate value of next digit in resultant list.
        // The next digit is sum of following things
        // (i) Carry
        // (ii) Next digit of head list (if there is a
        // next digit)
    sum = carry + Head->data;
	
	  // update carry for next calulation
	carry = (sum >= 10)? 1:0;
	
	// update sum if it is greater than 10
	sum = sum % 10;
	
	// Create a new node with sum as data
	Head->data = sum;
	
	temp = Head;
	Head = Head->next;
	}
	
	   // if some carry is still there, add a new node to
    // result list.
	if(carry > 0)
	{
	   temp->next = Insert(carry);
	}
	
	 // return head of the resultant list
	return res;
}

PNODE addOne(PNODE Head)
{
	Head = Reverse(Head);
	
	Head = addOneUtil(Head);
	
    return Reverse(Head);
}

void PrintList(PNODE Head)
{
	while(Head != NULL)
	{
		printf("%d\t",Head->data);
		Head = Head->next;
	}
	printf("\n");
}

int main()
{	
	PNODE Head = Insert(1);
	Head->next = Insert(9);
	Head->next->next = Insert(9);
	Head->next->next->next = Insert(9);
	
	printf("Our Linked List\n");
	PrintList(Head);
	
	Head = addOne(Head);
	
	printf("Rsultant Linked List\n");
	PrintList(Head);
	
	return 0;
}

/*
output

Our Linked List
1       9       9       9
Rsultant Linked List
2       0       0       0
*/