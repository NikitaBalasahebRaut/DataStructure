//level order travelsal using Queue

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

PNODE queue[100];
int front = -1;
int rear = 0;

void enqueue(PNODE Root)
{
	queue[rear] = Root;
	rear++;
}

PNODE dequeue()
{
	front++;
	PNODE c = queue[front];
	return c;
}

void levelorder(PNODE Root)
{
	PNODE q = NULL;
	printf("\n");
	enqueue(Root);

	while(rear-1 != front)
	{
		printf("\n rear = %d, front = %d", rear, front);
		
		q = dequeue();
		printf("%d\t", q->data);
		
		if(q->lchild)
		{
			enqueue(q->lchild);
		}
		else if(q->rchild)
		{
			enqueue(q->rchild);
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
	
	printf("Level order traversal of binary tree is \n");
    levelorder(Root);
	return 0;
}

/*
output
Level order travelsal of binary tree is
1       2       3       4       5

*/