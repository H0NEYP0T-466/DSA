#include<iostream>
using namespace std;
class avltree
{
	public:
		int data;
		avltree* left;
		avltree* right;
	avltree(int d)
	{
		data=d;
		left=nullptr;
		right=nullptr;
	}
};
int checkheight(avltree* root)
{
	if(root==nullptr)
	{
		return 0;
	}
	int l=checkheight(root->left);
	int r=checkheight(root->right);
	 cout<<"left:"<<l<<endl;
	 cout<<"right:"<<r<<endl;
    return (max(l,r)+1);
}
bool isbalance(avltree* root)
{
	if(root==nullptr)
	{
		return true;
	}
	int lh=checkheight(root->left);
	int rh=checkheight(root->right);
	return (abs(lh-rh)<=1)&& isbalance(root->left)&&isbalance(root->right);
}
int main()
{
       
	   //
	   avltree* root2=new avltree(1);
	   root2->left=new avltree(2);
	   root2->left->left=new avltree(4);
	   root2->left->right=new avltree(5);
	   root2->right=new avltree(3);
	   int h=checkheight(root2);
	   cout<<h;
	   if(isbalance(root2))
	   {
	   	cout<<"THE TREE IS BALANCED\n";
	   }
	   else
	   {
	   	cout<<"THE TREE IS NOT BALANCED\n";
	   }
	   return 0;
}
