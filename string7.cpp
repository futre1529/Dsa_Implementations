// Tp print all permutations of a given string
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void permute(string str,int i, int j)
{
	if(i==j)
		cout<<str<<"\n";
	else
	{
		for(int k=i;k<j;k++)
		{
			swap(str[i],str[k]);
			permute(str,i+1,j);
			swap(str[i],str[k]);
		}

	}
}

int main()
{
	string str;
	cin>>str;
	int n=str.length();
	permute(str,0,n);
	return 0;
}
