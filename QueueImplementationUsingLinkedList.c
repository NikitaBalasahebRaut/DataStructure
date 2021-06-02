//queue implementation using linked list

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

void Enqueue(PPNODE Head,int iValue)
{
	PNODE newn = NULL;
	newn = (PNODE) malloc(sizeof(NODE));
	newn->data = iValue;
	newn->next = NULL;
	PNODE temp = *Head;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
	}
}

int Dequeue(PPNODE Head)
{
	PNODE temp = *Head;
	int iNo = 0;
	
	if(*Head == NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		iNo = (*Head)->data;
		*Head = (*Head)->next;
		free(temp);
		return iNo;
	}
}

void Display(PNODE Head)
{
	while(Head != NULL)
	{
		printf("%d\t",Head->data);
		Head = Head->next;
	}
}

int Count(PNODE Head)
{
	int iCount = 0;
	
	while(Head != NULL)
	{
		iCount++;
		Head = Head->next;
	}
	return iCount;
}

int main()
{
	PNODE First = NULL;
	int iNo = 0;
	int iRet = 0;
	int choice = 1;
	
	while(choice != 0)
	{
		printf("\nEnter 1 for Eneque \n");
		printf("Enter 2 for Dequeue \n");
		printf("Enter 3 for Display \n");
		printf("Enter 4 for Count \n");
		printf("Enter 0 for Exit \n");
		
		printf("Enter your choice\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
			       printf("Enter the element\n");
				   scanf("%d",&iNo);
				   Enqueue(&First,iNo);
				   break;
			case 2:
			        iRet = Dequeue(&First);
					printf("removed element is: - %d",iRet);
					break;
			case 3:
			       Display(First);
				   break;
		    case 4:
			       iRet = Count(First);
				   printf("No of elemets are :- %d",iRet);
				   break;
			case 0:
			       printf("Thank you for using application\n");
				   break;
			default:
			        printf("Wrong choice");	     
		}
	}
	return 0;
}

/*
output

D:\ProgramTopicWise\DS2\Queue>myexe

Enter 1 for Eneque
Enter 2 for Dequeue
Enter 3 for Display
Enter 4 for Count
Enter 0 for Exit
Enter your choice
1
Enter the element
10

Enter 1 for Eneque
Enter 2 for Dequeue
Enter 3 for Display
Enter 4 for Count
Enter 0 for Exit
Enter your choice
3
10
Enter 1 for Eneque
Enter 2 for Dequeue
Enter 3 for Display
Enter 4 for Count
Enter 0 for Exit
Enter your choice
1
Enter the element
20

Enter 1 for Eneque
Enter 2 for Dequeue
Enter 3 for Display
Enter 4 for Count
Enter 0 for Exit
Enter your choice
4
No of elemets are :- 2
Enter 1 for Eneque
Enter 2 for Dequeue
Enter 3 for Display
Enter 4 for Count
Enter 0 for Exit
Enter your choice
2
removed element is: - 10
Enter 1 for Eneque
Enter 2 for Dequeue
Enter 3 for Display
Enter 4 for Count
Enter 0 for Exit
Enter your choice
3
20
Enter 1 for Eneque
Enter 2 for Dequeue
Enter 3 for Display
Enter 4 for Count
Enter 0 for Exit
Enter your choice
0
Thank you for using application

*/
