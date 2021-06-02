
//queue implementation using array

#include<stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void Enqueue(int iValue)
{
	if(rear == N-1)
	{
		printf("Queue is full");
	}
	else if(front == -1 && rear == -1)
	{
		front = rear = 0;
		queue[rear] = iValue;
	}
	else
	{
		 rear++;
		 queue[rear] = iValue;
	}
}

int Dequeue()
{
	int no = 0;
   if(front == -1 && rear == -1)
   {
      printf("queue is empty");
   }
   else if(front == rear)
   {
     	front = rear = -1;
   }
   else
   {
     no = queue[front];
      front++;
	  return no;
   }	  
}

void Display()
{
	int i = 0;
	
	if(front == -1 && rear == -1)
   {
      printf("queue is empty");
   }
   else
   {
	   for(i = front; i <= rear;i++)
	   {
		   printf("%d\t",queue[i]);
	   }
   }
}
int Count()
{
	int i = 0;
	int iCount = 0;
	
	if(front == -1 && rear == -1)
   {
      printf("queue is empty");
   }
   else
   {
	   for(i = front; i <= rear;i++)
	   {
		  iCount++;
	   }
	   return iCount;
   }
}
int main()
{
	int iNo = 0;
	int iRet = 0;
	int choice = 1;
	
	while(choice != 0)
	{
		printf("\nEnter 1 for Enqueue \n");
		printf("Enter 2 for Dequeue \n");
		printf("Enter 3 for Display \n");
		printf("Enter 4 for Count \n");
		printf("Enter 0 for Exit \n");
		
		printf("Enter your choice\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
			       printf("Enter the element\n");
				   scanf("%d",&iNo);
				   Enqueue(iNo);
				   break;
			case 2:
			        iRet = Dequeue();
					printf("Dequeue element is: - %d",iRet);
					break;
			case 3:
			       Display();
				   break;
		    case 4:
			       iRet = Count();
				   printf("No of elemets are :- %d",iRet);\
				   break;
			case 0:
			       printf("Thank you for using application\n");
				   break;
			default:
			        printf("Wrong choice");	     
		}
	}
	return 0;
}

/*
output


D:\ProgramTopicWise\DS\Queue>myexe

Enter 1 for Enqueue
Enter 2 for Dequeue
Enter 3 for Display
Enter 4 for Count
Enter 0 for Exit
Enter your choice
1
Enter the element
55

Enter 1 for Enqueue
Enter 2 for Dequeue
Enter 3 for Display
Enter 4 for Count
Enter 0 for Exit
Enter your choice
1
Enter the element
88

Enter 1 for Enqueue
Enter 2 for Dequeue
Enter 3 for Display
Enter 4 for Count
Enter 0 for Exit
Enter your choice
3
55      88
Enter 1 for Enqueue
Enter 2 for Dequeue
Enter 3 for Display
Enter 4 for Count
Enter 0 for Exit
Enter your choice
2
Dequeue element is: - 1
Enter 1 for Enqueue
Enter 2 for Dequeue
Enter 3 for Display
Enter 4 for Count
Enter 0 for Exit
Enter your choice
4
No of elemets are :- 1
Enter 1 for Enqueue
Enter 2 for Dequeue
Enter 3 for Display
Enter 4 for Count
Enter 0 for Exit
Enter your choice
0
Thank you for using application

*/