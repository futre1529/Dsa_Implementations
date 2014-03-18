//tree height check
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
int max(int a,int b)
{
 	return(a>b?a:b);
}
int height(bstnode *l)
{
 	 if(l==NULL)
	 			return(-1);
	 else
		 return(1+max(height(l->lchild),height(l->rchild)));
}

void display(bstnode *l)
{
     if(l!=NULL)
     {
	  			cout<<l->data<<"-";
				cout<<"Height : "<<height(l)<<" and ";
				int x=height(l->lchild),y=height(l->rchild);
				if((x-y==0)||(x-y==1)||(x-y==-1))
						cout<<"balanced\n";
				else
						cout<<"unbalanced\n";
                display(l->lchild);
                display(l->rchild);
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
    getch();
}
