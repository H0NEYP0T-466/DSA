#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
void twosum(int arr[], int target)
{
		for(int i=0;i<6;i++)
	{
		for(int j=i+1;j<6;j++)
		{
			if(arr[i]+arr[j]==target)
			{
				cout<<"match found at index number:"<<j<<" "<<i<<endl;
			}
		}
		
	}
}
void usehashmap(int arr[],int target,int size)
{
	unordered_map<int,int> hashmap;
	for(int i=0;i<size;i++)
	{
		int sub=target-arr[i];
		if(hashmap.find(sub)!=hashmap.end())
		{
			cout<<"match found:"<<hashmap[sub]<<" "<<i<<endl;
			return;
		}
		hashmap[arr[i]]=i;
			
	}
}
void twosumoptimal(int arr[],int target,int size)
{
	sort(arr,arr+size);
		int left=0,right=size-1;
	while(left<=right)
	{
	if(arr[left]+arr[right]==target)
	{
		cout<<"match found at index number:"<<left<<" "<<right<<endl;
		break;
	}
	else if(arr[left]+arr[right]>target)
	{
		right--;
	}
	else
	{
		left++;
	}
	}
}
int main()
{
	int n=6;
	int arr[n]={3,2,1,9,12,7};
	int target=21;
	twosum(arr,target);
	usehashmap(arr,target,n);
	twosumoptimal(arr,target,n);
	
}
