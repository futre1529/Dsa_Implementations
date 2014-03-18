//Given a string, find its first non-repeating character
// Optimiused solution for large strings. No two scans of string required
#include<iostream>
#include<string>
using namespace std;
struct node
{
	int count;
	int index;
	node()
	{
		count=0;
		index=-1;
	}
};
int main()
{
	string str;
	cin>>str;
	node arr[256];
	cout<<arr[10].count<<"\n";
	cout<<arr[10].index<<"\n";
	for(int i=0;i<str.length();i++)
	{
		(arr[str[i]].count)++;
		if((arr[str[i]].index)==-1)
		{
			arr[str[i]].index=i;

		}

	}
	int min=257;
	for(int j=0;j<256;j++)
	{
		if(arr[j].count==1)
		{
			if(arr[j].index<min)
				min=arr[j].index;
		}
	}
	cout<<" The answer is : "<<str[min]<<"\n";


}