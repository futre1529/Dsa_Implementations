//Reverse words in a given string
#include <iostream>
#include <string>
#include <stack>
#include <cstdio>
using namespace std;
int main()
{
	string str;
	getline(cin,str);
	//int i=0;
	string temp="";
	stack<string> s1;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]!=32)
		{
			temp=temp+str[i];
			//i++;
			//cout<<temp;
		}
		else
		{
			s1.push(temp);
			//i++;
			temp="";
		}
	}
	s1.push(temp);
	cout<<"\n Answer : ";
	//cout<<s1.size();
	while(!s1.empty())
	{
		cout<<s1.top()<<" ";
		s1.pop();
	}
	return 0;

}