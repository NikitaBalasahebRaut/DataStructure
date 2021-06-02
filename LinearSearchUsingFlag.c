//program to find the given element from the array using linear search using flag

#include<stdio.h>
#include<stdlib.h>

void LinearSearch(int arr[],int iSize,int data)
{
   int i = 0;
   int flag = 0;
   
   for(i = 0; i < iSize; i++)
   {
      if(data == arr[i])
	  {
	      flag = 1;
		  break;
	  }
   }	   
   if(flag == 1)
   {
       printf("Element is present at index :- %d and possition :- %d", i,i+1);
   }
   else
   {
      printf("Element is not present in the list\n");
   }
}

int main()
{
  int iSize = 0;
  int i = 0;
  int iNo = 0;
  
  printf("Enter The size of array\n");
  scanf("%d",&iSize);
  int arr[iSize];
  
  printf("Enter the elements of the array\n");
  for(i = 0; i < iSize; i++)
  {
	  scanf("%d",&arr[i]);
  }
  
   printf("Elements of the array\n");
  for(i = 0; i < iSize; i++)
  {
	  printf("%d\t",arr[i]);
  }
  
  printf("\nEnter the element to search\n");
  scanf("%d",&iNo);
  
  LinearSearch(arr,iSize,iNo);
  
  
return 0;
}

/*
output
Enter The size of array
5
Enter the elements of the array
10
20
30
40
50
Elements of the array
10      20      30      40      50
Enter the element to search
40
Element is present at index :- 3 and possition :- 4
*/