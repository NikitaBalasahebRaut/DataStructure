/*
program to check given Binary tree is Binary search tree or not
Time Complexity: O(n) 
In these program we include header file ie #include<limits.h>
these header file contain macro INT_MIN and INT_MAX
value of INT_MIN -32999 ,INT_MAX 32999
*/
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

BOOL isBSTUtil(PNODE Root,int min,int max)
{
  if(Root == NULL)
  {
      return TRUE;
  }
  
  if(Root->data < min || Root->data > max)
  {
     return FALSE;
  }

  return isBSTUtil(Root->lchild, min, Root->data -1) && 
         isBSTUtil(Root->rchild, Root->data +1, max);  
}

BOOL isBST(PNODE Root)
{
	return isBSTUtil(Root, INT_MIN, INT_MAX);
}

int main()
{
	PNODE Root = NULL;
	BOOL bRet = FALSE;
	
	Root = Insert(&Root,4);
	Root->lchild = Insert(&Root,2);
	Root->rchild = Insert(&Root,5);
	Root->lchild->lchild = Insert(&Root,1);
	Root->lchild->rchild = Insert(&Root,3);
	
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
/*
created BST
        4
	    / \
	    2  5
	   / \
	   1  3
*/

/*
output

Given Binary Tree is BST
*/