#include<iostream>
#include<vector>
using namespace std;
class tree
{
	public:
		int data;
		tree* left;
		tree* right;
	tree(int d)
	{
		this->data=d;
		this->left=nullptr;
		this->right=nullptr;
	}
};

void inorder(tree* &root,vector<int> & order)
	{
		tree* temp=root;
		if(temp==nullptr)
		{
			return;
		}
		inorder(root->left,order);
		order.push_back(root->data);
		inorder(root->right,order);
}

bool isvalid(vector<int>& list)
{
	for(int i=1;i<list.size();i++)
	{
		if(list[i]<list[i-1])
		return false;
	}
	return true;
}
bool bst(tree* &root)
{
	vector<int> order;
	inorder(root,order);
	return isvalid(order);
}
int main()
{
	tree* root;
	tree* mytree=new tree(50);
	root=mytree;
	mytree->left=new tree(41);
	mytree->left->left=new tree(30);
	mytree->left->right=new tree(44);
	mytree->right=new tree(55);
	mytree->right->left=new tree(51);
	mytree->right->right=new tree(59);
	cout<<bst(root)<<endl;
	tree* root2;
	tree* newtree=new tree(50);
	root2=newtree;
	newtree->left=new tree(55);
	newtree->left->left=new tree(60);
	newtree->left->right=new tree(29);
	newtree->right=new tree(11);
	newtree->right->left=new tree(2);
	newtree->right->right=new tree(3);
	cout<<bst(root2);
	
	
}
