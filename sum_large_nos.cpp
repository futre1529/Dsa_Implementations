//sum of very large nos.
#include<iostream>
using namespace std;
#include<conio.h>

struct node
{
       char data;
       node *next;
};

node* add(node *l,char k)
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
node *sum(node *l1,node *l2)
{
     node *l3=NULL,*t;
     int sum=0,carry=0,n1,n2;
     while(l1!=NULL&&l2!=NULL)
     {
                              n1=int(l1->data-'0');
                              n2=int(l2->data-'0');
                              sum=n1+n2+carry;
                              carry=sum/10;
                              sum%=10;
                              t=new node;
                              t->data=sum+'0';
                              t->next=l3;
                              l3=t;
                              l1=l1->next;
                              l2=l2->next;
     }
     if(l1==NULL)
     {
                 while(l2!=NULL)
                 {
                                n1=int(l2->data-'0');
                                sum=n1+carry;
                                carry=sum/10;
                                sum%=10;
                                t=new node;
                                t->data=sum+'0';
                                t->next=l3;
                                l3=t;
                                l2=l2->next;
                 }
     }
     else 
     if(l2==NULL)
     {
                   while(l1!=NULL)
                 {
                                n1=int(l1->data-'0');
                                sum=n1+carry;
                                carry=sum/10;
                                sum%=10;
                                t=new node;
                                t->data=sum+'0';
                                t->next=l3;
                                l3=t;
                                l1=l1->next;
                 }
     }
     if(carry>0)
     {
                t=new node;
                t->data=carry+'0';
                t->next=l3;
                l3=t;
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
                   cout<<l->data;
                   l=l->next;
     }
     }
}

int main()
{
    node *l1=NULL,*l2=NULL;char k;
    cout<<"\nEnter the large number(press dot after entering the number) :";
    while(1)
    {
            cin.get(k);
            if(k=='\n')
                      break;
            l1=add(l1,k);
    }
    cout<<"\nEnter the large number(press dot after entering the number) :";
    while(1)
    {
            cin.get(k);
            if(k=='\n')
                      break;
            l2=add(l2,k);
    }
    cout<<"\nThe sum of the nos. is :";
    node *l3=NULL;
    l3=sum(l1,l2);
    display(l3);
    getch();
}
