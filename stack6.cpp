//basic prog is here n u can further improve it by inserting menu 
//stack of student information
#include<iostream>
using namespace std;
#include<conio.h>
#include<cstring>

class stack_student
{
      public:
             int top;
             struct student
             {
                    int roll;
                    char name[20];
                    union
                    {
                         int hno;
                         char cell[10];
                    }ad;
                    int flag;
             }st[20],a;
             student s[15];
             void push(student);
             student pop();
};
void stack_student::push(student temp)
{
                s[++top]=temp;
}
stack_student::student stack_student::pop()
{
        return(s[top--]);
}
int main()
{
     stack_student stk;
     stk.top=-1;
     int n,i;
     cout<<"\nEnter the no. of students whose data u want to enter :";
     cin>>n;
     cout<<"\nStart entering the data :"<<endl;
     for(i=0;i<n;i++)
     {
                     stk.st[i].flag=0;
                     cout<<"Name :";cin>>stk.st[i].name;
                     cout<<"Roll :";cin>>stk.st[i].roll;
                     cout<<"Enter 0 for house no. and 1 for cell no. ";
                     cin>>stk.st[i].flag;
                     if(stk.st[i].flag==0)
                                         {cout<<"\nHouse no. :";cin>>stk.st[i].ad.hno;}
                     if(stk.st[i].flag==1)
                                         {cout<<"\nCell no. :";cin>>stk.st[i].ad.cell;}
                     stk.push(stk.st[i]);
     }
     cout<<endl;
     stk.a=stk.pop();
     cout<<"popped out namne :"<<stk.a.name;
     getch();
}
     
     
                
                         
             
