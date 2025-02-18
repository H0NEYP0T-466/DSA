#include<iostream>
using namespace std;
class node
{
	int data;
	node* next;
	node* prev;
	public:
		node(int d)
		{
			this->data=d;
			next=nullptr;
			prev=nullptr;
		}
	node* insert(node* &root,int d)
	{
		if(root==nullptr)
		{
			node* newnode=new node(d);
		}
		node* newnode=new node(d);
		newnode->next=root;
		root->prev=newnode;
	    root=newnode;
	}
	node* search(node* &root,int d)
	{
		node* temp=root;
		while(temp!=nullptr)
		{
			if(d==temp->data)
			{
				cout<<temp->data<<endl;
				break;
			}
			temp=temp->next;
			
		}

	}
	node* insertatpos(node* &root,int d,int pos)
	{
		int index=1;
		node* temp=root;
		while(index<pos-1)
		{
			temp=temp->next;
			index++;
		}
		node* newnode=new node(d);
		temp->next->prev=newnode;
		newnode->next=temp->next;
		temp->next=newnode;
		newnode->prev=temp;
	}
	void print(node* root)
	{
		if(root==nullptr)
		{
			return;
		}
		while(root!=nullptr)
		{
			cout<<"THE DATA OF THIS NODE IS:"<<root->data;
			cout<<endl;
			root=root->next;
		}
	}
	void deletenode(node* &root,int d)
	{
		node* temp=root;
		while(temp->data!=d)
		{
			temp=temp->next;
		}
		temp->prev->next=temp->next;
		temp->next=temp->prev;
		delete temp;
	}
	
	
};
int main()
{
	
	node* newnode=new node(5);
	node* root=newnode;
	newnode->insert(root,4);
	newnode->insert(root,3);
	newnode->insert(root,2);
	newnode->insert(root,1);
	newnode->print(root);
	node* temp=newnode->search(root,4);
	newnode->deletenode(root,4);
	newnode->print(root);
	cout<<endl;
	newnode->insertatpos(root,6,4);
	newnode->print(root);
	
	
}
