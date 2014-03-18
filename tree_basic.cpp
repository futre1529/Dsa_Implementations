//basic bst operation
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
