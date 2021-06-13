// program to implement queue using two stacks (using costly deQueue)

#include<iostream>
#include<stack>
using namespace std;

class Queue
{
	stack<int> s1, s2;
	
	public:
	
	void enQueue(int x) // Enqueue an item to the queue
	{
		s1.push(x);       //push item to the queue
	}
	
	int deQueue()
	{
		if(s1.empty() && s2.empty())  //if both stacks are empty
		{
			cout<<"Queue is empty";
			exit(0);
		}
		
	    if(s2.empty())           //if s2 is empty ,move element from s1
		{
			while(!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		
		int x = s2.top();
		s2.pop();
		return x;
		
	}
};

int main()
{
	Queue q;
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);
	
	cout<<q.deQueue()<<endl;
	cout<<q.deQueue()<<endl;
	cout<<q.deQueue()<<endl;
	
	return 0;
}

/*
output

1
2
3
*/