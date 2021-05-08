//program to swap two nodes of linked list 
//first search the nodes in linked list
//then swap the nodes 

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

void Insert(PPNODE Head,int iNo)
{
	PNODE newn = NULL;
	
	newn = (PNODE) malloc (sizeof(NODE));
	newn->data = iNo;
	newn->next = NULL;
	
	newn->next = *Head;
	*Head = newn;
	printf("Inserted element : %d\n",iNo);
}

void PrintLinkedList(PNODE Head)
{
	while(Head != NULL)
	{
		printf("%d \t", Head->data);
		Head = Head->next;
	}
	printf("\n");
}

void SwapNodes(PPNODE Head,int x,int y)
{
  PNODE current = *Head;     //to travel LL
  PNODE prev = NULL;          //store adress of prev nodes
  
  /* Nothing to do if x and y are same
    if (x == y)
	{
       return;
	}
  */
  // search for x
  while(current != NULL && current->data != x)    //joperyent LL sampat nahi ani data == x toperyent loop iterrate
  {
	 prev = current;
     current = 	current->next;
  }
  PNODE currentX = current;
  PNODE prevX = prev;
  
  //search for y 
  
  current = *Head;    //reinitilize current again because start searching of y from first element
  prev = NULL;
  
  while(current != NULL && current->data != y) //need to satisfy both the condition
  {
	  prev = current;
	  current = current->next;
  }
  
  PNODE currentY = current;
  PNODE prevY = prev;
  
  //now swap the nodes because we get the adress of both nodes
  PNODE temp = NULL;
  
  temp = currentY->next;
  currentY->next = currentX->next;
  currentX->next = temp;
  
  //After swaping nodes, Head will be change
  
  if(prevX == NULL)         //execute if x is first node in given LL  
  {
	  *Head = currentY;
	  prevY->next = currentX;
  }
  
  if(prevY == NULL)  //execute if y is the first Node
  {
	  *Head = currentX;
	  prevX->next = currentY;
  }
  
  if(prevX != NULL && prevY != NULL) //execute if both nodes are internal nodes
  {
	  prevX->next = currentY;
	  prevY->next = currentX;
  }
  
}
int main()
{
	PNODE First = NULL;
	
	//creating linked list
	Insert(&First,7);
	Insert(&First,6);
	Insert(&First,5);
	Insert(&First,4);
	Insert(&First,3);
	Insert(&First,2);
	Insert(&First,1);
	
	printf("Linked List Before Swapping Nodes \n");
    PrintLinkedList(First);
	
	SwapNodes(&First,1,3);
	
	printf("Linked List After swaping Nodes\n");
	PrintLinkedList(First);
	

	return 0;
}

/*
output

Inserted element : 7
Inserted element : 6
Inserted element : 5
Inserted element : 4
Inserted element : 3
Inserted element : 2
Inserted element : 1
Linked List Before Swapping Nodes
1       2       3       4       5       6       7
Linked List After swaping Nodes
3       2       1       4       5       6       7

*/