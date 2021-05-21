/*
program to insert node into BST

A new key is always inserted at the leaf. We start searching a key from the root until we hit a leaf node.
Once a leaf node is found, the new node is added as a child of the leaf node. 

steps
1. Start from the root. 
2. Compare the inserting element with root, if less than root, then recurse for left, else recurse for right. 
3. After reaching the end, just insert that node at left(if less than current) else right. 
 

         100                               100
        /   \        Insert 40            /    \
      20     500    --------->          20     500 
     /  \                              /  \  
    10   30                           10   30
                                              \   
                                              40
											  time complexity of search and insert operation may become O(n). 
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

void Inorder(PNODE Root)
{
	if(Root != NULL)
	{
		Inorder(Root->lchild);
		printf("%d \n",Root->data);
		Inorder(Root->rchild);
	}
}
int main()
{
	                    PNODE First = NULL;
	                    int iNo = 0;
	                    int choice = 1;
						
						while(choice != 0)
						{
						printf("\nEnter 1 for insert into BST\n");
						printf("Enter 2 for Display BST\n");
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
	                            Inorder(First);
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

D:\ProgramTopicWise\DS2>gcc InsertNodeAtBST.c -o myexe

D:\ProgramTopicWise\DS2>myexe

Enter 1 for insert into BST
Enter 2 for Display BST
Enter 0 for exit from the application
Enter Your choice
2

Enter 1 for insert into BST
Enter 2 for Display BST
Enter 0 for exit from the application
Enter Your choice
1
Enter number to insert
50

Enter 1 for insert into BST
Enter 2 for Display BST
Enter 0 for exit from the application
Enter Your choice
1
Enter number to insert
30

Enter 1 for insert into BST
Enter 2 for Display BST
Enter 0 for exit from the application
Enter Your choice
1
Enter number to insert
20

Enter 1 for insert into BST
Enter 2 for Display BST
Enter 0 for exit from the application
Enter Your choice
1
Enter number to insert
40

Enter 1 for insert into BST
Enter 2 for Display BST
Enter 0 for exit from the application
Enter Your choice
1
Enter number to insert
70

Enter 1 for insert into BST
Enter 2 for Display BST
Enter 0 for exit from the application
Enter Your choice
1
Enter number to insert
60

Enter 1 for insert into BST
Enter 2 for Display BST
Enter 0 for exit from the application
Enter Your choice
1
Enter number to insert
80

Enter 1 for insert into BST
Enter 2 for Display BST
Enter 0 for exit from the application
Enter Your choice
2
20
30
40
50
60
70
80

Enter 1 for insert into BST
Enter 2 for Display BST
Enter 0 for exit from the application
Enter Your choice
0
thank you for using application
*/