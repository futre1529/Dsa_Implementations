//Remove all duplicates from the input string.
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a;
	bool hash[256]={false};

	printf("Enter size of string \n");
	scanf("%d",&a);
	char *str=(char*)calloc(a,sizeof(char));
	printf("Enter the string \n");
	scanf(" %[^\n]",str);
	int i=0;
	while(str[i]!='\0')
	{
		if(hash[(int)str[i]]==false)
		{
			printf("%c",str[i] );
			hash[(int)str[i]]=true;
		}
		i++;

	}
}