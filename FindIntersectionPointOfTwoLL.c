//program to find the intersection point of two linked list 

    /*
    Create two linked lists
  
    1st 3->6->9->15->30
    2nd 10->15->30
  
    15 is the intersection point
  */


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

int Find_Intersect(PNODE Head1, PNODE Head2)
{
   PNODE larger = NULL;      //larger pinter we use to traverse LL which have large length
   PNODE smaller = NULL;     // to traverse smaller length LL
   
   int len1, len2, diff, i;
   
   len1 = Count(Head1);    //count length of first LL
   len2 = Count(Head2);    //count length of second LL 
   
   diff = len1 - len2;     //calculate difference between two LL
   
   if(diff < 0)
   {
	   diff = diff * -1;
   }
    
	if(len1 > len2)       //execute if LLOne is greter
	{
		larger = Head1;
		smaller = Head2;
	}
	 else                 // execute if LLTwo is greter
	{
		larger = Head2;
		smaller = Head1;
	}
	
	for(i = 0; i < diff; i++) //both the lists have equal no of nodes 
	{
		larger = larger->next;    //Now traverse the larger list from the first node till diff nodes
	}
	
	while(larger != NULL && smaller != NULL)      //// then move one step each in both linked lists
	{
		if(larger == smaller)
		{
			return larger->data;
		}
		larger = larger->next;
		smaller = smaller->next;
	}
	
	return -1;             //execute if there is no intersection point 
}

int main()
{
	PNODE Head1 = NULL;
	PNODE Head2 = NULL;
	PNODE newNode = NULL;
	int intersect = 0;
	
     Head1 = (PNODE) malloc (sizeof(NODE));
     Head1->data = 10;	 
	 
	 Head2 = (PNODE) malloc (sizeof(NODE));
     Head2->data = 3;	
	 
	 newNode = (PNODE) malloc (sizeof(NODE));
     newNode->data = 6;
	 Head2->next = newNode;
	 
	 newNode = (PNODE) malloc (sizeof(NODE));
     newNode->data = 9;
	 Head2->next->next = newNode;
	 
	 newNode = (PNODE) malloc (sizeof(NODE));
     newNode->data = 15;
	 Head1->next = newNode;
	 Head2->next->next->next = newNode;
	 
	 newNode = (PNODE) malloc (sizeof(NODE));
     newNode->data = 30;
	 Head1->next->next = newNode;
	
	 Head1->next->next->next = NULL;
	 
	 printf("First linked list \n");
	 PrintLinkedList(Head1);
	 
	 printf("second linked list \n");
	 PrintLinkedList(Head2);
	
	//find intersection point
	intersect = Find_Intersect(Head1,Head2);
	
	if(intersect == -1)
	{
		printf("there is no intersect point\n");
	}
	else
	{
	   printf("Intersection point is : %d",intersect);
	}
	
	return 0;
}


/*
output

First linked list
10      15      30
second linked list
3       6       9       15      30
Intersection point is : 15
D:\ProgramTopicWise\DS2>

*/