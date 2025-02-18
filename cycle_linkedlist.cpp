#include<set>
#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node* next;
	node(int d)
	{
		this->data=d;
		this->next=nullptr;
	}
};
void print(node* &head)
{
	node* temp=head;
	set<node*> visited;
	
	while(temp!=nullptr)
	{
		if(visited.find(temp)!=visited.end())
		{
			cout<<"\ncycle detected again\n";
			 break;
		}
		visited.insert(temp);
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
node* findcycle(node* &head)
{
	node* fast=head;
	node* slow=head;
	while(fast!=nullptr&& fast->next!=nullptr)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
		{
			cout<<"cycle detected\n";
			return slow;
		}
	}
	cout<<"no cycle detected\n";
	return nullptr;
}
int main()
{
	node* mynode=new node(12);
	node*head=mynode;
	mynode->next=new node(13);
	mynode->next->next=new node(14);
	mynode->next->next=mynode;
	print(head);
	node* ss;
	ss=findcycle(head);
	cout<<ss->data;
}
