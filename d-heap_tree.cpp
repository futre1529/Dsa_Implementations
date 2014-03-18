#include<iostream>
using namespace std;

struct node
{
    int data;
    node *parent;
    node **child;
};

void create(node *ar[],int &size,int d)
{
    node *a,*b;
    int n,i=0,j=1,k,t;
    cout<<"Start entering the data in the tree(0 to exit) :";
    while(1)
    {
        cin>>n;
        if(n==0)
            break;
        l1:if(j!=d+1)
        {
            k=d*i+j;
            cout<<k<<" "<<i<<"$";
            ar[k]=new node;
            ar[k]->data=n;
            ar[k]->parent=ar[i];
            ar[i]->child[j-1]=ar[k];
            int a=k;
            k=(k-1)/d;
            if(n<ar[k]->data)
            {
                while(n<ar[k]->data&&k>=0)
                {
                    ar[a]->data=ar[k]->data;
                    ar[k]->data=n;
                    a=(a-1)/d;
                    k=(k-1)/d;
                }
            }
            j++;
        }
        else
        {
            i=i+1;
            ar[i]->child=new node*[d];
            for(j=0;j<d;j++)
                {ar[i]->child[j]=NULL;ar[i]->parent=NULL;}
            j=1;
            goto l1;
        }
    }
    cout<<i<<"#"<<j<<"#";
    size=d*i+j;
    cout<<size<<"@";
}
void del(node *ar[],int &j,int d)
{
    if(j>=0)
    {
        int i=0,k=0,l,p=0,b;
        cout<<ar[0]->data<<" ";
        ar[0]->data=ar[j]->data;
        int m=ar[0]->data;
        if(2*i+1<j)
        {
            l=ar[2*i+1]->data;b=2;
            for(k=2*i+b;b<=d&&k<=j;b++)
                if(ar[k]->data<l)l=ar[k]->data;
        }
        else l=9999;
        while(ar[i]->data>l)
        {
            b=1;
            for(k=2*i+b;b<=d&&k<=j;k++)
                if(ar[k]->data==l)i=k;
            ar[p]->data=ar[i]->data;
            ar[i]->data=m;
            if(2*i+1<j)
            {
                l=ar[2*i+1]->data;b=2;
                for(k=2*i+b;b<=d&&k<=j;k++)
                    if(ar[k]->data<l)l=ar[k]->data;
            }
            else l=9999;
            p=i;
        }
        del(ar,--j,d);
    }
}
int main()
{
    node *ar[20];
    ar[0]=new node;
    int size,i,d;
    cout<<"\nEnter the d value :";cin>>d;
    cout<<"Eneter the first value :";
    cin>>ar[0]->data;
    ar[0]->child=new node*[d];ar[0]->parent=NULL;
    for(i=0;i<d;i++)ar[0]->child[i]=NULL;
    size=20;
    create(ar,size,d);
    cout<<"\nArray check :";
    for(i=0;i<size;i++)cout<<ar[i]->data<<" ";
    cout<<"\n"<<ar[0]->child[1]->data<<"\n";
    cout<<"\nDisplaying the sorted heap :";
    size-=1;
    del(ar,size,d);
}
