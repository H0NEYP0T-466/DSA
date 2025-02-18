#include<iostream>
using namespace std;
void twosum(int arr[],int target)
{
	for(int i=0;i<6;i++)
	{
		for(int j=1;j<6;j++)
		{
			if(arr[i]+arr[j]==target){
			cout<<j<<" "<<i<<endl;
			}
		}
	}
}
void sort(int arr[])
{
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			if(arr[i]>arr[j])
			{
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
void optimal(int arr[],int target)
{
	sort(arr);
	int left=0,right=6-1;
	while(left<right)
	{
		if(arr[left]+arr[right]==target)
		{
			cout<<left<<" "<<right<<endl;
			break;
		}
		else if(arr[left]+arr[right]>target)
		{
			--right;
		}
		else
		{
			++left;
		}
	}
}
int main()
{
	int target=21;
	int arr[6]={2,4,5,3,20,1};
	twosum(arr,target);
	optimal(arr,target);
}
