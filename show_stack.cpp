#include<iostream.h>
using namespace std;
#include<stdio.h>
#include<conio.h>

struct node
{
       int data;
       node *link;
};

main()
{
    node *ptr;
    ptr=NULL;
    int n,i,val;
    cout<<"how many elements do u want 2 enter :";
    cin>>n;
    cout<<"start entering the values one by one \n";
    for(i=0;i<n;i++)
    {
            cin>>val;
            node *temp;
            temp=new node;
            temp->data=val;
            temp->link=NULL;
            if(ptr==NULL)
                         ptr=temp;
            else
            {
                temp->link=ptr;
                ptr=temp;
            }
    }
    cout<<"the elemnts entered in the stack are :\n";
    for(i=0;i<n;i++)
    {
                    cout<<ptr->data;
                    ptr=ptr->link;
    }
    getch();
}              
