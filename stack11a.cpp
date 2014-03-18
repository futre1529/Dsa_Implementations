#include<iostream>
using namespace std;
#include<conio.h>
#include<cstring>

class convert
{
      public:
             int top;
             char ch[20];
             void push(char x);
             char pop();
             void conversion(char a[],int);
};
void convert::push(char x)
{
     ch[++top]=x;
}
char convert::pop()
{
     return(ch[top--]);
}
void convert::conversion(char a[],int l)
{
     convert t;
     t.top=-1;
     char ar[20],ch;
     int i=0,j=0,flag=0;
     cout<<"\nThe reqiured infix expression is :";
     while(i<l)
     {
               if(a[i]<='z'&&a[i]>='a')
               {
                                       ar[j]=a[i];
                                       j++;i++;
               }
               else
               {
                   switch(a[i])
                   {
                               case '+':
                                    case '-':
                                         j=0;
                                         if(flag==0)
                                                    cout<<ar[j++];
                                         t.push(a[i]);
                                         while(t.top!=-1)
                                         {
                                                         cout<<t.pop();
                                                         cout<<ar[j++];
                                         }
                                         flag=1;j=0;
                                         break;
                               case '*':
                                    case'/':
                                            t.push(a[i]);
                                            break;
                   }
                   i++;
               }
     }
}
int main()
{
    convert t;
    char s[20];
    cout<<"\nEnter the postfix expression :";
    cin>>s;
    int l=strlen(s);
    t.conversion(s,l);
    getch();
}                                                                                                                    
