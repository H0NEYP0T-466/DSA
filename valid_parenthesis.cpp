#include<iostream>
#include<stack>
using namespace std;
bool valid(string bracket)
{
	stack<char> s;
	for(int i=0;i<bracket.size();i++)
	{
		char first=bracket[i];
		if(first=='('||first=='{'||first=='[')
		{
			s.push(first);
		}
		else
		{
			if(!s.empty())
			{
				char top=s.top();
				if(first==')'&&top=='(' || first=='}'&& top=='{' ||first==']' && top=='[')
				{
					s.pop();
				}
				else
				{
					return false;
				}
			}
			else
			{
				//stack is empety
				return false;
			}
		}
	}
	if(s.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
int main()
{
	string s="(){}{}{}[]";
	bool res;
	res=valid(s);
	if(res)
	{
		cout<<"balanced/valid paranthesis\n";
	}
	else
	{
		cout<<"unbalanced/not valid paranthesis\n";
	}
	return 0;
}
