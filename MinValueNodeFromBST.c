/*
program to display minimum element from BST .
Inorder traversal of BST always produces sorted output.

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

int MinValueNode(PNODE Root)
{
	PNODE current = Root;
	
	while(current->lchild != NULL)
	{
		current = current->lchild;
	}	
	return current->data;
}

int main()
{
  PNODE Root = NULL;
  int iMin = 0;
  
  Insert(&Root,50);
  Insert(&Root,30);
  Insert(&Root,20);
  Insert(&Root,40);
  Insert(&Root,70);
  Insert(&Root,60);
  Insert(&Root,80);
  
  //print inorder travelsel of the BST
  printf("our Binary search tree in inorder format\n");
  Inorder(Root);
  
  //display smallest node from BST
  iMin = MinValueNode(Root);
  printf("minimum value node from BST is: %d \n",iMin);
  
return 0;
}

/*
output
our Binary search tree in inorder format
20
30
40
50
60
70
80
minimum value node from BST is: 20
*/