#include<iostream>
using namespace std;
#include<conio.h>

class queue
{
      public:
             int size,front,rear;
             int *elements;
             void enqueue(int);
             int dequeue();
             queue()
             {
                    front=-1;rear=-1;
             }
};
void queue::enqueue(int x)
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
int queue::dequeue()
{
    int t=-1;
    if(front==-1)
                 return(-1);
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
            front=(front+1)%size;
        }
    }
    return(t);
}
int main()
{
     queue q;
     cout<<"\nEnter the size of the queue :";
     cin>>q.size;
     q.elements=new int[q.size];
     int op,data,l;
     while(1)
     {
             cout<<"\nPress 1 for entering\nPress 2 for exiting\nPress 0 to close the program ";
             cout<<"\nNow enter your choice :";
             cin>>op;
             switch(op)
             {
                       case 1:
                            cout<<"\nEnter the data :";
                            cin>>data;
                            q.enqueue(data);
                            break;
                       case 2:
                            l=q.dequeue();
                            if(l>-1)
                                    cout<<"\nThe removed data is :"<<l;
                            else
                                cout<<"\nqueue empty ";
                            break;
                       case 0:
                            exit(0);
             }
     }
     getch();
}
