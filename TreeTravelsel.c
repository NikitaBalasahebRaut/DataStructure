//program to tree travelsel INORDER,PREORDER,POSTORDER

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
void Inorder(PNODE Root)
{
	if(Root != NULL)            //we can't use while becase we use recursion and if we use while then unblae to stop the loop
	{
	Inorder(Root->lchild);
	printf("%d\t",Root->data);
	Inorder(Root->rchild);
	}
}

void Preorder(PNODE Root)
{
	if(Root != NULL)
	{
	  printf("%d \t",Root->data);
	  Preorder(Root->lchild);
	  Preorder(Root->rchild);
	}
}

void Postorder(PNODE Root)
{
	if(Root != NULL)
	{
	  Postorder(Root->lchild);
      Postorder(Root->rchild);
      printf("%d \t",Root->data);	  
	}
}
int main()
{
	PNODE Root = NULL;
	
	Insert(&Root,10);      //root of the tree
	Insert(&Root,9);
	Insert(&Root,8);
	Insert(&Root,7);
	Insert(&Root,6);
	Insert(&Root,5);
	Insert(&Root,4);
	Insert(&Root,3);
	
	printf("Tree Travelsel using INORDER\n");
	Inorder(Root);
	
	printf("\nTree Travelsel using PREORDER\n");
	Preorder(Root);
	
	printf("\nTree Travelsel using POSTORDER\n");
	Postorder(Root);
	return 0;
}

/*output

D:\ProgramTopicWise\DS2>gcc TreeTravelsel.c -o myexe

D:\ProgramTopicWise\DS2>myexe
Tree Travelsel using INORDER
3       4       5       6       7       8       9       10
Tree Travelsel using PREORDER
10      9       8       7       6       5       4       3
Tree Travelsel using POSTORDER
3       4       5       6       7       8       9       10

*/