#include <stdio.h>
void reverse(char * a,int i)
{
	if(a[i+1]!='\0')                           //if(a[i]!='\0') will also work
	{
		reverse(a,i+1);
	}
	printf("%c",a[i]);
}

int main()
{
	char str[20];
	puts(" Enter the string");
	gets(str);
	reverse(str,0);
	return 0;
}