// /A Program to check if strings are rotations of each other or not   usinbg <cstring>    

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;
int rotation(char *a,char *b)
{
	char *temp=(char *)calloc(40,sizeof(char));
	//temp[0]='\0';

	strcpy(temp,a);
	strcat(temp,a);
	char *check = strstr(temp,b);
	if(check!=NULL)
		return 1;
	else
		return 0;

}
int main()
{

	char *str1=(char *)calloc(20,sizeof(char));
	char *str2=(char *)calloc(20,sizeof(char));
	printf("Enter string 1 \n");
	gets(str1);
	printf("Enter string 2 \n");
	gets(str2);
	if(rotation(str1,str2))
	{
		puts("Yes");

	}
	else
	{
		puts("No");
	}
	return 0;
	
}