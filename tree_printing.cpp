//printing tree as it looks.
#include<iostream>
using namespace std;
#include<conio.h>

struct bstnode
{
       int data;
       bstnode *lchild;
       bstnode *rchild;
};

class queue
{
      public:
      int front,rear;
      bstnode *elements[20];
      void enqueue(bstnode *b);
      bstnode *dequeue();
      queue(){front=rear=-1;}
};
void queue::enqueue(bstnode *x)
{
         rear=(rear+1)%20;
         elements[rear]=x;
         if(front==-1)
                      front=0;
}
bstnode *queue::dequeue()
{
    bstnode *t=new bstnode;
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
     bstnode *t=new bstnode,*temp;
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
bstnode *addchild(bstnode *l,int k)
{
     if(l==NULL)
     {
                l=new bstnode;
                l->data=k;
                l->rchild=l->lchild=NULL;
     }
     else if(k>l->data)
          l->rchild=addchild(l->rchild,k);
     else
         l->lchild=addchild(l->lchild,k);
     return(l);
}
int main()
{
    queue q;
    bstnode *root=NULL;
    cout<<"\nEnter the values in the tree(Enter 0 to exit) :";
    int num;
    while(1)
    {
            cin>>num;
            if(num==0)
                      break;
            else
                root=addchild(root,num);
    }
    q.enqueue(root);
    bstnode *t=new bstnode;
    t->data=-1;
    t->lchild=t->rchild=NULL;
    q.enqueue(t);
    print(q);
    getch();
}
