//a number of "grouped elements(struct)" piled up in a stack 
#include<iostream>
using namespace std;
#include<conio.h>
#include<cstring>

class items
{
      public:
             int top;
             struct pack
             {
                   int size;
                   int *ar;
             }b,c[12];
             pack a[20];
             void push(pack p);
             pack pop();
             void insertdata();
};
void items::push(pack p)
{
     a[++top]=p;
}
items::pack items::pop()
{
            return(a[top--]);
}
void items::insertdata()
{
     items it;
     int l,i,j;
     it.top=-1;
     cout<<"\nEnter the no. total of pack :";
     cin>>l;
     for(i=0;i<l;i++)
     {
                     cout<<"\nEnter the no. of elements in the pack :";cin>>it.c[i].size;
                     it.c[i].ar=new int[it.c[i].size];
                     cout<<"\nNow start entering the elements :";
                     for(j=0;j<(it.c[i].size);j++)
                                                     cin>>it.c[i].ar[j];
                     it.push(it.c[i]);
     }
     cout<<"\nTesting Popping.........."<<endl;
     it.b=it.pop();
     for(i=0;i<it.b.size;i++)
                             cout<<it.b.ar[i]<<"  ";
}
int main()
{
    items m;
    m.insertdata();
    getch();
}
