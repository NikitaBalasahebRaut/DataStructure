//implement queue using two stacks (using enque costly)

/*
enQueue(q, x): 


    While stack1 is not empty, push everything from stack1 to stack2.
    Push x to stack1 (assuming size of stacks is unlimited).
    Push everything back to stack1.

Here time complexity will be O(n)

deQueue(q): 

    If stack1 is empty then error
    Pop an item from stack1 and return it
*/

#include<iostream>
#include<stack>
using namespace std;

class Queue
{
	stack<int> s1, s2;
	
	public:
	
	void enQueue(int x)
	{
		while(!s1.empty())   //move all element from s1 to s2
		{
			s2.push(s1.top());
			s1.pop();
		}
		
		s1.push(x);    //push item into s1
		
		while(!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
	}
	
	int deQueue()
	{
		if(s1.empty())      //if first stack is empty
		{
			cout<<"Queue is empty";
			exit(0);
		}
		
		int x = s1.top();
		s1.pop();
		
		return x;
	}
	
};

int main()
{
	Queue q;
	
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);
	
	cout<<q.deQueue() <<endl;
	cout<<q.deQueue() <<endl;
	cout<<q.deQueue() <<endl;
	
	return 0;
}

/*
output

1
2
3

*/