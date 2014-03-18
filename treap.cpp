#include<iostream>
using namespace std;

struct tnode
{
    int data;
    char ch;
    tnode *lchild,*rchild;
};
void rotateright(tnode *&k1)
{
    tnode *k2=k1->rchild;
    k1->rchild=k2->lchild;
    k2->lchild=k1;
    k1=k2;
}
void rotateleft(tnode *&k1)
{
    tnode *k2=k1->lchild;
    k1->lchild=k2->rchild;
    k2->rchild=k1;
    k1=k2;
}

tnode *add(tnode *l,int k,char x)
{
    if(l==NULL)
    {
        l=new tnode;
        l->data=k;
        l->ch=x;
        l->lchild=l->rchild=NULL;
    }
    else if(l->ch>x)
    {
        l->lchild=add(l->lchild,k,x);
        if(l->data>l->lchild->data)
            rotateleft(l);
    }
    else if(l->ch<x)
    {
        l->rchild=add(l->rchild,k,x);
        if(l->data>l->rchild->data)
            rotateright(l);
    }
    return(l);
}
void display(tnode *l,int n)
{
    if(l!=NULL)
    {
        if(n==1)cout<<l->ch<<","<<l->data<<endl;
        display(l->lchild,n);
        if(n==2)cout<<l->ch<<","<<l->data<<endl;
        display(l->rchild,n);
        if(n==3)cout<<l->ch<<","<<l->data<<endl;
    }
}
int main()
{
    tnode *root=NULL;
    cout<<"Start entering the data in the treap(0 to exit)[character:integer format]->\n";
    int n;char s;
    while(1)
    {
        cin>>s>>n;
        if(n==0)
            break;
        root=add(root,n,s);
    }
    while(n!=4)
    {
        cout<<"\nEnter your traversal choice.........";
        cout<<"\n1.Preorder\n2.Inorder\n3.Postorder\n4.exit";
        cin>>n;
        display(root,n);
    }
}
