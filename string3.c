//Print all duplicates from the input string and their count.
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a;
	int hash[256]={0};

	printf("Enter size of string \n");
	scanf("%d",&a);
	char *str=(char*)calloc(a,sizeof(char));
	printf("Enter the string \n");
	scanf(" %[^\n]",str);
	int i=0;
	while(str[i]!='\0')
	{
		hash[(int)str[i]]++;
		i++;
	}
	for(i=0;i<256;i++)
	{
		if(hash[i]>1)
		{
			printf("%c\t",(char)i);
			printf("Count is %d\n",hash[i]);
		}
	}
}