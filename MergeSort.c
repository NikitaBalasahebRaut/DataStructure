//program to perform merge sorting\n

#include<stdio.h>
#include<stdlib.h>

void Merge(int arr[],int lb, int iMid, int ub)
{
	int i = lb;
	int j = iMid+1;
	int k = lb;
	int brr[ub+1];                        //int brr[ub-iMid];
	
	while(i <= iMid && j <= ub)            //execute loop until first sublist <= iMid and second sublist <= ub  (need to satisfy both the condition)
	{
		if(arr[i] <= arr[j])              //execute if element of first sublist is less than element in second sublist
		{
			brr[k] = arr[i];               //copy smallest element in newly created array
			i = i + 1;
		}
		else
		{
			brr[k] = arr[j];                
			j = j + 1;
		}
		k++;
    }
	
	if(i > iMid)                        //if first sublist is completed but some element from second sublist are remaning
	{
		while(j <= ub)
		{
			brr[k] = arr[j];
			j++;
			k++;
		}
	}
	else
	{
		while(i <= iMid)               //elements from first sublist are remaning
		{
			brr[k] = arr[i];
			i++;
			k++;
		}
	}
	
	for(k = lb; k <= ub; k++)
	{
		arr[k] = brr[k];                   //copy all elements from newly created array into orignal array
	}
}

void MergeSort(int arr[],int lb,int ub)
{
	int iMid = 0;
	
  if(lb < ub)                                //it means array have atlist two elements (our case array size in 9)
  {
	//iMid = lb + (ub - lb)/2;
	iMid = (lb + ub)/2;                    //(0 + 8)/2 = 4

     MergeSort(arr,lb,iMid);               //0 - 4     (divide sublist until each sublist having only one element 
     MergeSort(arr,iMid+1,ub);            //5 - 8

    Merge(arr,lb,iMid,ub);	              //now merge two sublist that having all element in sorted order
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
  int iSize = 0;
  int i = 0;
  
  printf("Enter the size of the array\n");
  scanf("%d",&iSize);
  int arr[iSize];
  
  printf("Enter the elements of the array\n");
  for(i = 0; i < iSize; i++)
  {
     scanf("%d",&arr[i]);
  }
   
  printf("Entered data is\n");
  for(i = 0; i < iSize; i++)
  {
     printf("%d \n",arr[i]);
  }
  
  MergeSort(arr,0,iSize-1);
  
  printArray(arr,iSize);


return 0;
}

/*
output

Enter the size of the array
9
Enter the elements of the array
15
5
24
8
1
3
16
10
20
Entered data is
15
5
24
8
1
3
16
10
20

 Array after complete sorting
1       3       5       8       10      15      16      20      24

*/