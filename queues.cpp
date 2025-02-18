#include<iostream>
using namespace std;
class queue
{
	public:
	int arr[5];
	int fornt;
	int rear;
	int size;
	queue()
	{
		fornt=0;
		rear=0;
		size=0;
	}
	void enqueue(int data)
	{
		if(size==5)
		{
			cout<<"OVERFLOW\n";
		}
		arr[rear]=data;
		rear=(rear+1)%5;
		size++;
	}
	void dequeue()
	{
		if(size==0)
		{
			cout<<"UNDERFLOW\n";
		}
		fornt=(fornt+1)%5;
		size--;
	}
	void peek()
	{
		if(size==0)
		{
			cout<<"queue is empety\n";
		}
		cout<<arr[fornt]<<endl;
	}
	void isfull()
	{
		if(size==5)
		{
			cout<<"QUEUE IS FULL\n";
		}
	}
	
};
struct node
{
	int data;
	node* next;
};
class linkedlist
{
	public:
		node* fornt;
		node* rear;
		linkedlist()
		{
			fornt=NULL;
			rear=NULL;
		}
		void enqueuelinkedlist(int d)
		{
			node* newnode=new node();
			newnode->data=d;
			newnode->next=NULL;
			if(rear==NULL)
			{
				fornt=newnode;
				rear=newnode;
			}
			else
			{
				rear->next=newnode;
				rear=newnode;
			}
		}
		void dequeuelinkedlist()
		{
			if(fornt==NULL)
			{
				cout<<"LINKED LIST IS EMPETY\n";
			}
			node* temp =fornt;
			fornt=fornt->next;
			delete temp;
			if(fornt==NULL)
			{
				rear=NULL;
			}
		}
        void peek()
        {
        	if(fornt==NULL)
        	{
        		cout<<"LINKED LIST IS EMPETY\n";
			}
			cout<<"top element is:"<<fornt->data<<endl;
		}
		void  isempety()
		{
			if(fornt==NULL)
        	{
        		cout<<"LINKED LIST IS EMPETY\n";
			}
		}
		
	
};

int main()
{
	queue obj;
	obj.enqueue(17);
	obj.enqueue(16);
	obj.enqueue(15);
	obj.enqueue(14);
	obj.enqueue(13);
	obj.isfull();
	obj.peek();
	cout<<"-----------------------\n";
	linkedlist obj1;
	obj1.enqueuelinkedlist(12);
	obj1.enqueuelinkedlist(13);
	obj1.peek();
	obj1.dequeuelinkedlist();
	obj1.peek();
	obj1.isempety();
}
