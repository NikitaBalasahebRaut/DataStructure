//Program for n’th node from the end of a Linked List

//step 1:Maintain two pointers – reference pointer and main pointer. Initialize both reference and main pointers to head.
//step 2:  move the reference pointer to n nodes from head
//if ref_ptr == NULL the move Head by 1 and printf data of main_ptr
//else move both pointer util ref_ptr != NULL then printf data of main_ptr

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

int len = 0;
void Insert(PPNODE Head,int iNo)
{
	PNODE newn = NULL;
	
	newn = (PNODE) malloc (sizeof(NODE));
	newn->data = iNo;
	newn->next = NULL;
	
	newn->next = *Head;
	*Head = newn;
   len++;
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

void PrintNthFromLast(PNODE Head, int n)
{
	PNODE main_ptr = Head;
	PNODE ref_ptr = Head;
	
	int iCount = 0;
	
	if(Head != NULL)
	{
	  while(iCount < n)  //or iCount =1 ; while{iCount <= n)};
	  {
		  if(ref_ptr == NULL)
		  {
			  printf("%d is greter than the no of nodes in list",n);
		  }
	      ref_ptr = ref_ptr->next;
          iCount++;		  
	  }	
	  
	  if(ref_ptr == NULL)
	  {
		  Head = Head->next;                                    //Head = Head->next;
		  if(Head != NULL)
		  {
			  printf("Node no %d from last is %d",n,main_ptr->data);
		  }
	  }
	  else
	  {
		 while(ref_ptr != NULL)
		 {
            main_ptr = main_ptr->next;
            ref_ptr = ref_ptr->next;
		 }			
         printf("Node no %d from last is %d",n,main_ptr->data);
	  }
	}
}

int main()
{
	PNODE First = NULL;
	int NthNode = 0;

	//creating  linked list
    //Insert(&First,70);
	//Insert(&First,60);
	//Insert(&First,50);
	Insert(&First,40);
	Insert(&First,30);
	Insert(&First,20);
	Insert(&First,10);
	
	
	printf("Given Linked List is \n");
	PrintLinkedList(First);
	
	printf("Enter the NthNode to display data\n");
	scanf("%d",&NthNode);
	
	PrintNthFromLast(First,NthNode);
	
	return 0;
}
/*
Given Linked List is
10      20      30      40      50      60      70
Enter the NthNode to display data
3
Nth node is 50

D:\ProgramTopicWise\DS2>myexe
Given Linked List is
10      20      30      40      50      60      70
Enter the NthNode to display data
8
please enter the valid Nth Node

D:\ProgramTopicWise\DS2>myexe
Given Linked List is
10      20      30      40      50      60      70
Enter the NthNode to display data
7
Nth node is 10
*/