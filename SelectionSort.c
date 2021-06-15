//program to perform selection sort 

#include<stdio.h>

void SelectionSort(int arr[], int iSize)
{
	int pass = 0, j =0, i_Min = 0, temp = 0, no = 0, k = 0;
	
	for(pass = 0; pass < iSize-1; pass++)
	{
		i_Min = pass;
		
		for(j = pass+1; j < iSize; j++)
		{
			if(arr[i_Min] > arr[j])
			{
				 i_Min = j;
			}
		}
		
		if(arr[pass] != arr[i_Min])
		{
			temp = arr[pass];
			arr[pass] = arr[i_Min];
			arr[i_Min] = temp;
		}
		
		no = pass+1;
		printf("\n array after pass %d \t",no);
		
		for(k = 0; k < iSize; k++)
		{
			printf("%d \t", arr[k]);
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
	
	 SelectionSort(arr,iSize);
	
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
7
4
10
8
3
Elements of the array are
7
4
10
8
3

 array after pass 1     3       4       10      8       7

 array after pass 2     3       4       10      8       7

 array after pass 3     3       4       7       8       10

 array after pass 4     3       4       7       8       10

 Array after complete sorting
3       4       7       8       10
*/