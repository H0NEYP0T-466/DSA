#include<iostream>
#include<vector>
using namespace std;
class graph
{
	int numNode;
	vector<vector<int>> object;
	public:
		graph(int n)
		{
			this->numNode=n;
			object.resize(n,vector<int>(n,0));
		}
		void addedge(int s,int e)
		{
			object[s][e]=1;
			//object[e][s]=1;
		}
		void deledge(int s,int e)
		{
			object[s][e]=0;
			//object[e][s]=0;
		}
		void print()
		{
			for(int i=0;i<object.size();i++)
			{
				for(int j=0;j<object.size();j++)
				{
					cout<<object[i][j]<<" ";
				}
				cout<<endl;
			}
			
		}
};
int main()
{
	graph obj(3);
	obj.addedge(0,1);
	obj.addedge(1,2);
	obj.addedge(2,0);
	obj.print();
}
