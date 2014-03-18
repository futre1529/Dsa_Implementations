#include<iostream>
using namespace std;
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node
{
       int data;
       node *link;
};
node *push(node *top,int val);
node *pop(node *top,int &val);
void show(node *top);  

main()
{
      node *top;
      top=NULL;
      int val,choice;
      char op='Y';
      do
      {
           cout<<"\npress 1 to add an element";
           cout<<"\npress 2 to remove an alement from the stack";
           cout<<"\npress 3 to show thw stack";
           cout<<"\npress 4 to exit";
           cout<<"\nenter ur choice :";
           cin>>choice;
           switch(choice)
           {
                         case 1:
                         do
                         {     
                              cout<<"enter the value u want to enter :";
                              cin>>val;
                              top=push(top,val);
                              cout<<"do u want to enter more value :";
                              cin>>op;
                         }while(toupper(op)=='Y');
                         break;
                         case 2:
                         do
                         {
                              top=pop(top,val);
                              if(val!=-1)
                                         cout<<"the value deleted from the stack is :"<<val;
                              cout<<"do u want to delete more elements :";
                              cin>>op;
                         }while(toupper(op)=='Y');
                         break;
                         case 3:
                              show(top);
                              break;
                         case 4:
                              exit(0);
           }
      }while(choice!=4);
}
                
node *push(node *top,int val)
{
     node *temp;
     temp=new node;
     temp->data=val;
     temp->link=NULL;
     if(top==NULL)
                  top=temp;
     else
     {
         temp->link=top;
         top=temp;
     }
     return(top);
}

node *pop(node *top,int &val)
{
     node *temp;
     if(top==NULL)
     {
                  val=-1;
                  return(top);
     }
     else
     {
         temp=top;
         top=top->link;
         temp->link=NULL;
         delete(temp);
     }
     return(top);
}

void show(node *top)
{
     node *temp;
     temp=top;
     while(temp!=NULL)
     {
                      cout<<temp->data;
                      temp=temp->link;
     }
}
