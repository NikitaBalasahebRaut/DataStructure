/*
program to delete node from the BST

1) Node to be deleted is the leaf: Simply remove from the tree. 

              50                            50
           /     \         delete(20)      /   \
          30      70       --------->    30     70 
         /  \    /  \                     \    /  \ 
       20   40  60   80                   40  60   80
2) Node to be deleted has only one child: Copy the child to the node and delete the child 

              50                            50
           /     \         delete(30)      /   \
          30      70       --------->    40     70 
            \    /  \                          /  \ 
            40  60   80                       60   80
3) Node to be deleted has two children: Find inorder successor of the node. Copy contents of the inorder successor to the node and delete the inorder successor. Note that inorder predecessor can also be used. 
 

              50                            60
           /     \         delete(50)      /   \
          40      70       --------->    40    70 
                 /  \                            \ 
                60   80                           80
The important thing to note is, inorder successor is needed only when the right child is not empty.
In this particular case, inorder successor can be obtained by finding the minimum value in the right child of the node.

Time Complexity: The worst case time complexity of delete operation is O(h) where h is the height of the Binary Search Tree.
 In worst case, we may have to travel from the root to the deepest leaf node. The height of a skewed tree may become n and the time complexity of delete operation may become O(n)
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

void Inorder(PNODE Root)
{
	if(Root != NULL)
	{
		Inorder(Root->lchild);
		printf("%d\t",Root->data);
		Inorder(Root->rchild);
	}
}

PNODE MinvalueNode(PNODE Root)
{
	while(Root != NULL && Root->lchild != NULL)
	{
		Root = Root->lchild;
	}
	return Root;
}

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
   else if(iValue < Root->data)
   {
      Root->lchild = Insert(Root->lchild,iValue);
   }
   else if(iValue > Root->data)
   {
      Root->rchild = Insert(Root->rchild,iValue);	   
   }
   return Root;
}

PNODE DeleteNode(PNODE Root,int iValue)
{
   //Base case if tree is empty
   if(Root == NULL)
   {
     return Root;    //return NULL
   }

   if(iValue < Root->data)
   {
      Root->lchild = DeleteNode(Root->lchild,iValue);
   }
   else if(iValue > Root->data)
   {
      Root->rchild = DeleteNode(Root->rchild,iValue);
   }	   
   else
   { 
	   if(Root->lchild == NULL)       //if root have one child ie rchild
	   {
		   PNODE temp = Root->rchild;
		   free(Root);
		   return temp;
	   }
	   else if(Root->rchild == NULL)   //if root have one child ie lchild
	   {
		  PNODE temp = Root->lchild;
		   free(Root);
		   return temp;
	   }
	   else
	   {
		  PNODE temp = MinvalueNode(Root->rchild);  //we get inorder successor
		   
		   Root->data = temp->data;          //update root value 
		   
		   Root->rchild = DeleteNode(Root->rchild,temp->data); //delete successor
	   }
   }
	   return Root;
}
int main()
{
	PNODE Root = NULL;
	
	Root = Insert(Root,100);
	Root = Insert(Root,60);
	Root = Insert(Root,40);
	Root = Insert(Root,30);
	Root = Insert(Root,20);
	Root = Insert(Root,50);
	Root = Insert(Root,10);
	Root = Insert(Root,80);
	Root = Insert(Root,70);
	Root = Insert(Root,90);
	
	printf("Our Linked List \n");
	Inorder(Root);
	
	printf("\nDelete 20\n");
	Root = DeleteNode(Root,20);
	printf("Inorder traversal of the modified tree \n");
	Inorder(Root);
	
	printf("\n Delete 50\n");
	DeleteNode(Root,50);
	printf("Inorder traversal of the modified tree \n");
	Inorder(Root);
	
	return 0;
}

/*
output
D:\ProgramTopicWise\DS2>gcc DeleteNodeFromBST.c -o myexe

D:\ProgramTopicWise\DS2>myexe
Our Linked List
10      20      30      40      50      60      70      80      90      100
Delete 20
Inorder traversal of the modified tree
10      30      40      50      60      70      80      90      100
 Delete 50
Inorder traversal of the modified tree
10      30      40      60      70      80      90      100
*/