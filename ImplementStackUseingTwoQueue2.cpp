//program to implement a stack using two queue  (By making pop operation costly)

#include<iostream>
#include<queue>
using namespace std;

class Stack
{
	queue<int> q1, q2;
	int curr_size;
	
	public:
	
	Stack()
	{
		curr_size = 0;
	}
	
	void push(int x)
	{
		q1.push(x);
		curr_size++;
	}
	
	void pop()
	{
		while(q1.size() != 1) //leave one element in q1 and push other in q2
		{
			q2.push(q1.front());
			q1.pop();
		}
		
		q1.pop();
		curr_size--;
		
		queue<int> q = q1;   //swap the names of two queue
		q1 = q2;
		q2 = q;
	}
	
	int top()
	{
		while(q1.size() != 1) //leave one element in q1 and push other in q2
		{
			q2.push(q1.front());
			q1.pop();
		}
		
		int temp = q1.front();
		
		q1.pop();
		
		q2.push(temp);
		
		queue<int> q = q1;   //swap the names of two queue
		q1 = q2;
		q2 = q;
		
		return temp;
	}
	
	int size()
	{
		return curr_size;
	}
};

int main()
{
	Stack s;
	
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	
	cout<<"current size :"<<s.size()<<endl;
	cout<<s.top() <<endl;
	s.pop();
	cout<<s.top() << endl;
	s.pop();
	cout<<s.top() << endl;
	cout<<"current size :"<<s.size()<<endl;
	
	return 0;
}

/*
output

current size :3
top element from stack  3
top element from stack  2
top element from stack  1
current size :1

*/

