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
void insertnode(node* &head, int d) {
    node* newnode = new node(d);
    cout<<"MEMORY ADDRESS OF NODE IS:"<<newnode<<" WITH THIS DATA:"<<d<<endl;
    if (head->next == NULL) { 
        head->next = newnode;
        newnode->next = head;
    } else {
        node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
}
void insertnodeafter(node* &head, int data, int newData) {
    node* temp = head;
    do {
        if (temp->data == data) {
            node* newNode = new node(newData);
            cout<<"MEMORY ADDRESS OF VALUE NODE IS:"<<newNode<<" WITH THIS DATA:"<<newData<<endl;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}


void print(node* &head)
{
	node* temp =head;
 do {
        cout<<"DATA IN THIS NODE IS: "<<temp->data<<endl;
		cout<<"THE NEXT NODE IS: "<<temp->next<<endl;
        temp = temp->next;
    } while (temp != head);
	cout<<endl;
}
void deletenode(node* &head,int d)
{
	node* current=head;
	node* pre=NULL;
	do
	{
		pre=current;
		current=current->next;
	}
	while(current->data!=d);
	pre->next=current->next;
	delete current;
	}
void linearsearch(node* &head,int d)
{
	node* temp=head;
	do
	{
		if(temp->data==d)
		{
			cout<<"this is the node with data:"<<temp<<endl;
			break;
		}
		temp=temp->next;
		
	}
	while(temp!=head);
}
int main()
{
	node* mynode=new node(10);
	cout<<"MEMORY ADDRESS OF MIAN NODE IS:"<<mynode<<endl;
	node* head=mynode;
	insertnode(head,9);
	insertnode(head,8);
	insertnode(head,7);
	insertnode(head,6);
	insertnodeafter(head,8,11);
	deletenode(head,6);
	linearsearch(head,7);
	print(head);
	
}
