// /A Program to check if strings are rotations of each other or not..........using string header file
#include <iostream>
#include <string>
using namespace std;
bool rotation(string str1,string str2)
{
	string str3 = str1 + str1;
	//char *pos=strstr(str3,str2);
	int found =str3.find(str2); 
	if(found<str3.length())
		return true;
	else
		return false;

}
int main()
{
	string str1,str2;
	cin>>str1>>str2;
	if(rotation(str1,str2))
	{
		cout<<"Yes";

	}
	else
	{
		cout<<"No";
	}
	return 0;


}