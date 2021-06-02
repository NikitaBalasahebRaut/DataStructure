//stack implementation using Linked List

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

void Push(PPNODE Head,int iValue)
{
	PNODE newn = NULL;
	newn = (PNODE) malloc(sizeof(NODE));
	newn->data = iValue;
	newn->next = NULL;
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		newn->next = *Head;
		*Head = newn;
	}
}

int Pop(PPNODE Head)
{
	int no = 0;
	PNODE temp = *Head;
	
	if(*Head == NULL)
	{
		printf("Stack is empty\n");
		return -1;
	}
	else
	{
		no = (*Head)->data;
		*Head =(*Head)->next;
		free(temp);
		return no;
	}
}

int Peek(PNODE Head)
{
   int no = 0;
   
   if(Head == NULL)
   {
        printf("stack is empty\n");
        return -1;
   }
   else
   {
      no = Head->data;
      return no;
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
		printf("\nEnter 1 for Push \n");
		printf("Enter 2 for Pop \n");
		printf("Enter 3 for Peek \n");
		printf("Enter 4 for Display \n");
		printf("Enter 5 for Count \n");
		printf("Enter 0 for Exit \n");
		
		printf("Enter your choice\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
			       printf("Enter the element\n");
				   scanf("%d",&iNo);
				   Push(&First,iNo);
				   break;
			case 2:
			        iRet = Pop(&First);
					printf("poped element is: - %d",iRet);
					break;
			case 3:
			       iRet = Peek(First);
				   printf("Peeked element is :- %d", iRet);
				   break;
			case 4:
			       Display(First);
				   break;
		    case 5:
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

D:\ProgramTopicWise\DS2\Stack>myexe

Enter 1 for Push
Enter 2 for Pop
Enter 3 for Peek
Enter 4 for Display
Enter 5 for Count
Enter 0 for Exit
Enter your choice
1
Enter the element
10

Enter 1 for Push
Enter 2 for Pop
Enter 3 for Peek
Enter 4 for Display
Enter 5 for Count
Enter 0 for Exit
Enter your choice
1
Enter the element
20

Enter 1 for Push
Enter 2 for Pop
Enter 3 for Peek
Enter 4 for Display
Enter 5 for Count
Enter 0 for Exit
Enter your choice
4
20      10
Enter 1 for Push
Enter 2 for Pop
Enter 3 for Peek
Enter 4 for Display
Enter 5 for Count
Enter 0 for Exit
Enter your choice
2
poped element is: - 20
Enter 1 for Push
Enter 2 for Pop
Enter 3 for Peek
Enter 4 for Display
Enter 5 for Count
Enter 0 for Exit
Enter your choice
3
Peeked element is :- 10
Enter 1 for Push
Enter 2 for Pop
Enter 3 for Peek
Enter 4 for Display
Enter 5 for Count
Enter 0 for Exit
Enter your choice
5
No of elemets are :- 1
Enter 1 for Push
Enter 2 for Pop
Enter 3 for Peek
Enter 4 for Display
Enter 5 for Count
Enter 0 for Exit
Enter your choice
0
Thank you for using application

*/