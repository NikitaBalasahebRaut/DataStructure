//Reverse alternate K nodes in a Singly Linked List

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

/* Reverses alternate k nodes and  returns the pointer to the new head node */
PNODE KAltReverse(PNODE Head,int k)
{
  PNODE current = Head;
  PNODE next  = NULL;
  PNODE prev = NULL;
  int iCount = 0;
  
  /*1) reverse first k nodes of the linked list */
  while(current != NULL && iCount < k)
  {
	  next = current->next;
	  current->next = prev;
	  prev = current;
	  current = next;
	  iCount++;
  }
  
   /* 2) Now head points to the kth node.  So change next  of head to (k+1)th node*/
  if(Head != NULL)
  {
	  Head->next = current;
  }
  
    /* 3) We do not want to reverse next k nodes. So move the current  pointer to skip next k nodes */ 
  iCount = 0;
  while(iCount < k-1 && current != NULL)
  {
	  current = current->next;
	  iCount++;
  }
  
      /* 4) Recursively call for the list starting from current->next.
       And make rest of the list as next of first node */
  if(current != NULL)
  {
	current->next = KAltReverse(current->next,k);
  }
  
  /* 5) prev is new head of the input list */
  return prev;
}

int main()
{
	PNODE First = NULL;
	int iNode = 0;

	//creating  linked list
    int i;
	for(i = 20; i > 0;i--)
	{
		Insert(&First,i);
	}
	
	printf("Given Linked List is \n");
	PrintLinkedList(First);
	
	printf("enter node\n");
	scanf("%d",&iNode);
	
	First = KAltReverse(First, iNode);
	
	printf("\n Modified Linked List: \n");
	PrintLinkedList(First);
	
	return 0;
}