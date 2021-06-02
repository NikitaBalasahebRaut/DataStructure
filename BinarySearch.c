//program to find the given element from the array using Binary search

#include<stdio.h>
#include<stdlib.h>

int BinarySearch(int arr[],int l,int r,int data)
{  
    if(r >= l)
	{
	 int iMid = l + (r- l) / 2;
	 
     if(data == arr[iMid])
	   return iMid;
   
	 if(data < arr[iMid])
	     return BinarySearch(arr,l,iMid-1,data);
	 else
         return BinarySearch(arr,iMid + 1,r,data);
    }
   return -1;
}

int main()
{
  int iSize = 0;
  int i = 0;
  int iNo = 0;
  int iRet = 0;
  
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
	  printf("%d\n",arr[i]);
  }
  
  printf("\nEnter the element to search\n");
  scanf("%d",&iNo);
  
  iRet = BinarySearch(arr,0,iSize-1,iNo);
  
  if(iRet == -1)
  {
	  printf("Element not found\n");
  }
  else
  {
	  printf("Element found at index:- %d", iRet);
  }
  
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
10
20
30
40
50

Enter the element to search
50
Element found at index:- 4
D:\ProgramTopicWise\DS2\Searching>myexe
Enter The size of array
3
Enter the elements of the array
1
2
3
Elements of the array
1
2
3

Enter the element to search
1000
Element not found
*/