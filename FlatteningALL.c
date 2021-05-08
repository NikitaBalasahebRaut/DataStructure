// C program for flattening a linked list
    /* Let us create the following linked list
       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
    */
	
#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node* right;
  struct Node* down;
};
typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

void Push(PPNODE Head,int data)
{
	PNODE newn = NULL;
	newn = (PNODE) malloc (sizeof(NODE));
	
	newn->right = NULL;
	newn->data  = data;
	
	newn->down = (*Head);
	(*Head)   = data;
}

/* function to print nodes in the flattened LL */

void PrintList(PNODE Head)
{
	while(Head != NULL)
	{
		printf("%d",Head->data);
		Head = Head->down;
	}
}

// A utility function to merge two sorted linked lists
PNODE Merge(PNODE a, PNODE b)
{
	//if first list is empty,the second list is result
	if(a == NULL)
	{
		return b;
	}
	
	//if second list is empty ,the first list is result
	if(b == NULL)
	{
		return a;
	}
	
	 // Compare the data members of head nodes of both lists
    // and put the smaller one in result
	
	PNODE result = NULL;
	
	if(a->data < b->data)
	{
		result = a;
		result->down = Merge(a->down, b);
	}
	else
	{
		result = b;
		result->down = Merge(a,b->down);
	}
	
	result->right = NULL;
	return result;
}

PNODE Flatten(PNODE root)
{
	if(root == NULL || root->right == NULL)
	{
		return root;
	}
	return Merge(root,Flatten(root->right));
}

int main()
{
	PNODE root = NULL;
	
	Push(&root, 30);
	Push(&root, 8);
	Push(&root, 7);
	Push(&root, 5);
	
	Push(&(root->right), 20);
	Push(&(root->right), 10);
	
	Push(&(root->right->right), 50);
	Push(&(root->right->right), 22);
	Push(&(root->right->right), 19);
	
	Push(&(root->right->right->right), 45);
	Push(&(root->right->right->right), 40);
	Push(&(root->right->right->right), 35);
	Push(&(root->right->right->right), 20);
	
	printf("Linked List Before Flatten\n");
	PrintList(root);
	
	//Let us flatten the list
	root = Flatten(root);
	
	//Let us print the flatended LL
	PrintList(root);
	
	return 0;
}

/*
output
5 7 8 10 19 20 20 22 30 35 40 45 50
*/