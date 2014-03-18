#include<iostream>
using namespace std;
#include<process.h>

struct node
{
    int k1;
    int k2;
    node *left,*right,*middle;
};
void swap(int &x,int &y)
{
    int t;
    t=x;
    x=y;
    y=t;
}
node *create(node *l,int k)
{
    if(l==NULL)
    {
        l=new node;
        l->left=l->right=l->middle=NULL;
        l->k1=k;l->k2=-1;
    }
    else if(l->k2==-1)
    {
        if(l->k1>k)
        {
            l->k2=l->k1;
            l->k1=k;
        }
        else
            l->k2=k;
    }
    else if(k<l->k1)
        l->left=create(l->left,k);
    else if(k>l->k2)
        l->right=create(l->right,k);
    else if(k>l->k1&&k<l->k2)
        l->middle=create(l->middle,k);
    else ;
    return(l);
}
void display(node *l)
{
    if(l!=NULL)
    {
        cout<<l->k1;
        if(l->k2!=-1)
            cout<<"-"<<l->k2;
        cout<<"  ";
        display(l->left);
        display(l->middle);
        display(l->right);
    }
}
void search(node *l,int k)
{
    if(l!=NULL)
    {
        if(l->k1==k||l->k2==k)
            {cout<<"\nObject found ";return;}
        search(l->left,k);
        search(l->middle,k);
        search(l->right,k);
    }
}
void del(node *b,int k)
{
    node *temp;
    temp=new node;
    if(b->k1==k)
    {
         if(b->left==NULL&&b->middle==NULL&&b->right==NULL)
         {

             b->k1=b->k2;
             b->k2=-1;
         }
         else if(b->left==NULL&&b->middle!=NULL)
         {
             temp=b->middle;
             while(temp->left!=NULL)
             temp=temp->left;
             b->k1=temp->k1;
             temp->k1=-1;
         }
         else  if(b->left!=NULL)
         {
             temp=b->left;
             while(temp->right!=NULL)
             temp=temp->right;
             b->k1=temp->k2;
             temp->k2=-1;
         }
    }
    else if(b->k2==k)
    {
        if(b->right==NULL)
        b->k2=-1;
        else if(b->right!=NULL||b->middle==NULL)
        {
            temp=b->right;
            while(temp->left!=NULL)
            temp=temp->left;
            b->k2=temp->k1;
            temp->k1=-1;
        }
    }
    if(b->left!=NULL)
        del(b->left,k);
    if(b->middle!=NULL)
        del(b->middle,k);
    if(b->right!=NULL)
        del(b->right,k);
}
int main()
{
    node *root=new node;
    int num;
    cout<<"\nEnter the values(0 to exit) :";
    cin>>num;
    root->k1=num;root->k2=-1;
    root->left=root->right=root->middle=NULL;
    while(1)
    {
        cin>>num;
        if(num==0)
            break;
        root=create(root,num);
    }
    cout<<"\nDisplaying the 2-3 tree :";
    display(root);
    cout<<"\nEnter the element to search :";
    cin>>num;
    del(root,num);
    display(root);
}
