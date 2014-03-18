//queue ADT implementation using 2 stacks
#include<iostream>
using namespace std;
#include<conio.h>

class stack
{
      public:
             int top;
             int ar[20];
             void push(int);
             int pop();
             void evaluate();
             stack()
             {
                    top=-1;
             }
};

void stack::push(int x)
{
    ar[++top]=x;
}
int stack::pop()
{
    return(ar[top--]);
}
void stack::evaluate()
{
     stack s1,s2;
     cout<<"\nStarting the operations :";
     int data,op;
     while(1)
     {
             cout<<"\nPress 1 for entering data\nPress 2 for removing data\nPress 3 for exiting :\n";
             cin>>op;
             switch(op)
             {
                       case 1:
                            cout<<"\nData :";cin>>data;
                            if(s1.top==-1)
                                          s1.push(data);
                            else
                            {
                                while(s1.top!=-1)
                                                 s2.push(s1.pop());
                                s1.push(data);
                                while(s2.top!=-1)
                                                 s1.push(s2.pop());
                            }
                            break;
                       case 2:
                            cout<<"\nThe member moving out is :"<<s1.pop();
                            break;
                       case 3:
                            exit(0);
             }
     }
}
int main()
{
    stack s;
    cout<<"\nImplementatio of 2 stacks as queue. "<<endl;
    s.evaluate();
    getch();
} 
                                                 
                                
