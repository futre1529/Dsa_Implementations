//evaluation of postfix
#include<iostream>
using namespace std;
#include<conio.h>
#include<cstring>

class convert
{
      public:
             int a[20];
             char c[20];
             int top;
             void push(char ch);
             char pop();
             void pushi(int ch);
             int popi();
             void change(char ch[],int l);
             void evaluate(char ch[],int l);
};
void convert::push(char ch)
{
     c[++top]=ch;
}
char convert::pop()
{
                return(c[top--]);
}
void convert::pushi(int ch)
{
     a[++top]=ch;
}
int convert::popi()
{
                return(a[top--]);
}

void convert::change(char s[],int l)
{    
     char str[20];
     cout<<"\nThe postfix expression is "<<endl;
     convert c;
     c.top=-1;
     int i=0,j=0;
     char ch;
     while(i<l)
     {
               if((s[i]<='z'&&s[i]>='a')||(s[i]>='A'&&s[i]<='Z'||s[i]<='9'&&s[i]>='0'))
               {cout<<s[i];str[j++]=s[i];}
               else
               {
                   switch(s[i])
                   {
                               case '+':
                               case '-':
                                    while(c.top!=-1)
                                                    {ch=c.pop();cout<<ch;str[j++]=ch;}
                                    c.push(s[i]);
                                    break;
                               case '*':
                               case '/':
                                    while(1)
                                    {
                                            ch=c.pop();
                                            if(ch=='*'||ch=='/')
                                                                {cout<<ch;str[j++]=ch;}
                                            else
                                                {c.push(ch);c.push(s[i]);break;}
                                    }
                   }
               }
      i++;
      }
      while(c.top!=-1)
              {ch=c.pop();cout<<ch;str[j++]=ch;}
      cout<<"\nThe new postfix is :"<<str;
      c.evaluate(str,l);        
}
void convert::evaluate(char ch[],int l)
{
     cout<<endl;
     convert t;
     t.top=-1;
     int n1,n2,i=0;
     cout<<endl;
     while(i<l)
     {
     if(ch[i]=='+'||ch[i]=='-'||ch[i]=='*'||ch[i]=='/')
     {
         switch(ch[i])
         {
                      case '+':
                           n1=t.popi();
                           n2=t.popi();
                           cout<<n1<<" "<<n2<<endl;
                           t.pushi(n1+n2);
                           break;
                      case '-':
                           n1=t.popi();
                           n2=t.popi();
                           cout<<n1<<" "<<n2<<endl;
                           t.pushi(n2-n1);
                           break;
                      case '*':
                           n1=t.popi();
                           n2=t.popi();
                           cout<<n1<<" "<<n2<<endl;
                           t.pushi(n1*n2);
                           break;
                      case '/':
                           n1=t.popi();
                           n2=t.popi();
                           cout<<n1<<" "<<n2<<endl;
                           t.pushi(n2/n1);
                           break;
         }
     }
     else
             t.pushi(int(ch[i]-'0'));
     i++;
     }
     cout<<"\nThe final value of the expression is :"<<t.popi();
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
