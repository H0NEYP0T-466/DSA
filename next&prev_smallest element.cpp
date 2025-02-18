#include<iostream>
using namespace std;
#include<stack>
int nextSmallElement(int arr[4],int ans[4])
{
	stack<int> s;
	s.push(-1);
	for(int i=4-1;i>=0;i--)
	{
		int curr=arr[i];
		while(s.top()>=curr)
		{
		    s.pop();
		}
		ans[i]=s.top();
		s.push(curr);
	}
	for(int i=0;i<4;i++)
	{
		cout<<ans[i]<<" ";
	}
}
int prevSmallElement(int arr[4],int ans[4])
{
	stack<int> s;
	s.push(-1);
	for(int i=0;i<4;i++)
	{
		int curr=arr[i];
		while(s.top()>=curr)
		{
		    s.pop();
		}
		ans[i]=s.top();
		s.push(curr);
	}
	for(int i=0;i<4;i++)
	{
		cout<<ans[i]<<" ";
	}
}
int main()
{
	
	int arr[4]={2,1,4,3};
	int ans[4];
	nextSmallElement(arr,ans);
	cout<<endl;
	prevSmallElement(arr,ans);
	
}
