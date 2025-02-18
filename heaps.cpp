#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
class heap
{
	public:
		int arr[100];
		int size=0;
	void insert(int data)
	{
		size=size+1;
		int index=size;
		arr[index]=data;
	while(index>1)
	{
		int parent=index/2;
		if(arr[parent]<arr[index])
		{
			swap(arr[parent],arr[index]);
			index=parent;
		}
		else return;
	}
	
	}
	void print()
	{
		for(int i=1;i<=size;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	
    
    void deletefromheap()
    {
    	if(size==0)
    	{
    		cout<<"nothing to delete\n";
		}
		arr[1]=arr[size];
		size--;
		int i=1;
		while(i<=size)
		{
			int right=2*i+1;
			int left=2*i;
			int largest=i;
			if(left<=size && arr[left]>arr[largest])
			{
				largest=left;
			}
			 if(right<=size && arr[right]>arr[largest])
			{
				largest=right;
			}
			if(largest!=i)
			{
				swap(arr[i],arr[largest]);
				i=largest;
			}
			else break;
		}
	}
};

void heapify(int arr[],int n,int i)
{
	int l=2*i;
	int r=2*i+1;
	int smallest=i;
	if(l<=n && arr[smallest]>arr[l])
	{
		smallest=l;
	}
	if(r<=n && arr[smallest]>arr[r])
	{
		smallest=r;
	}
	if(smallest!=i)
	{
		swap(arr[smallest],arr[i]);
		heapify(arr,n,smallest);
	}
}
void heapsort(int arr[],int n)
{
	int size=n;
	while(size>1)
	{
	  swap(arr[size],arr[1]);
		size--;
		heapify(arr,size,1);
	}
}
int main()
{
	heap h;
	h.insert(60);
	h.insert(50);
	h.insert(40);
	h.insert(30);
	h.insert(20);
	h.insert(70);
	h.print();
	h.deletefromheap();
	h.print();
	int arr[10]={-1,22,33,44,55,66,43,77,111,112};
	int n=9;
	for(int i=n/2;i>0;i--)
	{
		heapify(arr,n,i);
	}
	cout<<"PRINTING  MIN HEAPS\n";
	for(int i=1;i<=n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<"HEAP SORT\n";
	heapsort(arr,n);
	for(int i=n;i>=1;i--)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	priority_queue<int> pq;
	pq.push(12);
	pq.push(14);
	pq.push(1);
	pq.push(4);
	cout<<"\n on top:"<<pq.top()<<endl;
	pq.pop();
	cout<<"\n on top:"<<pq.top()<<endl;
	
	priority_queue<int, vector<int>,greater<int>> mh;
	mh.push(44);
	mh.push(25);
	mh.push(11);
	mh.push(3);
	cout<<"\n min heap on top:"<<mh.top()<<endl;
	mh.pop();
	cout<<"\n min heap on top:"<<mh.top()<<endl;
}
