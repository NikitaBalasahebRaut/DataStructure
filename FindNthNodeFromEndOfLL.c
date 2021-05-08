//Program for n’th node from the end of a Linked List
//by calculating lenth of Linked list (here we calculate length while inserting nodes in LL,use len variable that declare globaly and increment by 1 when insert the node )
//step 1: calculate the length
//step 2: print (len-n+1) minus length and NthNode,the add 1 in that

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
	PNODE temp = Head;
	int i = 0;
	
	if(len < n) //if given nth node is greter then the size of LL 
	{
		printf("please enter the valid Nth Node\n");
		return;
	}
	
	for(i = 1; i < len - n + 1; i++)
	{
		temp = temp->next;
	}
	printf("Nth node is %d\n", temp->data);
}

int main()
{
	PNODE First = NULL;
	int NthNode = 0;

	//creating  linked list
    Insert(&First,70);
	Insert(&First,60);
	Insert(&First,50);
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