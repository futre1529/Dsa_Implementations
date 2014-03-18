//reversing a list using recursion.
//printing list in ascending as well as descending order in same fn.(sorted list)
#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *reverse(node *l,node *&t,int &flag)
{
    if(l->next!=NULL)
        reverse(l->next,t,flag)->next=l;
    if(flag==0)
        t=l;
    flag=1;
    return(l);
}
void idisplay(node *l,int &flag)
{
    if(l!=NULL)
    {
        cout<<l->data<<" ";
        idisplay(l->next,flag);
        if(flag==0)
            cout<<"\n";
        flag=1;
        cout<<l->data<<" ";
    }
}

node* add(node *l,int k)
{
     if(l==NULL)
     {
                cout<<"\nFirst node created";
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
void display(node *l)
{
    if(l!=NULL)
    {
        cout<<l->data<<" ";
        display(l->next);
    }
}
int main()
{
    node *l=NULL;
    int num,flag=0;
    cout<<"\nEnter the data(0 to exit) :";
    while(1)
    {
        cin>>num;
        if(num==0)
            break;
        l=add(l,num);
    }
    cout<<"\nThe list is :";
    display(l);
    cout<<"\nThe ascending descending in same fn. is shoen below :\n";
    idisplay(l,flag);
    cout<<endl;
    flag=0;
    node *t=NULL;
    l=reverse(l,t,flag);
    l->next=NULL;
    cout<<"\nThe reversed list is :";
    display(t);
}
