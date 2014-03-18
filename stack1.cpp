//basic
#include<iostream>
using namespace std;
#include<conio.h>

class stack
{
      public:
             int size;
             int *elements;
             int top;
             void push(int);
             int pop();
};
int stack::pop()
{
   if(top!=-1)
              return(elements[top--]);
   else
       return(-1);
}
void stack::push(int x)
{
     if(top!=size-1)
                    elements[++top]=x; 
     else cout<<"\n Stack full ";
}
int main()
{
     stack s;
     s.size=10;
     s.top=-1;
     s.elements=new int[s.size]; 
     for(int i=0;i<9;i++)
                     s.push(i);
     cout<<s.pop()<<endl;
     cout<<s.pop()<<endl;
     /*cout<<s.pop()<<endl;*/
     getch();
}
