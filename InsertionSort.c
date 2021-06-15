//program to perforn insertion sorting

#include<stdio.h>

void InsertionSort(int arr[],int iSize)
{
  int pass = 0, j = 0, key = 0;
  
  for(pass = 1; pass < iSize; pass++)
  {
	  key = arr[pass];
	  j = pass - 1;
	  
	  while(j >= 0 && arr[j] > key)
	  {
		  arr[j+1] = arr[j];
		  j = j-1;
	  }
	    arr[j+1] = key;
  }

}

void printArray(int arr[],int iSize)
{ 
    int i = 0;
	printf("\n Array after complete sorting\n");
	for(i = 0; i < iSize; i++)
	{
		printf("%d \t",arr[i]);
	}
}

int main()
{
	int iSize = 0,i = 0;
	
	printf("Enter the size of array\n");
	scanf("%d",&iSize);
	int arr[iSize];
	
	printf("Enter the elements of the array\n");
	for(i = 0; i < iSize; i++)
	{
		scanf("%d",&arr[i]);
	}
	
	printf("Elements of the array are\n");
	for(i = 0; i < iSize; i++)
	{
		printf("%d \n",arr[i]);
	}
	
	 InsertionSort(arr,iSize);
	
	 printArray(arr,iSize);
	 
	return 0;
}

/*
output
Enter the size of array
6
Enter the elements of the array
16
15
4
13
2
1
Elements of the array are
16
15
4
13
2
1

 Array after complete sorting
1       2       4       13      15      16
*/