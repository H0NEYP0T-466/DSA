#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node* next;
		node(int d)
		{
			data=d;
			next=NULL;
		}
	
};
void insertnode(node* &head,int d)
{
	node* newnode =new node(d);
	newnode->next=head;
	head=newnode;
	
}
void print(node* &head)
{
	node* temp =head;
	while(temp!=NULL)
	{
		cout<<"data is:"<<temp->data;
		cout<<"\nnext address is:"<<temp->next<<endl;
		temp=temp->next;
	}
}
void insertatend(node* &head,int data)
{
	node* newnode =new node(data);
	node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
}
void insertatpos(node* &head,int data,int pos)
{
	node* temp=head;
	int c=1;
	if(pos==1)
	{
		insertnode(head,data);
		return;
	}
	else if(pos==6)
	{
		insertatend(head,data);
		return;
	}
	while(c<pos-1)
{
	temp=temp->next;
	c++;
}
node* newnode =new node(data);
newnode->next=temp->next;
temp->next=newnode;
	
}
void deletenode(node* &head,int pos,int len)
{
	
	if(pos==0)
	{
		node* temp=head;
		head=head->next;
		delete temp;
	}
	else if(pos==len-1)
	{
		node* temp=head;
		for(int i=0;i<pos-1;i++)
		{
			temp=temp->next;
		}
		node* nodetodel=temp->next;
		temp->next=NULL;
		delete nodetodel;
		
	}
	else
	{
		node* temp=head;
		for(int i=0;i<pos-1;i++)
		
		{
			
			temp=temp->next;
		}
		node* nodetodel =temp->next;
		temp->next=nodetodel->next;
		delete nodetodel;
		
	}
}


int main()
{
	node* mynode =new node(12);
	node* head =mynode;
	insertnode(head,88);
	insertatend(head,19);
	insertatend(head,20);
	insertnode(head,87);
	insertnode(head,86);
	insertatpos(head,1000,6);
	deletenode(head,3,7);
	print(head);
}
