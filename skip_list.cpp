#include<iostream>
using namespace std;
#include<math.h>

struct node
{
    node *top;
    node *next;
};

struct snode
{
    int data;
    snode *link;
    node *up;
};

void createlist(snode *&l,int k)
{
    snode *t=l,*temp=new snode;
    temp->data=k;
    temp->link=NULL;
    temp->up=NULL;
    if(t==NULL)
    {
        l=temp;
        return;
    }
    if(k>t->data&&t->link==NULL)
        t->link=temp;
    else if(k<t->data&&t->link==NULL)
    {
        temp->link=t;
        l=temp;
    }
    else
    {
        while(t->link->data<k)
            t=t->link;
        temp->link=t->link;
        t->link=temp;
    }
}
void display(snode *l)
{
    if(l!=NULL)
    {
        cout<<l->data<<" ";
        display(l->link);
    }
}
int countnodes(snode *l)
{
    if(l!=NULL)
        return(1+countnodes(l->link));
    else
        return(0);
}
void sklist(snode *l)
{
    snode *t1,*t2;
    int i=2,count;
    int len=countnodes(l);
    int j=0,val=1,k=0;
    while(val<=len)
    {
        j++;
        val=pow(i,j);
    }
    --j;
    cout<<"\nMaximum power of 2 is "<<j;
    while(k<j)
    {
        t1=t2=l;
        for(count=0;count<i;count++)
            t2=t2->link;
        while(t2!=NULL)
        {
            if(t1->up==NULL)
            {
                t1->up=new node;
                t1->up->top=NULL;
                t1->up->next=NULL;
            }
            else
            {
                while(t1->up->top!=NULL)
                    t1->up=t1->up->top;
                t1->up->top=new node;
                t1->up->top->top=NULL;
                t1->up->top->next=NULL;
                t1->up=t1->up->top;
            }
            if(t2->up==NULL)
            {
                t2->up=new node;
                t2->up->top=NULL;
                t2->up->next=NULL;
            }
            else
            {
                while(t2->up->top!=NULL)
                    t2->up=t2->up->top;
                t2->up->top=new node;
                t2->up->top->top=NULL;
                t2->up->top->next=NULL;
                t2->up=t2->up->top;
            }
            t1->up->next=t2->up;
            for(count=0;count<i&&t2!=NULL;count++)
            {
                t1=t1->link;
                t2=t2->link;
            }
        }
        i*=2;
        k++;
    }
}
int main()
{
    snode *root=NULL;
    int num;
    cout<<"\nEnter the values(enter 0 to exit) :";
    while(1)
    {
        cin>>num;
        if(num==0)
            break;
        createlist(root,num);
    }
    cout<<"\nList ban gaya hai.\n";
    cout<<"\nAb apke dwara banaya list dekhiye.\n";
    display(root);
    cout<<"\nApne total "<<countnodes(root)<<" node banaye hai.";
    sklist(root);
}
