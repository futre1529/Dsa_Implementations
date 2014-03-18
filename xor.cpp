#include<iostream>
using namespace std;

int main()
{
int b=012;
int x,y=0;
for(x=1;x<=10;x++)
y=y^x;
cout<<"XOR="<<y<<endl;
cout<<b<<endl;
return 0;
}
