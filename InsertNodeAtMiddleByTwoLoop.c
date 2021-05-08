//program to insert node at middle of linked list 

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
int Count(PNODE Head)
{
   int iCnt = 0;
   while(Head != NULL)
   {
      iCnt++;
      Head = Head->next;
   }
   
return iCnt;   
}

void InsertAtMiddle(PPNODE Head,int iValue)
{
     PNODE newn = NULL;
	 PNODE temp = *Head;
	 int iCount = 0;
	 int iMidd = 0;
	 int i = 0;
	 
     newn = (PNODE) malloc (sizeof(NODE));      //allocate memory
     newn->data = iValue;
     newn->next = NULL;
	 
	 if(*Head == NULL)                          //execute if LL is empty
	 {
		 *Head = newn;
	 }
	 else if((*Head)->next == NULL)             //execute if LL have only one node 
	 {
		 (*Head)->next = newn;
	 }
	 else
	 { 
		  iCount = Count(*Head);               //count no of node
          iMidd = iCount/2;		               //count midd
          for(i = 1; i < iMidd; i++)
           {
             temp = temp->next;
           }
		   newn->next = temp->next;          //insert new node
		   temp->next = newn;		          //now temp next is new node
	 }	 
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
		 printf("Enter 1 for Insert Node into linked list \n");
		 printf("Enter 2 for Display middle element in linked list\n");
		 printf("Enter 3 for display linked list \n");
		 printf("Enter 4 for enter element in middle of linked list\n");
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
			        printf("our linked list is \n");
			        Display(First);
				    break;
			case 4:
			        printf("Enter element to insert into middle of linked list\n");
					scanf("%d",&iNo);
					InsertAtMiddle(&First,iNo);
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

/*output

D:\ProgramTopicWise\DS2>myexe
Enter 1 for Insert Node into linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 4 for enter element in middle of linked list
Enter 0 for exit
Enter your choice
1
Enter element to insert into linked list
1
Enter 1 for Insert Node into linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 4 for enter element in middle of linked list
Enter 0 for exit
Enter your choice
1
Enter element to insert into linked list
2
Enter 1 for Insert Node into linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 4 for enter element in middle of linked list
Enter 0 for exit
Enter your choice
1
Enter element to insert into linked list
3
Enter 1 for Insert Node into linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 4 for enter element in middle of linked list
Enter 0 for exit
Enter your choice
1
Enter element to insert into linked list
4
Enter 1 for Insert Node into linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 4 for enter element in middle of linked list
Enter 0 for exit
Enter your choice
1
Enter element to insert into linked list
5
Enter 1 for Insert Node into linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 4 for enter element in middle of linked list
Enter 0 for exit
Enter your choice
1
Enter element to insert into linked list
6
Enter 1 for Insert Node into linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 4 for enter element in middle of linked list
Enter 0 for exit
Enter your choice
3
our linked list is
6       5       4       3       2       1
Enter 1 for Insert Node into linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 4 for enter element in middle of linked list
Enter 0 for exit
Enter your choice
2
The middle element is 3
Enter 1 for Insert Node into linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 4 for enter element in middle of linked list
Enter 0 for exit
Enter your choice
4
Enter element to insert into middle of linked list
100
Enter 1 for Insert Node into linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 4 for enter element in middle of linked list
Enter 0 for exit
Enter your choice
3
our linked list is
6       5       4       100     3       2       1
Enter 1 for Insert Node into linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 4 for enter element in middle of linked list
Enter 0 for exit
Enter your choice
2
The middle element is 100
Enter 1 for Insert Node into linked list
Enter 2 for Display middle element in linked list
Enter 3 for display linked list
Enter 4 for enter element in middle of linked list
Enter 0 for exit
Enter your choice
0
Thank you for using application
*/