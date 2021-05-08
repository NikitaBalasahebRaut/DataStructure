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

void isPalindrom(PNODE Head)
{
   //Temp pointer
   PNODE temp = Head;
   PNODE temp1 = Head;
   PNODE stack_ptr = NULL;

   
   //push all element of the LL to the stack
   while(temp != NULL)
   {
      Insert(&stack_ptr,temp->data);
	  temp = temp->next;    //move ahead
   }
   
        // Iterate in the list again and
      //compare  data from LL (using temp1 pointer) and from the stack using (stack_ptr pointer)
		
		while(temp1 != NULL)
		{
		      // Check if data is not same as popped element
			if(temp1->data == stack_ptr->data)
			{
			   temp1 = temp1->next;
			   stack_ptr = stack_ptr->next;
			}
			else
			{
				printf("\n Not palindrom");
				return;
			}
		
	    }
		printf("\npalindrom");        
} 

int main()
{
	PNODE First = NULL;

	//creating  linked list
	Insert(&First,1);
	Insert(&First,2);
	Insert(&First,3);
	Insert(&First,10);
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