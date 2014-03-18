//bin sort
#include<iostream>
using namespace std;
#include<math.h>
#include<conio.h>

struct node
{
       int data;
       char var;
       node *next;
};
class queue
{
      public:
             int size,front,rear;
             node *elements[10];
             void enqueue(node *);
             node *dequeue();
             queue()
             {
                    front=-1;rear=-1;
             }
};
void queue::enqueue(node *x)
{
     if((rear+1)%10==front)
                             cout<<"\nQueue full ";
     else
     {
         rear=(rear+1)%10;
         elements[rear]=x;
         if(front==-1)
                      front=0;
     }
}
node *queue::dequeue()
{
    node *t=new node;
    t->data=-1;t->next=NULL;
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
            front=(front+1)%10;
        }
    }
    return(t);
}

void insert(node *&r,int x,char ch)
{
     node *t=new node;
     t->data=x;t->var=ch;
     t->next=NULL;
     if(r==NULL)
                r=t;
     else
     {
     node *temp=r;
     while(temp->next!=NULL)
                            temp=temp->next;
     temp->next=t;
     }
}

void binsort(node *l)
{
     node *temp;
     queue q[10];
     while(l!=NULL)
     {
                   q[l->data].enqueue(l);
                   l=l->next;
     }
     int i;
     cout<<"\nBin sort started...........\n";
     for(i=0;i<10;i++)
     {
                      while(q[i].front!=-1)
                      {
                                          temp=q[i].dequeue();
                                          cout<<temp->data<<","<<temp->var<<"  ";
                      }
     }
     cout<<"\nBin sort completed ";
}
int main()
{
    node *l=NULL;
    int n;char s;
    cout<<"\nEnter the index and character in the list(-1 to exit) :\n";
    while(1)
    {
            cin>>n;
            if(n==-1)
                    break;
            cin>>s;
            insert(l,n,s);
    }
    binsort(l);
    getch();
}
