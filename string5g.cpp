// General solution to problem 5 without using any pre defined function
#include <iostream>
using namespace std;
int main()
{
	int flag=0;
	string str1,str2;
	int length=0;
	
	cin>>str1>>str2;
	while(str1[length]!='\0')
		length++;
	int i=0,j=0;
	while(1)
	{

	while( (str1[i]!=str2[j]) && str1[i]!='\0')
	{
		i++;
	}
	if(str1[i]=='\0')
	{
		cout<<"fuck off";
		break;
	}
	int temp=i+1;
	while(1)
	{
		if(str2[j]=='\0')
		{
			flag=1;
			break;
		}
		else if(str1[i%length]==str2[j])
		{
			i++;
			j++;
		}
		else
		{
			i=temp;
			break;

		}
		
	}
	if(flag==1)
	{
		cout<<"Pela";
		break;

	}
		//break;
}

}