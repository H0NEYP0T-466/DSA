#include<iostream>
using namespace std;
class arraybased
{
	private:
		int top;
		int size;
		int *stack;
	public:
		arraybased(int s)
		{
			this->size=s;
			this->top=-1;
			this->stack= new int [size];
		}
	void push(int element)
	{
		if(top<size-1)
		{
			top++;
			stack[top]=element;
		}
		else
		{
			cout<<"STACK OVERFLOW\n";
		}
	}
	void pop()
	{
		if(top>=0)
		{
			int element =stack[top];
			top--;
			cout<<"POPED ELEMENT IS:"<<element<<endl;
		}
		else
		{
			cout<<"STACK UNDERFL0W\n";
		}
	}
	int peek()
	{
		if(top>=0)
		{
			cout<<"ELEMENT ON TOP IS:"<<stack[top]<<endl;
		}
		else
		{
			cout<<"STACK IS EMPETY\n";
		}
	}
	void isempety()
	{
		if(top==-1)
		{
			cout<<"STACK ARRAY IS EMPETY\n";
		}
		else
		{
			cout<<"STACK ARRAY IS NOT EMPETY\n";
		}
	}
};
class node
{
	private:
		int data;
		node* next;
	public:
		node(int d)
		{
			data=d;
			next=NULL;
		}
    void push(int d,node * &head)
	{
		node* newnode =new node(d);
		newnode->next=head;
		head=newnode;
		cout<<"NODE IS PUSHED WITH DATA:"<<d<<endl;
	}	
	void pop(node* &head)
	{
		if(head)
		{
			int e=head->data;
			node* temp=head;
			head=head->next;
			delete temp;
			cout<<"NODE IS POPED WITH DATA:"<<e<<endl;
		}
		else
		{
			cout<<"STACK UNDERFLOW\n";
		}
	}
	void peek(node* &head)
	{
		if(head)
		{
			cout<<"TOP ELEMENT IS:"<<head->data<<"\n";
			
		}
		else
		{
			cout<<"STACK IS EMPETY\n"<<endl;
		}
	}
	
};
int main()
{
	arraybased obj(10);
	obj.push(0);
	obj.push(1);
	obj.push(2);
	obj.push(3);
	obj.push(4);
	obj.push(5);
	obj.push(6);
	obj.push(7);
	obj.push(8);
	obj.push(9);
	obj.peek();
	obj.pop();
	obj.peek();
	obj.isempety();
	node* mynode =new node(0);
	node* head=mynode;
	mynode->push(12,head);
	mynode->push(13,head);
	mynode->push(14,head);
	mynode->push(15,head);
	mynode->peek(head);
	mynode->pop(head);
	mynode->peek(head);
}
