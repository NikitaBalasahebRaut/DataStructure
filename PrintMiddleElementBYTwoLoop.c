//program to print middle element of linked list
//we use two loops 
//1 while loop to count no of element in the linked list
// 2 loop we use for loop iterate until NoOfElement/ 2 (means until middle of linked list)
//then print Head->data

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
 PNODE temp = Head;
 int iCnt = 0;
 int i = 0;
 
  while(temp != NULL)
  {
     iCnt++;
	 temp = temp->next;
  }
  
  for(i = 0; i < iCnt/2; i++)
  {
    Head = Head->next;
  }
  
  printf("Middle element is %d\n",Head->data);
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
 output
 D:\ProgramTopicWise\DS2>gcc PrintMiddleElementBYTwoLoop.c -o myexe

D:\ProgramTopicWise\DS2>myexe
Enter 1 for Insert element in linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 0 for exit
Enter your choice
1
Enter element to insert into linked list
99
Enter 1 for Insert element in linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 0 for exit
Enter your choice
1
Enter element to insert into linked list
77
Enter 1 for Insert element in linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 0 for exit
Enter your choice
1
Enter element to insert into linked list
44
Enter 1 for Insert element in linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 0 for exit
Enter your choice
1
Enter element to insert into linked list
33
Enter 1 for Insert element in linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 0 for exit
Enter your choice
1
Enter element to insert into linked list
25
Enter 1 for Insert element in linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 0 for exit
Enter your choice
1
Enter element to insert into linked list
43
Enter 1 for Insert element in linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 0 for exit
Enter your choice
3
43      25      33      44      77      99
Enter 1 for Insert element in linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 0 for exit
Enter your choice
2
Middle element is 44Enter 1 for Insert element in linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 0 for exit
Enter your choice
0
Thank you for using application
*/