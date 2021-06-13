//program to implement a stack using two queue  (By making push operation costly)

#include<iostream>
#include <queue>
using namespace std;

class Stack
{
	queue<int> q1, q2;       //Two inbuild queue
	
	int curr_size;      // to maintain current number of element
	
	public:
	     Stack()
		 {
			 curr_size = 0;
		 }
		 
		 void push(int x)
		 {
			 curr_size++;
			 
			 q2.push(x);   //push x first in empty q2
			 
			 //push all the remaning element in q1 to q2
			 while(!q1.empty())
			 {
				 q2.push(q1.front());
				 q1.pop();
			 }
			 
			 //swap the names of two queues
			 queue<int> q = q1;
			 q1 = q2;
			 q2 = q;
		 }
		 
		 void pop()
		 {
			 if(q1.empty())   //if no element are there in q1
			 {
				 return;
			 }
			 
			 q1.pop();
			 
			 curr_size--;
		 }
		 
		 int top()
		 {
			 if(q1.empty())
			 {
				 return -1;
			 }
			 return q1.front();
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

   cout<<"current size :"  <<s.size() <<endl;
   cout<<"top element from stack\t" <<s.top() <<endl;
   s.pop();
   cout<<"top element from stack\t" <<s.top() <<endl; 
   s.pop();
   cout<<"top element from stack\t" <<s.top() <<endl; 
   cout<<"current size :"  <<s.size() <<endl;
   
	return 0;
}

/*
output 

D:\ProgramTopicWise\DS2\Stack>myexe
current size :3
top element from stack  3
top element from stack  2
top element from stack  1
current size :1

*/