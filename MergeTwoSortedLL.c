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

PNODE MergeLinkedList(PNODE LLOne, PNODE LLTwo)
{
	PNODE resultHead = NULL;             //newly created( merged) list Head
	PNODE resultTail = NULL;
	PNODE temp = NULL;
	
	while(1)
	{
		if(LLOne == NULL)                  //if first liked list empty
		{
			resultTail->next = LLTwo;       // point to the second linked list
			break;
		}
		
		if(LLTwo == NULL)                   //if second linked list is empty
		{
			resultTail->next = LLOne;      //it point to the first linked list
			break;
		}
		
		//check whether current node of which linked list is smaller
		
		if(LLOne->data <= LLTwo->data)
		{
			temp = LLOne;
			LLOne = LLOne->next;
		}
		else
		{
			temp = LLTwo;
			LLTwo = LLTwo->next;
		}
		
		//Add smaller node to result linked list 
		
		if(resultHead == NULL)
		{
			resultHead = resultTail = temp;
		}
		else
		{
			resultTail->next = temp;
			resultTail = temp;
		}
		resultTail->next = NULL;   //add NULL at end of linked list
	}
	
	return resultHead;
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
	PNODE MergedLL = NULL;
	
	//creating first linked list
	Insert(&LLOne,9);
	Insert(&LLOne,6);
	Insert(&LLOne,3);
	Insert(&LLOne,1);
	PrintLinkedList(LLOne);
	
	//creating second linked list
	Insert(&LLTwo,10);
	Insert(&LLTwo,6);
	Insert(&LLTwo,5);
	Insert(&LLTwo,2);
	PrintLinkedList(LLTwo);
	
	//merge linked list
	MergedLL = MergeLinkedList(LLOne,LLTwo);
	printf("\nMerged Linked List \n");
	PrintLinkedList(MergedLL);
	return 0;
}

/*
output

D:\ProgramTopicWise\DS2>myexe
Inserted element : 9
Inserted element : 6
Inserted element : 3
Inserted element : 1
1       3       6       9
Inserted element : 10
Inserted element : 6
Inserted element : 5
Inserted element : 2
2       5       6       10

Merged Linked List
1       2       3       5       6       6       9       10

*/