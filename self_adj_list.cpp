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

node *adjust(node *l,int k)
{
     node *t=l,*temp;
     if(t==NULL)
                cout<<"\nList empty ";
     else if(t->next==NULL)
          cout<<"\nNo change ";
     else
     {
         while(t->next!=NULL)
         {
                       if(t->next->data==k)
                       {
                                           temp=t->next;
                                           t->next=t->next->next;
                                           temp->next=l;
                                           l=temp;
                                           return(l);
                       }
                       else
                           t=t->next;
         }
     }
     return(l);
}

void display(node *l)
{
     if(l==NULL)
     cout<<"empty\a"; 
     while(l!=NULL)
     {
                   cout<<l->data<<"  ";
                   l=l->next;
     }
}

int main()
{
    node *l=NULL;
    int k,op;
    cout<<"\nEnter the elements(enter 0 to exit) ";
    while(1)
    {
            cin>>k;
            if(k==0)
                    break;
            else
                l=add(l,k);
    }
    display(l);
    while(1)
    {
            cout<<"\n1.Add at front\n2.exit ";
            cout<<"\nyour choice :";cin>>op;
            switch(op)
            {
                       case 1:
                            cout<<"Choose your element :";cin>>k; 
                            l=adjust(l,k);
                            display(l);
                            break;
                       case 2:
                            exit(0);
            }
    }
    getch();
}
