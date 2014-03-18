//infix to postfix
#include<iostream>
using namespace std;
#include<conio.h>
#include<cstring>

class convert
{
      public:
             char c[20];
             int top;
             void push(char ch);
             char pop();
             void change(char ch[],int l);
};
void convert::push(char ch)
{
     c[++top]=ch;
}
char convert::pop()
{
                return(c[top--]);
}
void convert::change(char s[],int l)
{
     cout<<"\nThe postfix expression is "<<endl;
     convert c;
     c.top=-1;
     int i=0;
     char ch;
     while(i<l)
     {
               if((s[i]<='z'&&s[i]>='a')||(s[i]>='A'&&s[i]<='Z'))
               cout<<s[i];
               else
               {
                   switch(s[i])
                   {
                               case '+':
                               case '-':
                                    while(c.top!=-1)
                                                    cout<<c.pop();
                                    c.push(s[i]);
                                    break;
                               case '*':
                               case '/':
                                    while(1)
                                    {
                                            ch=c.pop();
                                            if(ch=='*'||ch=='/')
                                                                cout<<ch;
                                            else
                                                {c.push(ch);c.push(s[i]);break;}
                                    }
                   }
               }
      i++;
      }
      while(c.top!=-1)
              cout<<c.pop();
              
}                   
int main()
{
    convert a;
    char s[20];
    cout<<"\nEnter the infix expression :";
    cin>>s;
    int l=strlen(s);
    cout<<l<<endl;
    a.change(s,l);
    getch();
}
                                                   
