#include<iostream>
using namespace std;
#include<conio.h>
struct bstnode
{
       int data;
	   char visit;
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
//.........................................
class stack
{
      public:
             bstnode *elements[20];
             int top;
             void push(bstnode *);
             bstnode *pop();
			 stack(){top=-1;}
};
bstnode *stack::pop()
{
 bstnode *t=new bstnode;t->data=-1,t->lchild=t->rchild=NULL;
   if(top!=-1)
              return(elements[top--]);
   else
       return(t);
}
void stack::push(bstnode *x)
{
     if(top!=19)
                    elements[++top]=x; 
     else cout<<"\n Stack full ";
}
//..................................................
void idisplay(bstnode *l)
{
 	 stack s;
	 cout<<l->data<<" ";
	 s.push(l);
	 bstnode *temp;
 	 while(s.top!=-1)
	 {
	  		temp=s.pop();
	  		if(temp->lchild!=NULL&&temp->visit!='y')
			{
			 		cout<<temp->lchild->data<<" ";
					s.push(temp);
					temp->visit='y';
					s.push(temp->lchild);
			}
			else
			{
			 	if(temp->rchild!=NULL)
				{
				 		cout<<temp->rchild->data<<" ";
						temp->visit='y';
						s.push(temp->rchild);
				}
				else if(temp->visit!='y')
				{
				 		temp->visit='y';
						cout<<temp->data<<" \b\b\b";
				}
			}					 		
	 }
	 cout<<"  ";
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
    cout<<"\nDisplaying the list.........(inorder)\n";
    display(root);
	cout<<"\nDisplaying the preorder tree using iterative version..........\n";
	idisplay(root);
    getch();
}
