#include<iostream>
using namespace std;
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node
{
       int data;
       node *link;
};
node *add(node *t,int val);
node *show(node *first,node *last,int x);

node *add(node *temp,int val)
{
     node *t;
     t=new node;
     t->data=val;
     t->link=NULL;
     if(temp==NULL)
                   temp=t;
     else
     {
         temp->link=t;
         temp=t;
     }
     return(temp);
}        

main()
{
       int a,b,i,j;
       cout<<"Enter the no. of elements in list 1 :";
       cin>>a;
       cout<<"Enter the no. of elements in list 2 :";
       cin>>b;
       node *f1,*l1;       
       int val,v;
       node *temp;                  
                       cout<<"\nEnter the values of list "<<1<<" ";
                       cout<<"\nEnter the value at 1 ";
                       cin>>val;
                               f1->data=val;
                               f1->link=NULL;
                               temp=f1;
                       for(j=1;j<a;j++)
                       {
                                          cout<<"\nEnter the value at "<<j+1<<" ";
                                          cin>>val;
                                          temp=add(temp,val);
                       }
                       l1=temp;
       node *t;
       node *f2,*l2;
                       cout<<"\nEnter the values of list "<<2<<" ";
                       cout<<"\nEnter the value at 1 ";
                       cin>>v;
                               f2->data=v;
                               f2->link=NULL;
                               t=f2;
                       for(i=1;i<b;i++)
                       {
                                          cout<<"\nEnter the value at "<<i+1<<" ";
                                          cin>>v;
                                          t=add(t,v);
                       }
                       l2=t;
                       cout<<"\n "<<l2->data;
}                               
                                          
                                          
                       
