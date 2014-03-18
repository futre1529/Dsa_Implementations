#include<iostream>
using namespace std;

struct anode
{
    int height;
    anode *lchild;
    anode *rchild;
    int data;
};
int max(int a,int b)
{
    return(a>b?a:b);
}
int nheight(anode *l)
{
 	 if(l==NULL)
	 			return(-1);
	 else
		 return(1+max(nheight(l->lchild),nheight(l->rchild)));
}
void rchildsinglerot(anode *&k1)
{
    anode *k2=k1->rchild;
    k1->rchild=k2->lchild;
    k2->lchild=k1;
    k1->height=nheight(k1);
    k2->height=nheight(k2);
    k1=k2;
}
void lchildsinglerot(anode *&k1)
{
    anode *k2=k1->lchild;
    k1->lchild=k2->rchild;
    k2->rchild=k1;
    k1->height=nheight(k1);
    k2->height=nheight(k2);
    k1=k2;
}
void rchilddoublerot(anode *&k3)
{
    anode *k1=k3->rchild;
    anode *k2=k2->lchild;
    k3->rchild=k2->lchild;
    k1->lchild=k2->rchild;
    k2->rchild=k1;
    k2->lchild=k3;
    k3=k2;
}
void lchilddoublerot(anode * &k3)
{
    anode *k1=k3->lchild;
    anode *k2=k2->rchild;
    k3->lchild=k2->rchild;
    k1->rchild=k2->lchild;
    k2->lchild=k1;
    k2->rchild=k3;
    k3=k2;
}

void insert(anode *&l,int k)
{
    if(l==NULL)
    {
        l=new anode;
        l->height=0;
        l->data=k;
        l->lchild=l->rchild=NULL;
    }
    else if(k<l->data)
    {
        insert(l->lchild,k);
        if(nheight(l->lchild)-nheight(l->rchild)==2)
        if(k<l->lchild->data)
            lchildsinglerot(l);
        else
            lchilddoublerot(l);
    }
    else if(k>l->data)
    {
        insert(l->rchild,k);
        if(nheight(l->lchild)-nheight(l->rchild)==2)
        if(k>l->rchild->data)
            rchildsinglerot(l);
        else
            rchilddoublerot(l);
    }
    else ;
    l->height=nheight(l);
}

void display(anode *l)
{
    if(l!=NULL)
    {
        display(l->lchild);
        cout<<l->data<<" ";
        display(l->rchild);
    }
}
int main()
{
    anode *root=NULL;int val;
    cout<<"\nStart entering the data in the AVL tree :(enter -1 to exit)";
    while(1)
    {
        cin>>val;
        if(val==-1)
            break;
        else
            insert(root,val);
    }
    cout<<"\nDispalying the tree.....\n";
    display(root);
}
