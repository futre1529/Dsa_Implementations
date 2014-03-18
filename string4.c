//Remove characters from the first string which are present in the second string.
#include<stdio.h>
#include<stdlib.h>
char* masker(char *a,char *b)
{
	char *c=(char*)calloc(100,sizeof(char));
    int hash[256]={0};
	int i=0;
	while(b[i]!='\0')
	{
		hash[b[i]]++;
		i++;
	}
	i=0;int j=0;
	while(a[i]!='\0')
	{
		if(hash[a[i]]==0)
		{
			c[j++]=a[i];

		}	

		i++;

	}
	c[j]='\0';
	return c;

}
int main()
{
	char *str=(char*)calloc(100,sizeof(char));
	char *mask=(char*)calloc(100,sizeof(char));
	scanf(" %[^\n]",str);
	scanf(" %[^\n]",mask);
	char *fstr=masker(str,mask);
	printf("%s\n",fstr );
}