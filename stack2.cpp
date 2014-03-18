//brace matching
#include<iostream>
using namespace std;
#include<conio.h>
#include<cstring>

class braces
{
      public:
             char c[20];
             int top;
             void push(char ch);
             char pop();
             void check(char s[],int l);
};
void braces::push(char ch)
{
     c[++top]=ch;
}
char braces::pop()
{
     if(top!=-1)
                return(c[top--]);
     else return(-1);
}
void braces::check(char s[],int l)
{
         braces c;
         c.top=-1;
         int i=0,flag=1;char ch;
         while(i<l)
         {
                   if(s[i]=='('||s[i]=='{'||s[i]=='[')
                   c.push(s[i]);
                   else if(s[i]==')'||s[i]=='}'||s[i]==']')
                        {
                        ch=c.pop();
                        switch(s[i])
                        {
                                  case ')':
                                       if(ch=='(')
                                       {i++;
                                       continue;}
                                       else{
                                             flag=0;
                                             break;
                                             } 
                                   case '}':
                                       if(ch=='{')
                                       {i++;
                                       continue;}
                                       else{
                                             flag=0;
                                             break;
                                             }
                                    case ']':
                                       if(ch=='[')
                                       {i++;
                                       continue;}
                                       else{
                                             flag=0;
                                             break;
                                             }
                        }
                        }
         i++;
         }
         if(c.top!=-1)
                      flag=0;
         if(flag==0)
                    cout<<"\nThe expression is not balanced ";
         else
             cout<<"\nThe expression is balanced ";
             
}
int main()
{
    braces b;
    char s[20];
    cout<<"Enter the expression :";
    cin>>s;
    int l=strlen(s);
    cout<<"\n"<<l<<endl;
    b.check(s,l);
    getch();
}                  
          
