//union and intersection of two lists
#include<iostream>
using namespace std;
#include<conio.h>

struct node
{
       int data;
       node *next;
};

node* add(node *l,int k)
{
     if(l==NULL)
     {
                node *t=new node;
                t->data=k;
                t->next=NULL;
                l=t;
                return(l);
     }
     else
     {   
         node *t=new node;
         t->data=k;
         t->next=l;
         l=t;
         return(l);
     }
}
node* uni(node *l1,node *l2)
{
     node *l3,*l4,*t;
     l3=l1;
     int flag=0;
     while(l2!=NULL)
     {
                   l4=l1;
                   flag=0;
                   while(l4!=NULL)
                   {
                                  if(l4->data==l2->data)
                                  {
                                  flag=1;
                                  break;
                                  }
                                  l4=l4->next;
                   }
                   if(flag==0)
                   {
                              t=new node;
                              t->data=l2->data;
                              t->next=l3;
                              l3=t;
                   }
                   l2=l2->next;
     }
     return(l3);
}
node *intersection(node *l1,node *l2)
{
     node *l3=NULL,*l4,*t;
     int flag;
     while(l1!=NULL)
     {
                    l4=l2;flag=0;
                    while(l4!=NULL)
                    {
                                   if(l4->data==l1->data)
                                   {
                                                         flag=1;
                                                         break;
                                   }
                                   else
                                       l4=l4->next;
                    }
                    if(flag==1)
                    {
                              t=new node;
                              t->data=l1->data;
                              t->next=l3;
                              l3=t;
                    }
                    l1=l1->next;
     }
     return(l3);
}             
void display(node *l)
{
     if(l==NULL)
                cout<<"\nList empty ";
     else
     {
     cout<<"\nDisplaying the contents :";
     while(l!=NULL)
     {
                   cout<<l->data<<"  ";
                   l=l->next;
     }
     }
}
int main()
{
    node *l1=NULL,*l2=NULL,*l3,*l4;
    int op,k;
    cout<<"\nEnter the values in list 1 :(enter 0 to exit) ";
    while(1)
    {
         cin>>k;
         if(k==0)
                 break;
         else
             l1=add(l1,k);
    }
    display(l1);
    cout<<"\nEnter the values in list 2 :(enter 0 to exit) ";
    while(1)
    {
         cin>>k;
         if(k==0)
                 break;
         else
             l2=add(l2,k);
    }
    cout<<"\nThe intersection of 2 lists is :";
    l3=intersection(l1,l2);
    display(l3);
    cout<<"\nThe union of 2 lists is :";
    l4=uni(l1,l2);
    display(l4);
    getch();
}
