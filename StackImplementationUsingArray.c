//stack implementation using array

#include<stdio.h>
#define N 5
int stack[N];
int top = -1;

void Push(int iValue)
{
	if(top == N-1)
	{
		printf("stack overflow\n");
	}
	else
	{
		top++;
		stack[top] = iValue;
	}
}

int Pop()
{
	int item = 0;
	
	if(top == -1)
	{
		printf("stack is empty");
	}
	else
	{
		item = stack[top];
		top--;
		return item;
	}
}

int Peek()
{
	int item = 0;
	
	if(top == -1)
	{
		printf("stack is empty");
	}
	else
	{
		item = stack[top];
		return item;
	}
}

void Display()
{
	int i = 0;
	
	for(i = top; i >= 0; i--)
	{
       printf("%d\t",stack[i]);		
	}
}

int Count()
{
	int i = 0;
	int iCount = 0;
	
	for(i = top; i >= 0; i--)
	{
		iCount++;
	}
	return iCount;
}

int main()
{
	int iNo = 0,iRet = 0,choice = 1;
	
	while(choice != 0)
	{
		printf("\n Enter 1 for Push \n");
		printf("Enter 2 for POp\n");
		printf("Enter 3 for Peek\n");
		printf("Enter 4 for Display \n");
		printf("Enter 5 for Count\n");
		printf("Enter 0 for Exit\n");
		
		printf("Enter your choice\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
			       printf("Enter the element\n");
				   scanf("%d",&iNo);
				   Push(iNo);
				   break;
			case 2:
			       iRet = Pop();
				   printf("Poped element is :- %d",iRet);
				   break;
			case 3:
			       iRet = Peek();
				   printf("Peeked element is :- %d",iRet);
				   break;
			case 4:
			       Display();
				   break;
			case 5:
			       iRet = Count();
				   printf("No of elements are:- %d",iRet);
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

 Enter 1 for Push
Enter 2 for POp
Enter 3 for Peek
Enter 4 for Display
Enter 5 for Count
Enter 0 for Exit
Enter your choice
1
Enter the element
88

 Enter 1 for Push
Enter 2 for POp
Enter 3 for Peek
Enter 4 for Display
Enter 5 for Count
Enter 0 for Exit
Enter your choice
1
Enter the element
77

 Enter 1 for Push
Enter 2 for POp
Enter 3 for Peek
Enter 4 for Display
Enter 5 for Count
Enter 0 for Exit
Enter your choice
3
Peeked element is :- 77
 Enter 1 for Push
Enter 2 for POp
Enter 3 for Peek
Enter 4 for Display
Enter 5 for Count
Enter 0 for Exit
Enter your choice
2
Poped element is :- 77
 Enter 1 for Push
Enter 2 for POp
Enter 3 for Peek
Enter 4 for Display
Enter 5 for Count
Enter 0 for Exit
Enter your choice
4
88
 Enter 1 for Push
Enter 2 for POp
Enter 3 for Peek
Enter 4 for Display
Enter 5 for Count
Enter 0 for Exit
Enter your choice
5
No of elements are:- 1
 Enter 1 for Push
Enter 2 for POp
Enter 3 for Peek
Enter 4 for Display
Enter 5 for Count
Enter 0 for Exit
Enter your choice
0
Thank you for using application
*/