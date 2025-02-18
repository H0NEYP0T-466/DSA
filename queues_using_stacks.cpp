#include<stack>
#include<iostream>
using namespace std;
class stacks
{
	public:
		stack<int> stack1,stack2;
	int enqueue(int x)
	{
		stack1.push(x);
	}
	int dequeue()
	{
		if(stack2.empty())
		{
			while(!stack1.empty())
			{
			stack2.push(stack1.top()); 
				stack1.pop();
			}
		}
		if(stack2.empty())
		{
			cout<<"both stacks are empty\n";
			return -1;
		}
		int valuetodequeue=stack2.top();
		stack2.pop();
		return valuetodequeue;
	}
	bool isempty()
{
	return stack1.empty() && stack2.empty();
}
    int front()
    {
    	if(stack2.empty())
		{
			while(!stack1.empty())
			{
			stack2.push(stack1.top());
				stack1.pop();
			}
		}
		if(stack2.empty())
		{
			cout<<"both stacks are empty\n";
			return -1;
		}
		return stack2.top();
    	
	}

};
int main()
{
	stacks obj;
	obj.enqueue(12);
	obj.enqueue(15);
	obj.enqueue(18);
	cout<<obj.front()<<endl;
	cout<<obj.dequeue()<<endl;
	cout<<obj.front();
}
