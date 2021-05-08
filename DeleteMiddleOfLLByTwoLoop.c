//program to delete middle of a linked list and return that middle element

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

int Count(PNODE Head)
{
   int iCnt = 0;
   while(Head != NULL)
   {
      iCnt++;
      Head = Head->next;
   }
   
return iCnt;   
}

int DeleteMidd(PPNODE Head)
{
   PNODE temp = *Head;
   PNODE temp2 = NULL;
   int i = 0;
   int iCount = 0 ;
   int iMid = 0;
   int node = 0;
   
   if(temp == NULL)          //LL contain 0 element
   {
	   printf("Linked list is empty\n");
	   return -1;
   }
   if(temp->next == NULL)     //LL contain 1 element
   {
     free(temp);
	 *Head = NULL;
   }
   
   iCount = Count(*Head);       //count no of nodes in the LL
   iMid = iCount/2;             //divide no of nodes by 2 then we get the midd of LL
   
   for(i = 1; i < iMid; i++)    //loop iterate until less than midd (midd chaya ek ghar adogar)
   {
      temp = temp->next;
   }
   temp2 = temp->next;           //now temp at before the midd, temp->next means actual our midd that we take in the temp2
   node = temp2->data;           //temp2->data means actual midd node 
   temp->next = temp->next->next;  //change next of temp
   
   return node;                       //retu midd 
}

int main()
{
	PNODE First = NULL;
	int delNode = 0;
	//creating linked list
	Insert(&First,6);
	Insert(&First,5);
	Insert(&First,4);
	Insert(&First,3);
	Insert(&First,2);
	Insert(&First,1);
	
	printf("Linked List before midd delete \n");
    PrintLinkedList(First);
	
	delNode = DeleteMidd(&First);
	printf("deleted node is : %d\n", delNode);
	
    printf("Linked List after midd delete \n");
    PrintLinkedList(First);
	return 0;
}

/*
output

Inserted element : 6
Inserted element : 5
Inserted element : 4
Inserted element : 3
Inserted element : 2
Inserted element : 1
Linked List before midd delete
1       2       3       4       5       6
deleted node is : 4
Linked List after midd delete
1       2       3       5       6

*/