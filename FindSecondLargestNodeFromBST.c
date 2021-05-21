//program to find second largest node from BST

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
  
  if(iValue < Root->data)
  {
	  Root->lchild = Insert(Root->lchild,iValue);
  }
  else if(iValue > Root->data)
  {
	  Root->rchild = Insert(Root->rchild,iValue);
  }
  return Root;

}
void Inorder(PNODE Root)
{
	if(Root != NULL)            //we can't use while becase we use recursion and if we use while then unblae to stop the loop
	{
	Inorder(Root->lchild);
	printf("%d\t",Root->data);
	Inorder(Root->rchild);
	}
}

void secondLargestUtil(PNODE Root, int &iCount)
{
	if(Root == NULL || iCount >= 2)
   {
     return;
   }	   
   
   secondLargestUtil(Root->rchild,iCount);
   
   iCount++;
   
   if(iCount == 2)
   {
	   printf("second largest element is: %d\n",Root->data);
	   return;
   }
   
   secondLargestUtil(Root->lchild,iCount);
}

void secondLargest(PNODE Root)
{
   int iCount = 0;
   
   secondLargestUtil(Root,iCount);
}

int main()
{
	   /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
	   
	PNODE Root = NULL;
	
	Root = Insert(Root,50);      //root of the tree
	Insert(Root,30);
	Insert(Root,20);
	Insert(Root,40);
	Insert(Root,70);
	Insert(Root,60);
	Insert(Root,80);
	
	printf("Tree Travelsel using INORDER\n");
	Inorder(Root);
	
	secondLargest(Root);
	
	return 0;
}

/*output



*/