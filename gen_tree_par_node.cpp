#include<iostream>
using namespace std;
#include<conio.h>

struct node
{
    char data;
 	char visit;
    node *lchild;
    node *rchild;
    node *par;
};

node *create(node *l)
{
    if(l==NULL)
 	{
        l=new node;char val;
	  	cout<<"Enter d member name :";
	  	cin>>val;
	  	l->data=val;l->visit='u';
	  	l->lchild=l->rchild=l->par=NULL;
    }
    char ch;
    cout<<"Do u ("<<l->data<<") have left child ";
    cin>>ch;
    if(ch=='y')
    	{l->lchild=create(l->lchild);l->lchild->par=l;}
    cout<<"Do u ("<<l->data<<") have right child ";
    cin>>ch;
    if(ch=='y')
    	{l->rchild=create(l->rchild);l->rchild->par=l;}
    return(l);
}

void display(node *l)
{
    if(l!=NULL)
 	{
		display(l->lchild);
		cout<<l->data;
		if(l->par!=NULL)
		cout<<" and the parent is :"<<l->par->data<<endl;
		else cout<<" ->i am the head of the family aur meri le lo..."<<endl;
		display(l->rchild);
    }
}
void displaypath(node *l)
{
    if(l->visit=='r')
    {
        cout<<l->data<<" ";
        if(l->par==NULL)
            return;
        if(l->par->visit=='l')
        {
            l->visit='r';
            return;
        }
        else
        {
            l->par->visit='l';l=l->par;displaypath(l->rchild);
            l->visit='r';displaypath(l);
        }
    }
    else if(l->visit=='l')
    {
        if(l->rchild!=NULL)
            displaypath(l->rchild);
        l->visit='r';
    }
    else
    {
        while(l->lchild!=NULL)
            l=l->lchild;
        l->visit='r';
        displaypath(l);
    }
}
int main()
{
 	node *root=new node;root->lchild=root->rchild=root->par=NULL;root->visit='u';
	char ch;
 	cout<<"\nEnter the head ";
 	cin>>ch;
 	root->data=ch;
 	node *t=create(root);
 	display(root);
 	node *l=root;
 	while(l->lchild!=NULL)
        l=l->lchild;
    cout<<"\nTopological sort.....\n";
    l->visit='r';
    cout<<"\n@"<<l->data<<"@\n";
 	displaypath(l);
	getch();
}
