//Run Length Encoding
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;
int main()
{
	string str;
	string temp="";
	char buffer[250];
	cin>>str;
	int count=1;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]==str[i+1])
		{
			count++;
		}
		else
		{
			//itoa(count,buffer,10);
			stringstream ss;
			ss<<count;
			string buf = ss.str();
			temp=temp+str[i]+buf;
			count=1;

		}

	}
	cout<<"\n"<<temp;

}