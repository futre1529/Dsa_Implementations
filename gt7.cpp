#include <iostream>
#include <cstring>
using namespace std;
struct gtnode
{
	gtnode *parent;
	int data;
	int size;
	gtnode **child;
};
void swap(int &x,int &y)
{ int t;
	t=x;
	x=y;
	y=t;
}
void insert(gtnode *&g)
{
cout<<"Enter the Number of child of "<<g->data<<endl;
int size,k;
cin>>size;
g->size=size;
gtnode *temp;
temp=new gtnode;
if(size==0)
	g->child = NULL;
else
	g->child = new gtnode*[size];
for(int i=0;i<size;i++)
{
	g->child[i]= (gtnode*) new (gtnode);
	cout<<"Enter the child Data of "<<g->data<<endl;
	cin>>k;
	g->child[i]->data=k;
	g->child[i]->parent=g;
	if(g->data>g->child[i]->data)
	{	temp=g;
		swap(temp->data,g->child[i]->data);
		
		while(temp->parent!=NULL&&temp->data<temp->parent->data)
		{	swap(temp->data,temp->parent->data);
			temp=temp->parent;
		}
	}
}

for(int i=0;i<size;i++)
	insert(g->child[i]);

}
void printLevel(gtnode *g){
int tag=0;
if(g!=NULL)
{
	if(g->parent==0)
	cout<<g->data<<endl;
for(int i=0;i<g->size;i++)
{
	cout<<g->child[i]->data<<"   ";
	tag=1;
}
if(tag==1)
	cout<<endl;
if(g->child!=NULL)
	for(int i=0;i<g->size;i++)
		printLevel(g->child[i]);
}
}
main()
{
gtnode *g;
g = (gtnode*) new (gtnode);
cout<<"Enter the Root node \n";
cin>>g->data;
g->parent=0;
insert(g);
cout<<endl;
printLevel(g);
}
