/*
Write a Program to Find the Maximum Depth or Height of a Tree

Recursively calculate height of left and right subtrees of a node and assign height to the node as max of the heights of two children plus 1
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

int maxDepth(PNODE Root)
{
	if(Root == NULL)
	{
		return 0;
	}
	else
	{
		int lDepth = maxDepth(Root->lchild); //compute the depth of left subtree
		int rDepth = maxDepth(Root->rchild); //compute the depth of right subtree
		
		if(lDepth > rDepth)
		{
			return lDepth + 1;
		}
		else
		{
			return rDepth + 1;
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
	int maxlen = 0;
	
	/*
	    1
	   /  \
	  2    3
	 / \
	4   5
	Root = Insert(1);
	Root->lchild = Insert(2);
	Root->rchild = Insert(3);
	Root->lchild->lchild = Insert(4);
	Root->lchild->rchild = Insert(5);
	*/
	
	maxlen = maxDepth(Root);
	printf("Height of tree is %d\n", maxlen);
	
	return 0;
}

//output Height of tree is 3