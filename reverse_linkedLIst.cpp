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
	    next=nullptr;
	}
};
void insertatstart(node* &head,int data)
	{
		node* newnode=new node(data);
		newnode->next=head;
		head=newnode;
	}
void print(node* &head)
{
	node* temp = head;
	while(temp!=nullptr)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
node* reverse(node* &head)
{
	node* pre=nullptr;
	node* curr = head;
	node*nxt=nullptr;
	while(curr!=nullptr)
	{
		nxt=curr->next;
		curr->next=pre;
		pre=curr;
		curr=nxt;
	}
	return pre;
}
int main()
{
	node* newnode=new node(12);
	node* head = newnode;
    insertatstart(head,13);
    insertatstart(head,14);
    insertatstart(head,15);
    insertatstart(head,16);
    print(head);
    cout<<endl;
    head=reverse(head);
    print(head);
    
}
