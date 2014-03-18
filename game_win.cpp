//general binary tree
#include<iostream>
using namespace std;
#include<conio.h>
struct bstnode
{
       int data;
       bstnode *rchild;
       bstnode *lchild;
};

bstnode *addchild(bstnode *l,int ar[],int &i,int size)
{
 	 if(i<size)
	 {
 	 char ch;
     if(l==NULL)
     {
                l=new bstnode;
                l->data=ar[i];
                l->rchild=l->lchild=NULL;
     }
     cout<<"Do you want to enter into left node(y/n) :";
	 cin>>ch;
	 if(ch=='y')
         l->lchild=addchild(l->lchild,ar,++i,size);
	  	 cout<<"Do you want to enter into right node(y/n) :";
         cin>>ch;
		 if(ch=='y')
		 			l->rchild=addchild(l->rchild,ar,++i,size);
	 return(l);
	 }
	 return(l);
}

void display(bstnode *l)
{
     if(l!=NULL)
     {
                cout<<l->data<<"  ";
                display(l->lchild);
                display(l->rchild);
     }
}
void game(bstnode *l)
{
    if(l->data<0)
    {
        if(l->lchild->data>0&&l->rchild->data>0)
            l->data=(l->lchild->data)>(l->rchild->data)?(l->lchild->data):(l->rchild->data);
        if(l->lchild->data<0)
            game(l->lchild);
        if(l->rchild->data<0)
            game(l->rchild);
    }
}
int main()
{
    bstnode *root=NULL;
	int size,i;
    cout<<"\nEnter the no. of values in the tree :";
    cin>>size;
	int *ar=new int [size];
	cout<<"\nEnter those values :";
	for(i=0;i<size;i++)
			cin>>ar[i];
	cout<<"\nConstructing the tree with your choice............\n";
	i=0;
	root=addchild(root,ar,i,size);
	cout<<"\nDisplaying the list................\n";
	cout<<"\nDoing inorder traversal :\n";
    display(root);
    game(root);
    cout<<"\nDisplaying the new tree formed :";
    root->data=(root->lchild->data)>(root->rchild->data)?(root->lchild->data):(root->rchild->data);
    display(root);
    getch();
}
