#include<iostream>
using namespace std;
#include<conio.h>

class queue
{
      public:
             class stack
             {
                   public:
                          int n,top;
                          int *ar;
                          void push(int);
                          int pop();
                          stack()
                          {
                                 top=-1;
                          }
             }stk[20],st;
             int size,front,rear;
             stack *elements;
             void enqueue(stack);
             stack dequeue();
             queue()
             {
                    front=-1;rear=-1;
             }
};
void queue::enqueue(stack x)
{
     if((rear+1)%size==front)
                             cout<<"\nQueue full ";
     else
     {
         rear=(rear+1)%size;
         elements[rear]=x;
         if(front==-1)
                      front=0;
     }
}
queue::stack queue::dequeue()
{
    stack t;
        if(front==rear)
        {
                       t=elements[front];
                       front=-1;rear=-1;
        }
        else
        {
            t=elements[front];
            front=(front+1)%size;
        }
    return(t);
}
void queue::stack::push(int x)
{
     ar[++top]=x;
}
int queue::stack::pop()
{
     return(ar[top--]);
}
int main()
{
     queue q;
     cout<<"\nEnter the size of the queue :";
     cin>>q.size;
     q.elements=new queue::stack[q.size];
     int op,i=0,j;
     while(1)
     {
             cout<<"\n1.Enter\n2.Remove\n3.Exit from program\nEnter your choice :";
             cin>>op;
             switch(op)
             {
                      case 1:
                           cout<<"\nEnter the size of stack :";cin>>q.stk[i].n;
                           q.stk[i].ar=new int[q.stk[i].n];
                           cout<<"\nEnter the data in the stack :";
                           for(j=0;j<q.stk[i].n;j++)
                           {
                                                       cin>>q.stk[i].ar[j];
                                                       q.stk[i].push(q.stk[i].ar[j]);
                           }
                           q.enqueue(q.stk[i]);
                           break;
                      case 2:
                           cout<<"\nPopping process......"<<endl;
                           q.st=q.dequeue();
                           for(j=0;j<q.st.n;j++)
                           {
                                                cout<<q.st.pop();
                           }
                           break;
                      case 3:
                           exit(0);
             }
             i++;
     }
     getch();
}
