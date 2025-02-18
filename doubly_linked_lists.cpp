#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node* pre;
		node* nxt;
	node(int d)
	{
		data=d;
		pre=NULL;
		nxt=NULL;
	}
};
void getlen(node* &head)
{
	int len=0;
	node* temp=head;
	while(temp!=NULL)
	{
		len++;
		temp=temp->nxt;
	}
       cout<<"the length of the linked list is:"<<len<<endl;
}
void print(node* &head)
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<"\nTHE PREVIOUD NODE IS: "<<temp->pre<<endl;
		cout<<"DATA IN THIS NODE IS: "<<temp->data<<endl;
		cout<<"THE NEXT NODE IS: "<<temp->nxt<<endl;
		cout<<"\n\n";
		temp=temp->nxt;
	}
}
 void insertatstart(node* &head,int data)
{
	node* newnode =new node(data);
	cout<<"MEMORY ADDRESS OF THIS NODE IS:"<<newnode<<" WITH THIS DATA:"<<data<<endl;
	node* temp=head;
	newnode->nxt=head;
	temp->pre=newnode;
	head=newnode;
}
void insertatpos(node* &head,int p,int d)
{
	node* temp=head;
	int c=1;
	while(c<p-1)
	{
		temp=temp->nxt;
		c++;
	}
	node* newnode=new node(d);
	cout<<"MEMORY ADDRESS OF POSITION NODE IS:"<<newnode<<" WITH THIS DATA:"<<d<<endl;
	newnode->nxt=temp->nxt;
	newnode->pre=temp;
	temp->nxt=newnode;
}
void insertatend(node* &head,int data)
{
	node* temp=head;
	while(temp->nxt!=NULL)
	{
		temp=temp->nxt;
	}
	node* newnode =new node(data);
	cout<<"MEMORY ADDRESS OF END NODE IS:"<<newnode<<" WITH THIS DATA:"<<data<<endl;
	temp->nxt=newnode;
	newnode->pre=temp;
}
 void deletenode(node* &head,int pos,int len)
 {
 	if(pos==0)
 	{
 		node* temp=head;
 		temp->nxt->pre=NULL;
 		head=temp->nxt;
 		delete temp;
	 }
	 else if(pos==len-1)
	 {
	 	node* temp=head;
	 	int n=0;
	 	while(n<pos-1)
	 	{
	 		temp=temp->nxt;
	 		n++;
		 }
		 node* nodetodel=temp->nxt;
		 temp->nxt=NULL;
		 delete nodetodel;
	 	
	 }
	 else
	 {
	 	node* temp=head;
	 	int n=0;
	 	while(n<pos-1)
	 	{
	 		temp=temp->nxt;
	 		n++;
		 }
		 node* nodetodel=temp->nxt;
		 temp->nxt=nodetodel->nxt;
		 delete nodetodel;
	 }
 }
int main()
{
	node* mynode =new node(10);
	cout<<"MEMORY ADDRESS OF MAIN NODE IS:"<<mynode<<endl;
	node*head =mynode;
	insertatstart(head,11);
	insertatstart(head,12);
	insertatstart(head,13);
	insertatend(head,9);
	insertatpos(head,2,99);
	deletenode(head,5,6);
	print(head);
	getlen(head);	
}
