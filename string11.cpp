//Print list items containing all characters of a given word
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int n;
	cout<<"Enter the no of strings to check \n";
	cin>>n;
	string *list=new string[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the strings \n";
		cin>>list[i];
	}
	cout<<"\n Answer: \n";
	for(int i=0;i<n;i++)
	{
		int count=0,count1=0;
		int *check=(int*)calloc(256,sizeof(int));
		for(int k=0;k<str.length();k++)
		{
			if(check[str[k]]==0)
			{
				count++;
				check[str[k]]=1;
			}
		}
		for(int k=0;k<(list[i].length());k++)
		{
			if(check[list[i][k]]==1)
			{
				count1++;
				check[list[i][k]]=0;
			}
		}
		//cout<<count<<"..........."<<count1;
		if(count==count1)
		{
			cout<<list[i]<<"\n";
		}
	}
	

}