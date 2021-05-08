//Check whether Linked List is Palindrome using Stack

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
	//printf("Inserted element : %d\n",iNo);
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

PNODE Reverse(PNODE Head)
{
   PNODE current = Head;
   PNODE next = current->next;

   if(Head == NULL)
   {
	   return Head;
   }
   if(next == NULL)
   {
	   return current;
   }
   
   next = Reverse(next);
   current->next->next = current;
   current->next = NULL;
   return current;
}

void isPalindrom(PNODE Head)
{
   //Temp pointer
   PNODE slow_ptr = Head;
   PNODE fast_ptr = Head;
   PNODE first_start = NULL;
   PNODE second_start = NULL;

  if(slow_ptr->next == NULL)
  {
    printf("It is palindrom\n");
    return;
  }
 
  //slit the LL

  while(1)
  {
    fast_ptr = fast_ptr->next->next; //fast_ptr move ahead by 2
	
	if(slow_ptr == NULL)
	{
	  second_start = slow_ptr->next;
	  break;
	}
    
    if(slow_ptr->next == NULL)  //execute when 
    {
       second_start = slow_ptr->next->next;
       break;
    }	
        slow_ptr = slow_ptr->next; //slow_ptr move ahead by 1
  }	

  slow_ptr->next = NULL;  //first part
  
  second_start = Reverse(second_start); //reverse the second part
  
  first_start = Head;
  
  while(first_start != NULL && second_start != NULL)
  {
    if(first_start->data == second_start->data)
	{
		first_start = first_start->next;
		second_start = second_start->next;
	}
	else
	{
		printf("\n Not a palindrome");
		return;
	}
  }  
  printf("It is a palindrome");
} 

int main()
{
	PNODE First = NULL;

	//creating  linked list
	Insert(&First,1);
	Insert(&First,2);
	Insert(&First,3);
	Insert(&First,2);
	Insert(&First,1);
	
	
	printf("Given Linked List is \n");
	PrintLinkedList(First);
	
   isPalindrom(First);
	
	return 0;
}

/*
output

D:\ProgramTopicWise\DS2>myexe
Given Linked List is
1       2       3       2       1

palindrom
D:\ProgramTopicWise\DS2>gcc ChkLLisPalindrome.cpp -o myexe

D:\ProgramTopicWise\DS2>myexe
Given Linked List is
1       10      3       2       1

 Not palindrom
D:\ProgramTopicWise\DS2>
*/