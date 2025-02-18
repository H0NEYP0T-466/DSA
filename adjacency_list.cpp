#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class graph
{
	public:
	unordered_map<int, list<int>> object;
		void addedge(int first,int second,bool direction)
		{
			object[first].push_back(second);
			if(direction==0)
			{
				object[second].push_back(first);
			}
		}
		void print()
		{
			for(auto i:object)
			{
				cout<<i.first<<"->";
				for(auto j:i.second)
				{
					cout<<j<<", ";
				}
				cout<<endl;
			}
		}
};
int main()
{
	cout<<"enter the number of edges\n";
	int m;
	cin>>m;
	graph obj;
	for(int i=0;i<m;i++)
	{
		int first,second;
		cin>>first>>second;
		obj.addedge(first,second,0);
	}
	obj.print();
}
