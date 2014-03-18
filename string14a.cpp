// Time complexity= O(n) Find the smallest window in a string containing all characters of another string.
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
	string str;
	getline(cin,str);
	string str1;
	getline(cin,str1);
	int count=0;
	int wbegin=-1,wend=-1;
	int tbegin,tend,min=str.length()+1;
	int *arr=(int *)calloc(256,sizeof(int));
	int *check=(int *)calloc(256,sizeof(int));
	for(int i=0;i<str1.length();i++)
	{
		arr[str1[i]]++;
		if(str1[i]!=32)
		count++;
	}
	cout<<count;
	int count1=0;
	cout<<"1";
	for(int i=0;i<str.length();i++)
	{
		cout<<str[i];
		if((arr[str[i]]>0)&&(wbegin==-1))
		{
			wbegin=i;
			count1++;
			check[str[i]]++;
			cout<<"2";
		}
		else if(arr[str[i]]>0)
		{
			check[str[i]]++;
			if (check[str[i]]<=arr[str[i]])
			{
				count1++;
				if(count==count1)
				{
					wend=i;
					if((wend-wbegin)<min)
					{
						tbegin=wbegin;
						tend=wend;
						min=wend-wbegin;
						cout<<"3";
					}
				}
			}
			else if((str[i]==str[wbegin])&&(wend!=-1))
			{
				wend=i;
				check[str[i]]--;
				while(1)
				{
					wbegin++;
					cout<<"4";

					if(arr[str[wbegin]]<check[str[wbegin]])
						check[str[wbegin]]--;
					else if((arr[str[wbegin]]==check[str[wbegin]]) && (arr[str[wbegin]]>0))
						break;
				}
				if((wend-wbegin)<min)
				{
					tbegin=wbegin;
					tend=wend;
					min=wend-wbegin;
					cout<<"5";
				}

			}

		}


	}
	string ans=str.substr(wbegin,(wend-wbegin)+1);
	cout<<"\n Answer is:"<<ans<<"\n";

}