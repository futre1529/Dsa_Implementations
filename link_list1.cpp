#include<iostream>
using namespace std;
#include<conio.h>

struct node
{
       int data;
       node *next;
};

node* add(node *l,int k)
{
     if(l==NULL)
     {
                cout<<"\nFirst node created";
                node *t=new node;
                t->data=k;
                t->next=NULL;
                l=t;
                return(l);
     }
     else
     {   
         node *t=new node;
         t->data=k;
         t->next=l;
         l=t;
         return(l);
     }
}
void remove(node *l,int k)
{
     node *t;int flag=0;
     if(l->next==NULL)
     {
                      if(l->data==k)
                      {
                                    t=l;
                                    l=l->next;
                                    delete(t);
                                    cout<<"\nNode deleted ";
                                    flag=1;
                      }
     }
     else
     {
         while(l->next!=NULL)
         {
                             if(l->next->data==k)
                             {
                                                 t=l->next;
                                                 l->next=t->next;
                                                 delete(t);
                                                 cout<<"\nNode deleted ";
                                                 flag=1;
                                                 break;
                             }
                             else
                                 l=l->next;
         }
     }
     if(flag==0)
                cout<<"\nNode not present ";
}
void check(node *l,int k)
{
     int flag=0;
     if(l->data==k)
                   {cout<<"\nValue found ";flag=1;return;}
     else
     {
         while(l->next!=NULL)
         {
                             if(l->data==k)
                             {
                                           cout<<"\nValue found ";
                                           flag=1;
                                           return;
                             }
                             else
                                 l=l->next;
         }
     }
     cout<<"\nNode not present ";
}
void display(node *l)
{
     if(l==NULL)
     cout<<"empty\a"; 
     while(l!=NULL)
     {
                   cout<<l->data<<"  ";
                   l=l->next;
     }
}
int main()
{
     node *l1=NULL;
     int op,k;
     while(1)
     {
     cout<<"\n1.Insert a value in the linked list\n2.Remove a value from linked list\n3.Search for a value in the list";
     cout<<"\n4.Display the list\n5.Exit from the list\nEnter your choice :";
     cin>>op;
     switch(op)
     {
               case 1:
                    cout<<"\nEnter the value you want to insert in the list :";cin>>k;
                    l1=add(l1,k);
                    break;
               case 2:
                    cout<<"\nEnter the value you want to delete from the list :";cin>>k;
                    remove(l1,k);
                    break;
               case 3:
                    cout<<"\nEnter the value you want to search in the list :";cin>>k;
                    check(l1,k);
                    break;
               case 4:
                    cout<<"\nDisplaying the list :"<<endl;
                    display(l1);
                    break;
               case 5:
                    exit(0);
               default:cout<<"\nPlease enter a valid choice ";break;
     }
     }
     getch();
}
