//program to demonstrate the concept of quick sort

#include<stdio.h>

int partion(int arr[],int lb, int ub)
{
   int pivote = arr[lb];
   int iStart = lb;
   int iEnd = ub;
   int temp = 0;
   
    while(iStart < iEnd)
	{
        while(arr[iStart] <= pivote)
		{
			iStart++;
		}
		while(arr[iEnd] >pivote)
		{
			iEnd--;
		}
		if(iStart < iEnd)
		{
			temp = arr[iStart];
			arr[iStart] = arr[iEnd];
			arr[iEnd] = temp;
		}
	
	}

        temp = arr[lb];
        arr[lb] = arr[iEnd];
        arr[iEnd] = temp;
	
     return iEnd;
}

void QuickSort(int arr[],int lb,int ub)
{
	int mid = 0;
	
   if(lb < ub)
   {
      mid = partion(arr,lb,ub);
	  
      QuickSort(arr,lb,mid-1);
	  QuickSort(arr,mid+1,ub);
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
  
  QuickSort(arr,0,iSize-1);
  
  printf("order of sorted element\n");
  
  for(i = 0; i < iSize; i++)
  {
	  printf("%d\n",arr[i]);
  }
return 0;
}


/*

output

Enter the size of the array
9
Enter the elements of the array
7
6
10
5
9
2
1
15
7
Entered data is
7
6
10
5
9
2
1
15
7
order of sorted element
1
2
5
6
7
7
9
10
15

*/