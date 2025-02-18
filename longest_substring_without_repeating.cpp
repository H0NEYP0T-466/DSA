#include<iostream>
using namespace std;
#include<vector>
int main()
{
	string s="pwwkew";
	int start=-1,maxlen=0;
	vector<int> window(256,-1);
	for(int i=0;i<s.size();i++)
	{
		if(window[s[i]]>start)
		{
			start=window[s[i]];
		}
		window[s[i]]=i;
		maxlen=max(maxlen,i-start);
	}
	cout<<maxlen;
}
