//direct evaluation of infix
#include<iostream>
using namespace std;
#include<conio.h>
#include<cstring>

class evaluate
{
      public:
             char c[20];
             int a[20];
             int top;
             void push(int x);
             int pop();
             void pushi(char);
             char popi();
             void conversion(char [],int);
             void process(evaluate &,char);
};

void evaluate::push(int ch)
{
     a[++top]=ch;
     cout<<"\npushed :"<<ch;
}
int evaluate::pop()
{
                return(a[top--]);
}
void evaluate::pushi(char ch)
{
     c[++top]=ch;
     cout<<"\npushed :"<<ch;
}
char evaluate::popi()
{
                return(c[top--]);
}
void evaluate::conversion(char ch[],int l)
{
     evaluate s1,s2;
     s1.top=-1;s2.top=-1;
     int i=0;char a,b;
     while(i<l)
     {
               if(ch[i]<='9'&&ch[i]>='0')
                                         {s1.push(int(ch[i]-'0'));i++;}
               else
               {
                   a=ch[i];
                   switch(a)
                   {
                             case '+':
                             case '-':
                                  while(s2.top!=-1)
                                  {
                                                   b=s2.popi();
                                                   s1.process(s1,b);
                                  }
                                  s2.pushi(a);
                                  break;
                             case '*':
                             case '/':
                                  while(1)
                                    {
                                            b=s2.popi();                                            
                                            if(b=='*'||b=='/')
                                                                s1.process(s1,b);
                                            else
                                                {s2.pushi(b);s2.pushi(ch[i]);break;}
                                    }
                   }
                   i++;
               }
        }
        while(s2.top!=-1)
        {
                         b=s2.popi();
                         s1.process(s1,b);
        }
        cout<<"\n The value of the expression is :"<<s1.pop();
}
void evaluate::process(evaluate &s,char ch)
{
     int n1=s.pop();
     int n2=s.pop();
     cout<<endl<<n1<<"---------"<<n2<<endl;
     switch(ch)
     {
               case '+':
                       s.push(n1+n2);
                       return;
               case '-':
                       s.push(n2-n1);
                       return;
               case '*':
                       s.push(n1*n2);
                       return;
               case '/':
                       s.push(n2/n1);
                       return;
     }
}
int main()
{
     evaluate s;
     char ch[20];
     cout<<"\nEnter the mathematical expression :";
                    cin>>ch;
     int l=strlen(ch);
     s.conversion(ch,l);
     getch();
}
