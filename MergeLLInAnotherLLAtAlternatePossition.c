//program to demonstrate the concept of merge two sorted linked list

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

void MergeLinkedList(PNODE LLOne, PPNODE LLTwo)
{
	PNODE LLOne_curr = LLOne;
	PNODE LLTwo_curr = *LLTwo;
	PNODE LLOne_next = NULL;
	PNODE LLTwo_next = NULL;
	
	while(LLOne_curr != NULL && LLTwo_curr != NULL)
	{
	    // Save next pointers
	   LLOne_next = LLOne_curr->next;
	   LLTwo_next = LLTwo_curr->next;
	   
	   LLTwo_curr->next = LLOne_next;
	   LLOne_curr->next = LLTwo_curr;
	   
	   LLTwo_curr = LLTwo_next;
	   LLOne_curr = LLOne_next;
	   
	}
	
	*LLTwo = LLTwo_curr;   // Update head pointer of second list
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

int main()
{
	PNODE LLOne = NULL;
	PNODE LLTwo = NULL;
	
	//creating first linked list
	Insert(&LLOne,3);
	Insert(&LLOne,2);
	Insert(&LLOne,1);
	
	printf("First linked list \n");
	PrintLinkedList(LLOne);
	
	//creating second linked list
	Insert(&LLTwo,8);
	Insert(&LLTwo,7);
	Insert(&LLTwo,6);
	Insert(&LLTwo,5);
	Insert(&LLTwo,4);
	
	printf("second linked list \n");
	PrintLinkedList(LLTwo);
	
	//merge linked list
    MergeLinkedList(LLOne,&LLTwo);
	
    printf("modified First linked list \n");
	PrintLinkedList(LLOne);
	
	printf("second linked list \n");
	PrintLinkedList(LLTwo);
	return 0;
}

/*


D:\ProgramTopicWise\DS2>myexe
Inserted element : 3
Inserted element : 2
Inserted element : 1
First linked list
1       2       3
Inserted element : 8
Inserted element : 7
Inserted element : 6
Inserted element : 5
Inserted element : 4
second linked list
4       5       6       7       8
modified First linked list
1       4       2       5       3       6
second linked list
7       8

*/