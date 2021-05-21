/*
 program to search node from the Binary search tree if node found return adress 
 
 steps
 1. Start from the root. 
 2. Compare the searching element with root, if less than root, then recurse for left, else recurse for right. 
 3. If the element to search is found anywhere, return true, else return false. 
 
 time complexity of search and insert operation may become O(n). 
 */
#include<stdio.h>
#include<stdlib.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

struct Node
{
	int data;
	struct Node *lchild;
	struct Node *rchild;
};

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

void Insert(PPNODE Root,int iValue)
{
   PNODE newn = NULL;
   PNODE temp = *Root;   
   
   newn = (PNODE)malloc(sizeof(NODE));
   newn->data = iValue;
   newn->lchild = NULL;
   newn->rchild = NULL;
   
   if(*Root == NULL)
   {
	   *Root = newn;
   }
   else
   {
	   while(1)
	   {
		   if(temp->data == iValue)
		   {
			   printf("Element already present:Unable to insert\n");
			   free(newn);
			   break;
		   }
		   if(iValue < (temp->data))
		   {
			   if((temp->lchild) == NULL)
			   {
				  temp->lchild = newn;
                  break;				  
			   }
			   temp = temp->lchild;
		   }
		   else if(iValue > (temp->data))
		   {
			   if((temp->rchild) == NULL)
			   {
				   temp->rchild = newn;
				   break;
			   }
			   temp = temp->rchild;
		   }
	   }

   }
     
}

BOOL Search(PNODE Root,int iValue)
{
  while(Root != NULL)
  {
     if(Root->data == iValue)
	 {
		 break;
	 }
	 if(iValue < Root->data)
	 {
		 Root = Root->lchild;
	 }
	 else
	 {
		 Root = Root->rchild;
	 }
  }

  if(Root == NULL)
  {
      return FALSE;
  }
  else
  {
	  return TRUE;
  }
	
}

int main()
{
	                    PNODE First = NULL;
	                    int iNo = 0;
	                    int choice = 1;
						BOOL bRet = FALSE;
						
						while(choice != 0)
						{
						printf("\nEnter 1 for insert into BST\n");
						printf("Enter 2 for search node into BST\n");
						printf("Enter 0 for exit from the application\n");
						
						printf("Enter Your choice\n");
						scanf("%d",&choice);
	
	                    switch(choice)
						{
						 case 1:
	                         printf("Enter number to insert\n");
	                         scanf("%d",&iNo);
	                         Insert(&First,iNo);
							 break;
						case 2:
	                        printf("Enter element to search\n");
	                        scanf("%d",&iNo);
	                        bRet = Search(First,iNo);
							
						    if(bRet == TRUE)
						    {
							  printf("Element is there in BST\n");
						    }
						    else
						    {
							  printf("here is no element in BST\n");
						    }
							break;
						case 0:
						        printf("thank you for using application\n");
								break;
						default:
						        printf("please enter valid choice\n");
						}
                    }
						
return 0;
}

/*


D:\ProgramTopicWise\DS2>gcc SearchNodeFromBST2.c -o myexe

D:\ProgramTopicWise\DS2>myexe

Enter 1 for insert into BST
Enter 2 for search node into BST
Enter 0 for exit from the application
Enter Your choice
1
Enter number to insert
7

Enter 1 for insert into BST
Enter 2 for search node into BST
Enter 0 for exit from the application
Enter Your choice
1
Enter number to insert
8

Enter 1 for insert into BST
Enter 2 for search node into BST
Enter 0 for exit from the application
Enter Your choice
1
Enter number to insert
9

Enter 1 for insert into BST
Enter 2 for search node into BST
Enter 0 for exit from the application
Enter Your choice
2
Enter element to search
8
Element is there in BST

Enter 1 for insert into BST
Enter 2 for search node into BST
Enter 0 for exit from the application
Enter Your choice
0
thank you for using application
*/
