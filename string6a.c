#include <stdio.h>
void reverse(char * a)
{
	if(*a!='\0')                           //if(a[i]!='\0') will also work
	{
		reverse(a+1);
	}
	printf("%c",*a);
}

int main()
{
	char str[20];
	puts(" Enter the string");
	gets(str);
	reverse(str);
	return 0;
}