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
		//printf("\n rear = %d, front = %d", rear, front);
		
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

int main()
{
    PNODE Root = NULL;
    Insert(&Root,1);
	Insert(&Root,2);
	Insert(&Root,3);
    Insert(&Root,4);
    Insert(&Root,5);
	
	printf("Level order traversal of binary tree is \n");
    levelorder(Root);
	return 0;
}

/*
output
Level order travelsal of binary tree is
1       2       3       4       5

*/