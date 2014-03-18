//addition of 2 polynoials
#include<iostream>
using namespace std;
#include<conio.h>

struct node
{
       int coef;
       int exp;
       node *next;
};

node* add(node *l,int k,int e)
{
     if(l==NULL)
     {
                cout<<"\nFirst node created";
                node *t=new node;
                t->coef=k;t->exp=e;
                t->next=NULL;
                l=t;
                return(l);
     }
     else
     {   
         node *t=new node;
         t->coef=k;t->exp=e;
         t->next=l;
         l=t;
         return(l);
     }
}

void display(node *l)
{
     if(l==NULL)
     cout<<"empty\a"; 
     while(l!=NULL)
     {
                   cout<<l->coef<<"x("<<l->exp<<")"<<" + ";
                   l=l->next;
     }
     cout<<"\b\b\b";
}

node* addlist(node *l1,node *l2)
{
      node *l3=NULL,*l4;
      while(l1!=NULL&&l2!=NULL)
      {
                               if(l1->exp==l2->exp)
                               {
                                                   l4=new node;
                                                   l4->coef=l1->coef+l2->coef;
                                                   l4->exp=l1->exp;
                                                   l4->next=l3;
                                                   l3=l4;
                                                   l1=l1->next;l2=l2->next;
                               }
                               else if(l1->exp>l2->exp)
                               {
                                     l4=new node;
                                     l4->coef=l1->coef;
                                     l4->exp=l1->exp;
                                     l4->next=l3;
                                     l3=l4;
                                    l1=l1->next;
                               }
                               else if(l2->exp>l1->exp)
                               {
                                     l4=new node;
                                     l4->coef=l2->coef;
                                     l4->exp=l2->exp;
                                     l4->next=l3;
                                     l3=l4;
                                     l2=l2->next;
                               }
      }
      if(l1!=NULL)
      {
                  while(l1!=NULL)
                  {
                                     l4=new node;
                                     l4->coef=l1->coef;
                                     l4->exp=l1->exp;
                                     l4->next=l3;
                                     l3=l4;
                                     l1=l1->next;
                  }
      }
      else
      {
          while(l2!=NULL)
                  {
                                     l4=new node;
                                     l4->coef=l2->coef;
                                     l4->exp=l2->exp;
                                     l4->next=l3;
                                     l3=l4;
                                     l2=l2->next;
                  }
      }
      return(l3);
}
                                              
int main()
{
     node *l1=NULL,*l2=NULL,*l3;
     int op,k,opt,flag=0;
     while(1)
     {
     cout<<"\n1.Insert values in the linked list\n2.Add the 2 lists :"<<endl;
     cin>>op;
     switch(op)
     {
               case 1:
                    cout<<"1.list 1\n2.list 2 :";cin>>opt;
                    switch(opt)
                    {
                    case 1:
                    cout<<"\nEnter the coeff. n exponent of d polynomial :";cin>>k;cin>>op;
                    l1=add(l1,k,op);
                    break;
                    case 2:
                    cout<<"\nEnter the coeff. n exponent of d polynomial :";cin>>k;cin>>op;
                    l2=add(l2,k,op);
                    break;
                    }
                    break;
               case 2:
                    l3=addlist(l1,l2);
                    cout<<"\nDisplaying the lists :"<<endl;
                    display(l1);cout<<" + ";display(l2);cout<<" = ";display(l3);cout<<"  ";
                    flag=1;
                    break;
              default:cout<<"\nPlease enter a valid choice ";break;
     }
     if(flag==1)
                break;
     }
     getch();
}
