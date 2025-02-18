#include<iostream>
using namespace std;
int main()
{
	int arr[10]={1,1,1,2,2,3,4,4,4,4};
	int count=0;
	for(int i=0;i<10;i++)
	{
		for(int j=1;j<10;j++)
		{
			if(arr[i]==arr[j])
			{
				count++;
			}
		}
		cout<<"frequency of:"<<arr[i]<<"is:"<<count<<endl;
		count=0;
		
	}
}
