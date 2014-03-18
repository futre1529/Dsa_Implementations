//Divide a string into n equal parts
#include<iostream>
#include<string>
using namespace std;
void divide(string s,int n)
{
	int l=s.length();
	if((l%n)!=0)
	{
		cout<<"String is not divisible";
		return;
	}
	int j=l/n;

	for(int i=0;i<l;i++)
	{
		if((i%j)==0)
		{
			cout<<"\n";
			cout<<s[i];

		}
		else
		{
			cout<<s[i];
		}
	}
}
int main()
{
	string str;
	cin>>str;
	int n;
	cin>>n;
	divide(str,n);
	return 0;
}