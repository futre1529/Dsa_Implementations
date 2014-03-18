//Given a string, find its first non-repeating character
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int *arr=(int *)calloc(256,sizeof(int));

	for(int i=0;i<str.length();i++)
	{
		arr[str[i]]++;
	}
	for(int i=0;i<str.length();i++)
	{
		if(arr[str[i]]==1)
		{
			cout<<" The first unrepeated character is :"<<str[i]<<"\n";
			break;

		}
			
	}
}