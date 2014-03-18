#include<iostream>
using namespace std;

struct bnode
{
    int data;
    bnode *lchild;
    bnode *rchild;
    bnode *par;
};
void swap(int &a,int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void create(int ar[],int j,int k)
{
    int i=j;
    ar[i]=k;
    j=(j-1)/2;
    if(k<ar[j])
    {
        while(k<ar[j]&&j>=0)
        {
            ar[i]=ar[j];
            ar[j]=k;
            i=(i-1)/2;
            j=(j-1)/2;
        }
    }
}
bnode *listcreate(bnode *l,int ar[],int i,int j)
{
    if(l==NULL)
    {
        l=new bnode;
        l->data=ar[i];
        l->lchild=l->rchild=NULL;l->par=NULL;
    }
    if((2*i)+1<=j)
        {l->lchild=listcreate(l->lchild,ar,(2*i)+1,j);l->lchild->par=l;}
    if((2*i)+2<=j)
        {l->rchild=listcreate(l->rchild,ar,(2*i)+2,j);l->rchild->par=l;}
    return(l);
}
void disp(bnode *l)
{
    if(l!=NULL)
    {
        disp(l->lchild);
        cout<<l->data<<" ";
        disp(l->rchild);
    }
}
//..........................................
class queue
{
      public:
      int front,rear;
      bnode *elements[20];
      void enqueue(bnode *b);
      bnode *dequeue();
      queue(){front=rear=-1;}
};
void queue::enqueue(bnode *x)
{
         rear=(rear+1)%20;
         elements[rear]=x;
         if(front==-1)
                      front=0;
}
bnode *queue::dequeue()
{
    bnode *t=new bnode;
    t->data=-1;
    t->lchild=t->rchild=NULL;
    if(front==-1)
                 return(t);
    else
    {
        if(front==rear)
        {
                       t=elements[front];
                       front=-1;rear=-1;
        }
        else
        {
            t=elements[front];
            front=(front+1)%20;
        }
    }
    return(t);
}

void print(queue q)
{
     bnode *t=new bnode,*temp;
     t->data=-1;
     t->lchild=t->rchild=NULL;
     temp=q.dequeue();
     cout<<temp->data<<" ";
     while(temp->data>0)
     {
     if(temp->lchild!=NULL)
                        q.enqueue(temp->lchild);
     if(temp->rchild!=NULL)
                        q.enqueue(temp->rchild);
     temp=q.dequeue();
     if(temp->data>0)
                     cout<<temp->data<<" ";
     }
     if(q.front==-1)
                   return;
     q.enqueue(t);
     cout<<endl;
     print(q);
}
//...........................................
void del(int ar[],int &j)
{
    if(j>=0)
    {
        int i=0,l,k=0;
        cout<<ar[0]<<" ";
        ar[0]=ar[j];
        int m=ar[0];
        if(2*i+2<=j)
            l=min(ar[2*i+1],ar[2*i+2]);
        else if(2*i+1<=j)
            l=ar[2*i+1];
        else
            l=999;
        while(ar[i]>l)
        {
            if(l==ar[2*i+1])i=2*i+1;
            else i=2*i+2;
            ar[k]=ar[i];
            ar[i]=m;
            if(2*i+2<=j)
                l=min(ar[2*i+1],ar[2*i+2]);
            else if(2*i+1<=j)
                l=ar[2*i+1];
            else
                l=999;
            k=i;
        }
        del(ar,--j);
    }
}
//.........................................................
void search(bnode *l,bnode *&t,int x)
{
    if(l!=NULL)
    {
        search(l->lchild,t,x);
        if(l->data==x)
            t=l;
        search(l->rchild,t,x);
    }
}
void treedel(bnode *l,int ar[],int &k)
{
    bnode *t=l;
    if(k>=0)
    {
        int m;
        bnode *temp=l;
        search(l,temp,ar[k]);
        cout<<l->data<<" ";
        l->data=temp->data;
        if(temp->par!=NULL)
            temp=temp->par;
        else return;
        if(temp->rchild!=NULL)
            temp->rchild=NULL;
        else
            temp->lchild=NULL;
        if(l->lchild!=NULL&&l->rchild!=NULL)
            {m=min(l->lchild->data,l->rchild->data);}
        else if(l->lchild!=NULL)
            m=l->lchild->data;
        else    m=999;
        while(l->data>m)
        {
            if(l->lchild->data==m)temp=l->lchild;
            else temp=l->rchild;
            m=temp->data;
            temp->data=l->data;
            l->data=m;
            l=temp;
            if(l->lchild!=NULL&&l->rchild!=NULL)
                m=min(l->lchild->data,l->rchild->data);
            else if(l->lchild!=NULL)
                m=l->lchild->data;
            else    m=999;
        }
        int i=0,d=0;
        ar[0]=ar[k];
        int n=ar[0];
        if(2*i+2<=k)
            m=min(ar[2*i+1],ar[2*i+2]);
        else if(2*i+1<=k)
            m=ar[2*i+1];
        else
            m=999;
        while(ar[i]>m)
        {
            if(m==ar[2*i+1])i=2*i+1;
            else i=2*i+2;
            ar[d]=ar[i];
            ar[i]=n;
            if(2*i+2<=k)
                m=min(ar[2*i+1],ar[2*i+2]);
            else if(2*i+1<=k)
                m=ar[2*i+1];
            else
                m=999;
            d=i;
        }
        treedel(t,ar,--k);
    }
}
int main()
{
    bnode *root=new bnode;
    int ar[20];
    cout<<"\nStart entering the data for heap sort(0 to exit):";
    int num,j=0,k;
    cin>>num;
    ar[0]=num;
    while(1)
    {
        cin>>num;
        if(num==0)
            break;
        j++;
        create(ar,j,num);
    }
    root->data=ar[0];root->lchild=root->rchild=NULL;
    cout<<"\nDisplaying the list......\n";
    for(k=0;k<=j;k++)
        cout<<ar[k]<<" ";
    cout<<"\nCreating the list in tree form.........\n";
    bnode *m=listcreate(root,ar,0,j);
    queue q;
    q.enqueue(root);
    bnode *t=new bnode;t->data=-1;t->lchild=t->rchild=NULL;
    q.enqueue(t);
    print(q);
    cout<<endl;
    int a[20];
    for(k=0;k<=j;k++)
        a[k]=ar[k];
    k=j;
    root->par=NULL;
    cout<<"\nDisplaying the heapsort using the tree :";
    treedel(root,a,k);
}
