#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main()
{
	//map creation
	unordered_map <string,int> obj;
    //pair making of key and value
	pair<string,int> m=make_pair("shoiab",99);
	//inserting methord 1
	obj.insert(m);
	pair<string,int> pair2("aliraza",101);
	//inserting methord 2
	obj.insert(pair2);
	//inserting methord 3
	obj["faizan"]=1000;
	//printing methord 1
	cout<<obj["faizan"]<<endl;
	//printing methord 2
	cout<<obj.at("shoiab")<<endl;
	//size
	cout<<obj.size()<<endl;
	//count
	cout<<obj.count("faizan")<<endl;
	//itereator traverse full map
	unordered_map<string,int> ::iterator object=obj.begin();
	while(object !=obj.end())
	{
		cout<<"KEY:"<<object->first<<" "<<"VALUE:"<<object->second<<endl;
		object++;
		
	}
	//using for loop
	for(auto i:obj)
	{
		cout<<"key:"<<i.first<<"value:"<<i.second<<endl;
	}
}
