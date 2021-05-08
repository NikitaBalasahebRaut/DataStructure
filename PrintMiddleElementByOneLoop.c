//program to print middle element of linked list
//in these program we use two pointer name is 1]slow and 2]fast ,slow pointer increment by 1 and fast pointer increment by 2 when fast pointer reach at last node at that time slow
//pointer reach at middle of linked list and then print data of slow pointer

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
 
void Insert(PPNODE Head,int iValue)
{
     PNODE newn = NULL;
     newn = (PNODE) malloc (sizeof(NODE));
     newn->data = iValue;
     newn->next = NULL;

     newn->next = *Head;
     *Head = newn;	 
}

void Display(PNODE Head)
{
	 while(Head != NULL)
	 {
		 printf("%d\t",Head->data);
		 Head = Head->next;
	 }
	 printf("\n");                           //newn line after displaying all linked list
}

void PrintMiddle(PNODE Head)
{
	PNODE slow_ptr = Head;
	PNODE fast_ptr = Head;
	
	if(Head != NULL)                        //check atlist have one element in linked list
	{
		 while(fast_ptr != NULL && fast_ptr->next != NULL)
		 {
			 fast_ptr = fast_ptr->next->next;                   //increment by 2
			 slow_ptr = slow_ptr->next;                         //increment by 1
		 }
		 printf("The middle element is %d\n", slow_ptr->data);
	}
}

int main()
{
	PNODE First = NULL;
	 int choice = 1;
	 int iNo = 0;
	 
	 while(choice != 0)
	 {
		 printf("Enter 1 for Insert element in linked list \n");
		 printf("Enter 2 for Display middle element in linked list\n");
		 printf("Enter 3 for display linked list \n");
		 printf("Enter 0 for exit \n");
		 
		 printf("Enter your choice\n");
		 scanf("%d",&choice);
		 
		 switch(choice)
		 {
			 case 1:
			        printf("Enter element to insert into linked list\n");
					scanf("%d",&iNo);
					Insert(&First,iNo);
					break;
			case 2:
			        PrintMiddle(First);
					break;
			case 3:
			       Display(First);
				   break;
			case 0:
			        printf("Thank you for using application\n");
					break;
			default:
			         printf("please enter valid choice\n");
		 }
	 }
	return 0;
}

/*

D:\ProgramTopicWise\DS2>gcc PrintMiddleElement.c -o myexe

D:\ProgramTopicWise\DS2>myexe
Enter 1 for Insert element in linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 0 for exit
Enter your choice
1
Enter element to insert into linked list
88
Enter 1 for Insert element in linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 0 for exit
Enter your choice
1
Enter element to insert into linked list
96
Enter 1 for Insert element in linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 0 for exit
Enter your choice
1
Enter element to insert into linked list
74
Enter 1 for Insert element in linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 0 for exit
Enter your choice
1
Enter element to insert into linked list
59
Enter 1 for Insert element in linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 0 for exit
Enter your choice
1
Enter element to insert into linked list
46
Enter 1 for Insert element in linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 0 for exit
Enter your choice
3
46      59      74      96      88
Enter 1 for Insert element in linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 0 for exit
Enter your choice
2
The middle element is 74
Enter 1 for Insert element in linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 0 for exit
Enter your choice
1
Enter element to insert into linked list
89
Enter 1 for Insert element in linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 0 for exit
Enter your choice
3
89      46      59      74      96      88
Enter 1 for Insert element in linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 0 for exit
Enter your choice
2
The middle element is 74
Enter 1 for Insert element in linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 0 for exit
Enter your choice
0
Thank you for using application

*/