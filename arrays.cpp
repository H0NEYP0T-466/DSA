#include<iostream>
using namespace std;
int main()
{
	int arr[4]={0,1,2,3};
	int a;
	cin>>a;
	for(int i=0;i<4;i++)
	{
		if(a==arr[i])
		{
			cout<<"match found at"<<i+1;
		}
	}
}
