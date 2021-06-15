//program to perform bubble sort

#include<stdio.h>

void BubbleSort(int arr[],int iSize)
{
   int pass = 0,j = 0, temp = 0,no = 0,k = 0;

   for(pass = 0; pass < iSize-1; pass++)
   {
      for(j = 0; j < iSize-1; j++)
	  {
		  if(arr[j] > arr[j+1])
		  {
			  temp = arr[j];
			  arr[j] = arr[j+1];
			  arr[j+1] = temp;
		  }
	  }
	  
	  no = pass + 1;
	  printf("\n array after pass %d : \t",no);
	  for(k = 0; k < iSize; k++)
	  {
		  printf("%d\t",arr[k]);
	  }
	  printf("\n");
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
	
	BubbleSort(arr,iSize);
	
	printf("\n Array after complete sorting\n");
	for(i = 0; i < iSize; i++)
	{
		printf("%d \t",arr[i]);
	}
	return 0;
}

/*
output

Enter the size of array
5
Enter the elements of the array
15
16
6
8
5
Elements of the array are
15
16
6
8
5

 array after pass 1 :   15      6       8       5       16

 array after pass 2 :   6       8       5       15      16

 array after pass 3 :   6       5       8       15      16

 array after pass 4 :   5       6       8       15      16

 Array after complete sorting
5       6       8       15      16


*/