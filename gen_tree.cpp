//general tree
#include<iostream>
using namespace std;
#include<conio.h>
#include<cstring>

struct gnode
{
 	   char data;
	   gnode *fchild;
	   gnode *sibling;
};
//.................
class queue
{
      public:
      int front,rear;
      gnode *elements[20];
      void enqueue(gnode *b);
      gnode *dequeue();
      queue(){front=rear=-1;}
};
void queue::enqueue(gnode *x)
{
         rear=(rear+1)%20;
         elements[rear]=x;
         if(front==-1)
                      front=0;
}
gnode *queue::dequeue()
{
    gnode *t=new gnode;
    t->data=-1;
    t->fchild=t->sibling=NULL;
    if(front==-1)
                 return(t);
    else
    {
        if(front==rear)
        {
                       t=elements[front];
                       front=-1;rear=-1;
        }
        else
        {
            t=elements[front];
            front=(front+1)%20;
        }
    }
    return(t);
}
//....................
gnode *gtree(gnode *l,char ch[],int &i,int s)
{
 	 if(i<s)
	 {
	 if(l==NULL)
	 {
	  			l=new gnode;
				l->data=ch[i];
				l->fchild=l->sibling=NULL;
	 }
	 char  choice='n';
	 cout<<"Do u ("<<l->data<<") have any first child(y/n) :";
	 cin>>choice;
	 if(choice=='y')
	 				l->fchild=gtree(l->fchild,ch,++i,s);
	 cout<<"Do u ("<<l->data<<") have sibling :(y/n) :";
	 cin>>choice;
	 if(choice=='y')
	 				l->sibling=gtree(l->sibling,ch,++i,s);
	 return(l);
	 }
	 return(l);
}
//....................
void print(gnode *l,char fdata[],int &i)
{
 	 if(l!=NULL)
	 {
	  			print(l->fchild,fdata,i);
				cout<<l->data;
				fdata[i]=l->data;i++;
				print(l->sibling,fdata,i);
	 }
}
//..................
int spaceCount(gnode *temp,char fdata[],int i)
{
	while(fdata[i]!=temp->data)
		{cout<<".";i++;}
	return(i);
}
void fdisplay(queue q,char fdata[])
{
 	 gnode *t=new gnode,*l;
	 t->data='@';
	 t->fchild=t->sibling=NULL;
	 gnode *temp=q.dequeue();
	 int count=spaceCount(temp,fdata,0);
	 cout<<temp->data;
	 while(temp->data!='@')
	 {
	  		l=temp->fchild;
	  		while(l!=NULL)
			{
			 	q.enqueue(l);
				l=l->sibling;
			}
			temp=q.dequeue();
			if(temp->data!='@')
			{
			 	count=spaceCount(temp,fdata,count+1);
				cout<<temp->data;
			}
	}
	if(q.front==-1)
				   return;
	q.enqueue(t);
	cout<<endl;
	fdisplay(q,fdata);
}
//......................				
int main()
{
 	gnode *root=NULL;
	char fdata[20];
	cout<<"\nEnter the character codes of family member :";
	cin>>fdata;
	root=new gnode;
	root->data=fdata[0];
	root->fchild=root->sibling=NULL;
	int i=0;
	gnode *t=gtree(root,fdata,i,strlen(fdata));
	cout<<"\nDisplaying the family tree ";
	i=0;
	print(root,fdata,i);cout<<"------";
	for(i=0;i<strlen(fdata);i++)
				   cout<<fdata[i];
	cout<<"\nLevel order display of the famiy :\n";
	queue q;
	q.enqueue(root);
	t=new gnode;t->data='@';t->fchild=t->sibling=NULL;
	q.enqueue(t);
	fdisplay(q,fdata);
	getch();
}
