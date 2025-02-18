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
bst* insertbst(bst* &root,int d)
{
	if(root==nullptr)
	{
		root=new bst(d);
		return root;
	}
    if(d>root->data)
	{
		 root->right=insertbst(root->right,d);
	}
	else
	{
	   root->left=insertbst(root->left,d);
	}
	return root;
}
bst* insert(bst* &root)
{
	int data;
	cin>>data;
	while(data!=-1)
	{
		insertbst(root,data);
		cin>>data;
	}
	return root;
}
void inorder(bst* &root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
bst* deletenode(bst* &root,int d)
{
	if(root==nullptr)
      {
      	return nullptr;
	  }
	 if(d>root->data)
	{
		root->right=deletenode(root->right,d);
		return root;
	}
	else if(d<root->data)
	{
		root->left=deletenode(root->left,d);
		return root;
	}
	else
	{
		if(root->left ==nullptr && root->right ==nullptr)
		{
			delete root;
			return nullptr;
		}
		 if(root->left !=nullptr && root->right ==nullptr)
		{
			bst* temp=root->left;
			delete root;
			return temp;
		}
	    if(root->left ==nullptr && root->right !=nullptr)
		{
			bst* temp=root->right;
			delete root;
			return temp;
		}
		if(root->left !=nullptr && root->right !=nullptr)
		{
			int maxi=maximum(root->left)->data;
			root->data=maxi;
			root->left=deletenode(root->left,maxi);
			return root;
		}
	
	}
}
int main()
{
	bst* root=nullptr;
	cout<<"ENTER DATA FOR BST:\n";
	root=insert(root);
	inorder(root);
	cout<<endl;
	root=deletenode(root,33);
	root=deletenode(root,30);
	root=deletenode(root,34);
	inorder(root);
}
