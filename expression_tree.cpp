#include<iostream>
using namespace std;
#include<conio.h>
#include<cstring>

struct bnode
{
 	   char data;
 	   bnode *lchild;
 	   bnode *rchild;
};

class stack
{
      public:
             int size;
             bnode *elements[20];
             int top;
             void push(bnode *);
             bnode *pop();
 			 stack(){top=-1;}
};
bnode *stack::pop()
{
   bnode *t=new bnode;t->data=-1;t->lchild=t->rchild=NULL;
   if(top!=-1)
              return(elements[top--]);
   else
       return(t);
}
void stack::push(bnode *x)
{
     if(top!=19)
                    elements[++top]=x;
     else cout<<"\n Stack full ";
}

bnode *exptree(char pexp[],int size)
{
	 stack s;
	 int i=0;
	 bnode *t1,*t2;
	 while(i<size)
	 {
	  			  if(pexp[i]>='0'&&pexp[i]<='9')
				  {
				  bnode *t=new bnode;
				  t->data=pexp[i];
				  t->lchild=t->rchild=NULL;
				  s.push(t);
				  }
	 			  else
				  {
				  bnode *t=new bnode;t->data=pexp[i];
				  t1=s.pop();t2=s.pop();
				  t->rchild=t1;t->lchild=t2;
				  s.push(t);


				  }
				  i++;
	 }
	 t1=s.pop();
	 return(t1);
}

void display(bnode *l)
{
     if(l!=NULL)
     {
                display(l->lchild);
                cout<<l->data;
                display(l->rchild);
	  }
}

int main()
{
 	char exp[20];
	cout<<"\nEnter the postfix expression :";
	cin>>exp;
	int l=strlen(exp);
	bnode *root=exptree(exp,l);
	cout<<"\nThe prefix expression is :";
	display(root);
	getch();
}
