#include<stdio.h>
#include<stdlib.h>
#include<limits.h>  // OR #define INT_MIN -32999,#define INT_MAX 32999

typedef int BOOL;
#define TRUE 0
#define FALSE 1


struct node
{
  int data;
  struct node* lchild;
  struct node* rchild;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

PNODE Insert(PPNODE Root,int data)
{
	PNODE newn = NULL;
	newn = (PNODE) malloc (sizeof(NODE));
	newn->data = data;
	newn->lchild = NULL;
	newn->rchild = NULL;
	return newn;
}


int minValue(PNODE Root)
{
	PNODE current = Root;
	
	while(current->rchild != NULL)
	{
		current = current->rchild;
	}	
	return current->data;
}

int maxValue(PNODE Root)
{
	PNODE current = Root;
	
	while(current->lchild != NULL)
	{
		current = current->lchild;
	}	
	return current->data;
}


BOOL isBST(PNODE Root)
{
	if(Root == NULL)
	{
	   return TRUE;
	}
	
	if(Root->lchild != NULL && maxValue(Root->lchild) > Root->data)
	{
	  return FALSE;
	}
	
	if(Root->rchild != NULL && minValue(Root->rchild) < Root->data)
	{
	   return FALSE;
	}
	
	if(!isBST(Root->lchild) || !isBST(Root->rchild))
	{
	  return FALSE;
	}
	
	return TRUE;
}

int main()
{
	PNODE Root = NULL;
	BOOL bRet = TRUE;
	
	Root = Insert(&Root,4);
	Root->lchild = Insert(&Root,2);
	Root->rchild = Insert(&Root,5);
	Root->lchild->lchild = Insert(&Root,1);
	Root->lchild->rchild = Insert(&Root,10);
	
	bRet = isBST(Root);
	
	if(bRet == TRUE)
	{
		printf("Given Binary Tree is BST\n");
	}
	else
	{
		printf("Given Binary Tree is not BST\n");
	}
	
	return 0;
}

//OUTPUT Given Binary Tree is not BST