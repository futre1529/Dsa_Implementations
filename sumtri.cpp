#include<iostream>
using namespace std;
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<vector>
 
using namespace std;
 
char inp[10000000];
char *ptr;
int v[200][200];
 
inline int SCAN_INT(void)
{
    while(!(*ptr<='9' && *ptr>='0'))
        ptr++;
    int  ret=0;
    while(*ptr<='9' && *ptr>='0')
        ret=ret*10+(*(ptr++))-'0';
    return ret;
}
 
int main()
{
    //freopen("input.txt","r", stdin);
	fread(inp, sizeof(char), 10000000, stdin);
	ptr = inp;
	int t,n;
	t=SCAN_INT();
	while(t--){
        n=SCAN_INT();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
                v[i][j]=SCAN_INT();
        for(int i=n-1;i>0;i--){
            for(int j=i;j>0;j--){
                v[i][j]=max(v[i+1][j],v[i+1][j+1]) + v[i][j];
            }
        }
        printf("%d\n",v[1][1]);
        getch();
	}
}
 
