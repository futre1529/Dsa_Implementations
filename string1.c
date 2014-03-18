//Return maximum occurring character in the input string
#include<stdio.h>
#include<stdlib.h>
int main()
{
	//char a[]="Manas Joshi";
	int s;int i=0;
	int count[256];
	for(int k=0;k<256;k++)
		count[k]=0;
		//int *count=(int*)calloc(2566,sizeof(int));
	printf("Enter size of string\n");
	scanf("%d",&s);
	//char *a=malloc(s * sizeof(char));
	char *a=(char*)calloc(s,sizeof(char));
	printf("Enter the string \n");
	scanf(" %[^\n]",a);
	//printf("\n%s \n",a );
	//printf("\n%c\n",a[3] );
	while(a[i]!='\0')
	{
		count[int(a[i])]++;
		i++;


	}
	int max=count[0];char maxchar='a';
	for(int j=1;j<256;j++)
		if (count[j]>max)
		{
			max=count[j];

			maxchar = char(j);
		}
	printf("%c\n",maxchar );
	return 0;
}