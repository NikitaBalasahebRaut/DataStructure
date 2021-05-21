/*
Print Left View of a Binary Tree
using recursion:

The left view contains all nodes that are first nodes in their levels. 
A simple solution is to do level order traversal and print the first node in every level.

Time Complexity: The function does a simple traversal of the tree, so the complexity is O(n). 
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>  // OR #define INT_MIN -32999,#define INT_MAX 32999



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

void leftViewUtil(PNODE Root,int level,int* max_level)
{
   if(Root == NULL)                //if tree is empty
   {
      return;
   }
   if(*max_level < level)           //if this is the first node of its level
   {
     printf("%d\t", Root->data);
	 *max_level = level;
   }

   //recur for left and right subtree
   leftViewUtil(Root->lchild, level + 1, max_level);
   leftViewUtil(Root->rchild, level + 1, max_level); 
}

void leftView(PNODE Root)
{
  int max_level = 0;
  leftViewUtil(Root, 1, &max_level);  
}

int main()
{
	PNODE Root = NULL;
	
	Root = Insert(&Root,4);
	Root->lchild = Insert(&Root,2);
	Root->rchild = Insert(&Root,5);
	Root->lchild->lchild = Insert(&Root,1);
	Root->lchild->rchild = Insert(&Root,10);
	
	leftView(Root);
	return 0;
}

//output  4       2       1