/*
program to insert node into BST using recursion
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

void Inorder(PNODE Root)
{
	if(Root != NULL)
	{
		Inorder(Root->lchild);
		printf("%d \n",Root->data);
		Inorder(Root->rchild);
	}
}

PNODE Insert(PNODE Root,int iValue)
{
	PNODE newn = NULL;
	newn = (PNODE) malloc (sizeof(NODE));
	newn->data = iValue;
	newn->lchild = NULL;
	newn->rchild = NULL;
	
	if(Root == NULL)
	{
		Root = newn;
	}
	else if(iValue < (Root->data))
	{
		Root->lchild = Insert(Root->lchild,iValue);
	}
	else
	{
		Root->rchild = Insert(Root->rchild,iValue);
	}
	return Root;
}
int main()
{
  PNODE Root = NULL;
  
  Root = Insert(Root,50);
  Root = Insert(Root,30);
  Root = Insert(Root,20);
  Root = Insert(Root,40);
  Root = Insert(Root,70);
  Root = Insert(Root,60);
  Root = Insert(Root,80);
  
  //print inorder travelsel of the BST
  printf("our Binary search tree in inorder format\n");
  Inorder(Root);
  
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

*/