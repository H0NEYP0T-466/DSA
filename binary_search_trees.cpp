#include<iostream>
using namespace std;
class bst
{
	public:
		int data;
		bst* left;
		bst* right;
	bst(int d)
	{
		data=d;
		left=nullptr;
		right=nullptr;
	}
};
bst* insertbst(bst* &root,int data)
{
	if(root==nullptr)
	{
		root=new bst(data);
		return root;
	}
	if(data>root->data)
	{
		root->right=insertbst(root->right,data);
	}
	else
	{
		root->left=insertbst(root->left,data);
	}
	return root;
}
bst* insert(bst* &root)
{
	int data;
	cin>>data;
	while(data!= -1)
	{
		insertbst(root,data);
		cin>>data;
	}
	return root;
}
void inorder(bst* root)
{
	if(root==nullptr)
	{
		return;
	}
	inorder(root->left);
	cout<<root->data<<"\t";
	inorder(root->right);
}
bst* searchbst(bst* &root,int x)
{
	if(root==nullptr)
	{
		return nullptr;
	}
	if(root->data==x)
	{
		return root;
	}
	if(root->data>x)
	{
		return searchbst(root->left,x);
	}
	else
	{
		 return searchbst(root->right,x);
	}
}
void minimum(bst* &root)
{
	bst* temp=root;
	while(temp->left)
	{
		temp=temp->left;
	}
     cout<<"MINIMUM VALUE OF BST IS:"<<temp->data<<endl;
}
bst* maximum(bst* &root)
{
	bst* temp=root;
	while(temp->right)
	{
		temp=temp->right;
	}
	return temp;
}
bst* deletenode(bst* root,int x)
{
	if(root==nullptr)
	{
		return nullptr;
	}
	if(root->data==x)
	{
		//no child
		if(root->left && root->right ==NULL)
		{
			delete root;
			return NULL;
		}
		
		//1 child
		    //left child
		       if(root->left!=NULL && root->right==nullptr)
		       {
		       	bst* temp=root->left;
		       	delete root;
		       	return temp;
			   }
		    //right child
		       if(root->left==NULL && root->right !=nullptr)
		       {
		       	bst* temp=root->right;
		       	delete root;
		       	return temp;
			   }
		//2 childs
		if(root->left && root->right !=nullptr)
		{
			int maxi=maximum(root->left)->data;
			root->data=maxi;
			root->left=deletenode(root->left,maxi);
			return root;
		}
	}
	else if(root->data>x)
	{ 
		//left me ja bhi
		root->left=deletenode(root->left,x);
		return root;
	}
	else
	{
		//right me ja bhai
		root->right=deletenode(root->right,x);
		return root;
	}
}
int main()
{
  bst* root=nullptr;
  cout<<"ENTER DATA FOR BINARY SEARCH TREE:\n";
  root=insert(root);
  inorder(root);
  cout<<endl;
  
  bst* temp=searchbst(root,57);
  if(temp)
  {
  	cout<<"MATCH FOUND WITH THIS DATA:"<<temp->data<<endl;
  }
  else
  {
  	cout<<"MATCH NOT FOUND\n";
  }
  minimum(root);
  bst* a=maximum(root);
  cout<<"MAXINUM VALUE IN BST IS:"<<a->data<<endl;
  root=deletenode(root,33);
  root=deletenode(root,30);
  root=deletenode(root,34);
  inorder(root);
}
