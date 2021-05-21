//Recursive c program for level order travelsal of binary tree

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

//function prototype

void printCurrentLevel(PNODE Root, int level);
int height(PNODE Root);
PNODE Insert(int data);

//function to print level order travelsal a tree 

void printLevelOrder(PNODE Root)
{
	int h = height(Root);
	int i;
	for(i = 1; i <= h; i++)
	{
		printCurrentLevel(Root,i);
	}
}

void printCurrentLevel(PNODE Root,int level)
{
	 if(Root == NULL)
	 {
		 return;
	 }
	 
	 if(level == 1)
	 {
		 printf("%d\t", Root->data);
	 }
	 else if(level > 1)
	 {
		 printCurrentLevel(Root->lchild,level-1);
		 printCurrentLevel(Root->rchild,level-1);
	 }
}

int height(PNODE Root)
{
	if(Root == NULL)
	{
		return 0;
	}
	else
	{
		int lheight = height(Root->lchild); //cumpute height of each subtree
		int rheight = height(Root->rchild);
		
		if(lheight > rheight)
		{
			return lheight+1;
		}
		else
		{
			return rheight+1;
		}
	}
}

PNODE Insert(int data)
{
	PNODE newn = NULL;
	newn = (PNODE) malloc (sizeof(NODE));
	newn->data = data;
	newn->lchild = NULL;
	newn->rchild = NULL;
	
	return newn;
}

int main()
{
	PNODE Root = NULL;
	Root = Insert(1);
	Root->lchild = Insert(2);
	Root->rchild = Insert(3);
	Root->lchild->lchild = Insert(4);
	Root->lchild->rchild = Insert(5);
	
	printf("Level order travelsal of binary tree is \n");
	printLevelOrder(Root);
	
	return 0;
}