//Deleting nodes in a bst
#include<iostream>
using namespace std;
#include<conio.h>
struct bstnode
{
       int data;
       bstnode *rchild;
       bstnode *lchild;
};

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

void display(bstnode *l)
{
     if(l!=NULL)
     {
                display(l->lchild);
                cout<<l->data<<"  ";
                display(l->rchild);
     }
}

bstnode *find(bstnode *l,int k)
{
		if(l->lchild!=NULL)
				if(k==l->lchild->data)
						return(l);
		if(l->rchild!=NULL)
				if(k==l->rchild->data)
						return(l);
		if(k>l->data)
			 l=find(l->rchild,k);
		else if(k<l->data)
			 l=find(l->lchild,k);
		return(l);
}
void findmax(bstnode *l,int &max)
{
 	  if(l!=NULL)
 	  {findmax(l->lchild,max);
	   max=l->data;
	   findmax(l->rchild,max);}
}
void delnode(bstnode *l,int k)
{
 	cout<<"\n@"<<k<<"@\n";
 	bstnode *f=find(l,k),*t;
 	cout<<"parent :"<<f->data<<endl;
	if(f->lchild!=NULL&&k==f->lchild->data)
		t=f->lchild;
	else if(f->rchild!=NULL&&k==f->rchild->data)
		t=f->rchild;
    else if(f->data==k)
        t=f->rchild;
	else
		{cout<<"\nElement not found\n";return;}
    cout<<"#"<<t->data<<"#";
	if(t->lchild==NULL&&t->rchild==NULL)
		{if(f->lchild!=NULL&&k==f->lchild->data)f->lchild=NULL;
		else
			f->rchild=NULL;}
	else if(t->lchild==NULL||t->rchild==NULL)
	{
	 	 if(f->lchild!=NULL&&k==f->lchild->data)
		 		{if(t->lchild==NULL)f->lchild=t->rchild;
				 else f->lchild=t->lchild;}
	 	 if(f->rchild!=NULL&&k==f->rchild->data)
		 		{if(t->lchild==NULL)f->rchild=t->rchild;
				 else f->rchild=t->lchild;}
	}
	else
	{
	int val=0;cout<<val;
	findmax(t,val);
	t->data=val;
	cout<<"\nsubtree :";display(t);cout<<"\n";
	delnode(t,val);
	}
}
int main()
{
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
    cout<<"\nDisplaying the list................\n";
    display(root);
    cout<<"\Deletion operation started............(press 0 to exit)\n";
    while(1)
    {
        cout<<"\nWhich element do you want to delete :";cin>>num;
        if(num==0)break;
        delnode(root,num);
        cout<<"\nDisplaying the tree after deletion operation.........\n";
        display(root);
    }
    getch();
}
