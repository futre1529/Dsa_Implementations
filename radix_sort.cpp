#include<iostream>
using namespace std;
#include<math.h>
#include<conio.h>

struct node
{
       int data;
       node *next;
};

void insert(node *r,int x)
{
     node *t=new node;
     t->data=x;
     t->next=NULL; 
     while(r->next!=NULL)
                            r=r->next;
     r->next=t;
}

void sort(int ar[],int l)
{
     node *r[10];
     int i=0,j,t,k;
     while(i<3)
     {
               for(j=0;j<10;j++)
                               r[j]=NULL;
               cout<<"\a";
               for(j=0;j<l;j++)
               {
                               t=ar[j]/pow(10,i);
                               if(r[t%10]==NULL)
                               {
                               node *temp=new node;
                               temp->data=ar[j];
                               temp->next=NULL;
                               r[t%10]=temp;
                               }
                               else
                               {
                               insert(r[t%10],ar[j]);
                               }
               
               }
               k=0,j=0;
               while(j<10)
               {
                          if(r[j]==NULL)
                                        j++;
                          else
                          {
                          while(r[j]!=NULL)
                          {
                              ar[k]=r[j]->data;
                              r[j]=r[j]->next;
                              k++;
                          }
                          }
               }
               for(j=0;j<l;j++)
                     cout<<ar[j]<<"  ";
               cout<<endl;
               i++;
     }
     cout<<"\nThe sorted list is :";
     for(j=0;j<l;j++)
                     cout<<ar[j]<<"  ";
} 
 
int main()
{
    int x,*ar;
    cout<<"\nEnter the no. of nos. u want to enter :";
    cin>>x;
    ar=new int[x];
    cout<<"\nNow enter the elements ";
    for(int i=0;i<x;i++)
            cin>>ar[i];
    cout<<"\nRadix sorting started.............."<<endl;
    sort(ar,x);
    getch();
}
