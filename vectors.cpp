#include<iostream>
#include<vector>
#include<list>
using namespace std;
int main()
{
	vector<int>v;
	v.push_back(11);
	v.push_back(22);
	v.push_back(9);
	v.push_back(19);
	v.push_back(3);
	v.pop_back();
	pair<int,int>p;
	p.first=99;
	p.second=101;
	list<int> mylist;
	mylist.push_front(10);
	mylist.push_front(1110);
	mylist.push_back(110);
	mylist.push_front(101);
	cout<<"list\n";
	for(auto i:mylist)
	{
		cout<<i<<endl;
	}
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<endl;
	}
	
}
