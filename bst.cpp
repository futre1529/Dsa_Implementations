#include <iostream>
#include <stack>
using namespace std;
struct node
{
	int data;
	node* lchild;
	node* rchild;
};
int count=0;
int size(node *r)
{
	if(r==NULL)
		return count;
	else
	{
		size(r->lchild);
		
		size(r->rchild);
		count++;
	}
}
int sizea(node *r)
{
	if(r==NULL)
		return 0;
	else
	{
		return(sizea(r->lchild)+1+sizea(r->rchild));
	}
}
void insert(node* &r,int j)
{
	if(r==NULL)
	{
		node *n=new node;
		n->data=j;
		n->lchild=NULL;
		n->rchild=NULL;
		r=n;
	}
	else if(j>r->data)
		insert(r->rchild,j);
	else if(j<r->data)
		insert(r->lchild,j);
}
void inorder(node* r)
{
	stack<node*> s;
	while(1)
	{
	while(r!=NULL)
	{
		s.push(r);
		r=r->lchild;
	}
	if(!s.empty())
	{
		node *temp=s.top();
		s.pop();
		cout<<temp->data<<" , ";
		r=temp->rchild;
	}
	else
		break;
	}
}

void deletea(node* &r,int j)
{
	if(r==NULL)
		return;
	else
	{
		deletea(r->lchild,j);
		if(r->data==j)
		{
			if((r->lchild!=NULL)&&(r->rchild!=NULL))
			{
				node *temp=r->rchild;
				while(temp->lchild!=NULL)
					temp=temp->lchild;
				r->data=temp->data;
				deletea(r->rchild,temp->data);
			}
			else if(r->lchild!=NULL)
			{
				r=r->lchild;
			}
			else if(r->rchild!=NULL)
			{
				r=r->rchild;
			}
			else
			{
				r=NULL;
			}

		}
		if(r!=NULL)
		deletea(r->rchild,j);
	}
}

void postorder(node *r)
{
	stack<node*> s;
	while(1)
	{
		while(r!=NULL)
		{
			s.push(r);
			r=r->lchild;
		}
		if(!s.empty())
		{
			node *temp=s.top();
			if(temp->rchild==NULL)
			{
				cout<<temp->data<<" , ";
				s.pop();

			}
			else
				r=temp->rchild;
		}
		else
			break;
	}
}

void preorder(node* r)
{
	stack<node*> s;
	while(1)
	{
		while(r!=NULL)
		{
			cout<<r->data<<" , ";
			s.push(r);
			r=r->lchild;
		}
		if(!s.empty())
		{			
			node *temp=s.top();
			s.pop();
			r=temp->rchild;				
		}
		else
			break;
	}
}

void display(node *r)
{
	if(r->lchild!=NULL)
		display(r->lchild);
	cout<<r->data<<" , ";
	if(r->rchild!=NULL)
		display(r->rchild);
}
int height(node* &r)
{
	if(r==NULL)
		return -1;
	int i=height(r->lchild);
	int j=height(r->rchild);
	if(i>j)
		return i+1;
	else
		return j+1;
}

void mirror(node* &r1,node* &r2)
{
	if(r1==NULL)
		return;
	else
	{
		if(r2==NULL)
		{
			node *n=new node;
			n->data=r1->data;
			n->lchild=NULL;
			n->rchild=NULL;
			r2=n;
			mirror(r1->lchild,r2->rchild);
			mirror(r1->rchild,r2->lchild);
		}
	}
}

void mirror(node* &r1)
{
	if(r1==NULL)
		return;
	else
	{
		node *temp=r1->lchild;
		r1->lchild=r1->rchild;
		r1->rchild=temp;
		mirror(r1->lchild);
		mirror(r1->rchild);
	}

}

int identical(node *r1,node *r2)
{
	if((r1==NULL)&&(r2==NULL))
		return 1;
	else if((r1!=NULL)&&(r2!=NULL))
		{
			identical(r1->lchild,r2->lchild);
			identical(r1->lchild,r2->rchild);
			if(r1->data!=r2->data)
				return 0;


		}
		else
		{
			return 0;
		}
}
int main()
{
	cout<<" Enter the number of nodes";
	int n;
	cin>>n;
	int j;
	node *root=NULL;
	node *mroot=NULL;
	for(int i=0;i<n;i++)
	{
		cin>>j;
		insert(root,j);

	}

	//display(root);
	//preorder(root);
	inorder(root);
	cout<<"\n";
	//mirror(root,mroot);
	mirror(root);
	inorder(root);
	//cout<<"\n Enter no to delete";
	//int l;cin>>l;
	//deletea(root,l);
	//inorder(root);
	//postorder(root);
	//int h=height(root);
	//cout<<"\nHeight is: "<<h;
	//cout<<"\n Size is: "<<size(root);
	//cout<<"\n Size is: "<<sizea(root);
	return 0;
}
