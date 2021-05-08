//c++ program for the Delete continuous nodes with sum K from a given linked list
/*
input: 1 -> 2 -> -3 -> 3 -> 1
k = 3
output: -3 -> 1

explanation

The nodes with continuous sum 3 are: 
1) 1 -> 2 
2) 3 
Therefore, after removing these chain of nodes Linked List becomes: -3-> 1
*/


/*
Input: Linked List: 1 -> 1 -> -3 -> -3 -> -2, K = 5 
Output: 1 -> 1 -> -3 -> -3 -> -2 
Explanation: 
No continuous nodes exits with sum K 
*/

#include<iostream>
#include <unordered_map>
using namespace std;

struct Node
{
	int data;
	Node* next;
	
	//constructor
	Node(int x):data(x),next(NULL)
	{
		
	}
};

//function to crete nodes
Node* getNode(int data)
{
	Node* temp ;
	temp = (Node*) malloc (sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

//function to print the Linked list
void PrintList(Node* Head)
{
	while(Head->next)
	{
	  cout<<Head->data<<"->";
      Head = Head->next;	  
	}
	printf("%d",Head->data);
}

//function that remove continuous nodes whose sum is k
Node* removeZeroSum(Node* Head,int k)
{
	//Root node initilize to 0
	Node* root = new Node(0);
	
	//Append at the front of the given Linked list
	root->next = Head;
	
	//map to store the sum and reference of the node
	unordered_map<int,Node*>umap;
	
	umap[0] = root;
	
	//to store the sum while traversing
	int sum = 0;
	
	//traversing the Linked List
	while(Head != NULL)
	{
		sum += Head->data;
		
		//if found value with (sum-k)
		if(umap.find(sum - k) != umap.end())
		{
			Node* prev = umap[sum - k];
			Node* start = prev;
			
			//delete all the node
			//traverse till current node
			int aux = sum;
			
			//update sum
			sum = sum - k;
			
			//Traverse till current Head
			while(prev != Head)
			{
				prev = prev->next;
				aux += prev->data;
				if(prev != Head)
				{
					umap.erase(aux);
				}
			}
			//update the start value to the next value of current head
			start->next = Head->next;
	    }
	    else if(umap.find(sum) == umap.end())
		{
			umap[sum] = Head;
		}
		Head = Head->next;
   }
   //return the value of updated head node
   return root->next;
   
}

int main()
{
	//head node
	Node* Head;
	
	//create linked list
	Head = getNode(1);
	Head->next = getNode(2);
	Head->next->next = getNode(-3);
	Head->next->next->next = getNode(3);
	Head->next->next->next->next = getNode(1);
	
	printf("our Linked List \n");
	PrintList(Head);
	//given sum k bhit
	int k = 3;
	
	//function call to get hea node of the updated linked list
	Head = removeZeroSum(Head, k);
	
	//print the updated linked list
	if(Head != NULL)
	{
		printf("\nour Linked list After perform operation\n");
		PrintList(Head);
	}
	return 0;
}

/*
output
our Linked List
1->2->-3->3->1
our Linked list After perform operation
-3->1

*/