//Find the smallest window in a string containing all characters of another string
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
void window(string str1,string str2)
{
	for(int i=str2.length();i<str1.length();i++)
	{
		for(int j=0;j<str1.length()-i;j++)
		{
			int *arr=(int *)calloc(256,sizeof(int));
			for(int i1=0;i1<str2.length();i1++)
			{
				arr[str2[i1]]++;

			}
			string a=str1.substr(j,i);
			int count=0;
			for(int k=0;k<a.length();k++)
			{
				if(arr[a[k]]>0)
				{
					count++;
					arr[a[k]]--;
				}
			}
			if(count==str2.length())
			{
				cout<<" Answer is: "<<a<<"\n";
				return;
	//			break;
	//			flag=1;
			}
			free(arr);
		}
	//	if(flag==1)
	//		break;
	}

}
int main()
{
	int flag=0;
	string str1,str2;
	getline(cin,str1);
	getline(cin,str2);
	window(str1,str2);
	return 0;
}