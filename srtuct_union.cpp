#include<iostream>
using namespace std;
#include<conio.h>

struct student
{
       int roll;
       char name[8];
       int flag;
       union
       {
            int hno;
            char cellno[10];
       }ad;
       int marks;
};
int main()
{
    struct student s;
    s.roll=30;
    cout<<s.roll<<endl;
    cout<<"\nEnter 0 for house number OR 1 for cell number ";
    cin>>s.flag;
    cout<<"\nEnter the nuumber according to choice ";
    if(s.flag==0)
               cin>>s.ad.hno;
    else
               cin>>s.ad.cellno;
    s.marks=96;
    cout<<"\nUr marks in EG is "<<s.marks;
    getch();
} 
            
