#include<iostream>
using namespace std;

const int d=2;
struct bnode
{
    int index;
    int key[4];
    bnode *child[5];
};

void add(bnode *&p,int data,int &flag)
{
    bnode *l=p;
    int i,j;
    if(l==NULL&&flag==0)
    {
        l=new bnode;
        l->index=0;
        for(i=0;i<2*d;i++)
            {l->child[i]=NULL;l->key[i]=-1;}
        l->child[i]=NULL;
        l->key[0]=data;
        p=l;
        flag=1;
        return;
    }
    else if(l==NULL)return;
    for(i=0;i<=l->index;i++)
        {if(l->key[i]==-1||data<l->key[i])break;}
    add(l->child[i],data,flag);
    if(l->index!=2*d-1)
    {
        cout<<l->index<<"#";
        l->index+=1;
        l->key[l->index]=data;
        //sort(l,index);
    }
    else
    {
        cout<<"yipee!!entered else part.....:D";
        int ar[2*d+1];
        for(i=0;i<2*d;i++)
        ar[i]=l->key[i];
        ar[i]=data;
        //sortAr(ar);
        bnode *temp=new bnode;
        temp->index=0;
        temp->key[0]=ar[d];
        temp->child[0]=l;
        bnode *t=temp->child[temp->index+1]=new bnode;
        for(i=d+1,j=0;i<2*d+1;i++,j++)
        {
            t->key[j]=ar[i];
        }t->index=j-1;
        for(i=j;i<2*d;i++)t->key[i]=-1;
        for(i=0;i<=2*d;i++)
            t->child[i]=NULL;
        for(i=0;i<d;i++)
        {
            l->key[i]=ar[i];
        }l->index=i-1;
        for(;i<2*d;i++)l->key[i]=-1;
        p=temp;
    }
}
void display(bnode *l)
{
    int i;
    if(l!=NULL)
    {
        for(i=0;i<=l->index+1;i++)
        {if(l->key[i]!=-1)
        cout<<l->key[i]<<","<<l->index<<" ";
        display(l->child[i]);}
    }
}
int main()
{
    bnode *root=NULL;
    int n,flag=0;
    cout<<"\nEnter the data in the tree :\n";
    while(1)
    {
        cin>>n;
        if(n==0)break;
        add(root,n,flag);
    }
    cout<<"\n\n";
    cout<<root->child[0]->key[0];
    cout<<root->child[0]->key[1];
    cout<<root->key[0];
    cout<<root->child[1]->key[0];
    cout<<root->child[1]->key[3];
    //cout<<"\nDisplaying the formed tree :";
    //display(root);
}
