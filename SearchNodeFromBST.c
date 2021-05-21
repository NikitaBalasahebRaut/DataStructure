/*
 program to search node from the Binary search tree if node found return adress 
 
 steps
 1. Start from the root. 
2. Compare the searching element with root, if less than root, then recurse for left, else recurse for right. 
3. If the element to search is found anywhere, return true, else return false. 
 */
 
#include<stdio.h>
#include<stdlib.h>

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

PNODE Search(PNODE Root,int iValue)
{
	while(Root != NULL)
	{
     if(Root->data == iValue)
	 {
		 return Root;
	 }
	 if(iValue < Root->data)
	 {
		 return Search(Root->lchild,iValue);
	 }
	 else
	 {
		 return Search(Root->rchild,iValue);
	 }
	}
	return NULL;
}

int main()
{
	                    PNODE First = NULL;
	                    int iNo = 0;
	                    int choice = 1;
						PNODE temp = NULL;
						
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
	                        temp = Search(First,iNo);
							
							if(temp == NULL)
							{
								 printf("node not present in BST\n");
							}
							else
							{
                                printf("Element searched at adress %d",temp);
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
output

D:\ProgramTopicWise\DS2>gcc SearchNodeFromBST.c -o myexe

D:\ProgramTopicWise\DS2>myexe

Enter 1 for insert into BST
Enter 2 for search node into BST
Enter 0 for exit from the application
Enter Your choice
1
Enter number to insert
10

Enter 1 for insert into BST
Enter 2 for search node into BST
Enter 0 for exit from the application
Enter Your choice
1
Enter number to insert
40

Enter 1 for insert into BST
Enter 2 for search node into BST
Enter 0 for exit from the application
Enter Your choice
1
Enter number to insert
96

Enter 1 for insert into BST
Enter 2 for search node into BST
Enter 0 for exit from the application
Enter Your choice
2
Enter element to search
10
Element searched at adress 7934960
Enter 1 for insert into BST
Enter 2 for search node into BST
Enter 0 for exit from the application
Enter Your choice
2
Enter element to search
40
Element searched at adress 7934984
Enter 1 for insert into BST
Enter 2 for search node into BST
Enter 0 for exit from the application
Enter Your choice
0
thank you for using application
*/