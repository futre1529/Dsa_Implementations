#include<iostream>
using namespace std;
#include<conio.h>

class stack1
{
      public:
             int top1;
             class stack2
             {
                   public:
                   int top2;
                   int ar[20];
                   void push(int);
                   int pop();
             }s2;
             stack2 a[20],b[20];
             void pushi(stack2);
             stack2 popi();
             void insert();
};
void stack1::pushi(stack2 s)
{
     b[++top1]=s;
}
stack1::stack2 stack1::popi()
{
     return(b[top1--]);
} 
 
int stack1::stack2::pop()
{
                return(ar[top2--]);
}
void stack1::stack2::push(int data)
{
                ar[++top2]=data;
}
void stack1::insert()
{
     stack1 s1;
     s1.top1=-1;
     int l1,l2,i,j,n;
     cout<<"\nEnter the no. of groups :";
     cin>>l1;
     for(i=0;i<l1;i++)
     {
                      cout<<"\nEnter the no. of elements in group "<<i+1<<" : ";
                      cin>>l2;
                      s1.a[i].top2=-1;
                      for(j=0;j<l2;j++)
                      {
                                       cout<<"value "<<j+1<<" :";cin>>n;
                                       s1.a[i].push(n);
                      }
                      s1.pushi(s1.a[i]);
     }
     cout<<"\nTesting popping............."<<endl;
     s1.s2=s1.popi();
     while(s1.s2.top2!=-1)
                      cout<<s1.s2.pop()<<" ";
}
int main()
{
    stack1 st;
    st.insert();
    getch();
}              
                

                   
                    
