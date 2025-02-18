#include<iostream>
using namespace std;
class tree
{
	public:
		string data;
		tree* left;
		tree* right;
	tree(string d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};
void preorder(tree* current)
{
	if(current==nullptr)
	{
		return;
	}
	cout<<current->data;
	preorder(current->left);
    preorder(current->right); 
}
void inorder(tree* current)
{
	if(current==nullptr)
	{
		return ;
	}
	inorder(current->left);
	cout<<current->data;
    inorder(current->right); 
}
void postorder(tree* current)
{
	if(current==nullptr)
	{
		return;
	}
	postorder(current->left);
    postorder(current->right);
	cout<<current->data; 
}
tree* searchnode(tree* current,string data)
{
	if(current==nullptr || current->data==data)
	{
		return current;
	}
	tree* leftsubtree=searchnode(current->left,data);
	if(leftsubtree!=NULL)
	{
		return leftsubtree;
	}
	return searchnode(current->right,data);
}
int main()
{
	tree* root=new tree("A");
	root->left=new tree("B");
	root->left->left=new tree("D");
	root->left->right=new tree("E");
	root->right=new tree("C");
	root->right->left=new tree("F");
	root->right->right=new tree("G");
	cout<<"PREORDER:\n";
	preorder(root);
	cout<<"\nINORDER:\n";
	inorder(root);
	cout<<"\nPOSTORDER:\n";
	postorder(root);
	tree* res=searchnode(root,"A");
	{
		if(res)
		{
			cout<<"\nNODE FOUND WITH THIS DATA:"<<res->data<<" AND THIS ADDRESS:"<<res<<endl;
		}
		else
		{
			cout<<"\nNODE NOT FOUND\n";
		}
	}
}
