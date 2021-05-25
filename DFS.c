/*
program to depth first search(it internally work like preorder traversal)

        A
       / \
      B   C
     /   / \
    D   E   F
	
	output is : A, B, D, C, E, F
*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node* lchild;
  struct Node* rchild;
};

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

void Insert(PPNODE Root,int iValue)
{
  PNODE newn = NULL;
  newn = (PNODE) malloc (sizeof(NODE));
  newn->data = iValue;
  newn->lchild = NULL;
  newn->rchild = NULL;
  PNODE temp = *Root;

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
			 printf("Element is already present in tree \n");
			 break;;
		 }
		 if(iValue < temp->data )
		 {
			 if(temp->lchild == NULL)
			 {
				 temp->lchild = newn;
				 break;
			 }
			 temp = temp->lchild; 
		 }
		 else if(iValue > temp->data)
		 {
			 if(temp->rchild == NULL)
			 {
				 temp->rchild = newn;
				 break;
			 }
			 temp = temp->rchild;
		 }  
	 }
 }
}

void DFS(PNODE Root)
{
	if(Root != NULL)
	{
	  printf("%d \t",Root->data);
	  DFS(Root->lchild);
	  DFS(Root->rchild);
	}
}

int main()
{
	PNODE Root = NULL;
	
	Insert(&Root,1);      //root of the tree
	Insert(&Root,2);
	Insert(&Root,3);
	Insert(&Root,4);
	Insert(&Root,5);
	
	printf("Depth First Search(DFS)\n");
	DFS(Root);
	return 0;
}