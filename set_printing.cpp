#include<iostream>
using namespace std;
#include<string.h>
#include<conio.h>

struct node
{
       int tag;
       union
       {
            char data;
            node *down;
       };
       node *next;
};

void nestedlist(node *root,string str,int &i)
{
     if(i<str.length()-1)
     {    
                    if(str[i]==']'||root->next!=NULL)
		            {
                                                     return;
                    }
                    else
                    {                               
                    if(str[i]=='[')
                    {
                                   node *temp=new node;
                                   temp->tag=1;
                                   temp->down=NULL;
                                   temp->next=NULL;
                                   root->next=temp;
                                   nestedlist(temp,str,++i);
                                   while(str[i]!=']')
                                                     i++;
                                   nestedlist(temp,str,++i);
                    }
                    else if((str[i]<='z'&&str[i]>='a'))
                    {
                    if(str[i-1]=='[')
                    {
                           node *temp=new node;
                           temp->tag=0;
                           temp->data=str[i];
                           temp->next=NULL;
                           root->down=temp;
                           cout<<temp->data<<" ";
                           nestedlist(temp,str,++i);
                    }
                    else
                    {
                          node *temp=new node;
                          temp->tag=0;
                          temp->data=str[i];
                          temp->next=NULL;
                          root->next=temp;
			              cout<<temp->data<<"  ";
                          nestedlist(temp,str,++i);
                          return;
                    }
                    }
                    }
     }
     else
         return;
}
int count(node* ptr)
{
	int cnt;
	if(ptr==NULL)
	cnt=0;
	else if(ptr->tag==0)
	cnt=1+count(ptr->next);
	else if(ptr->tag==1)
	cnt=count(ptr->down)+count(ptr->next)-1;
	return cnt;
}
void print(node* ptr,int &t)
{
	if(ptr==NULL)
	return;
	else if(ptr->tag==0)
	{
		cout<<ptr->data;
		print(ptr->next,++t);
	}
	else
	{
		node *tmp=ptr->down;
		for(int i=0;i<count(tmp);i++)
		cout<<" ";
		int x=t+count(tmp);
		print(ptr->next,x);
		cout<<endl;
		for(int i=0;i<t;i++)
		cout<<" ";
		print(ptr->down,t);
	}
}

int main()
{
    string s;
    cout<<"\nEnter the required node :";
    cin>>s;
    node *root=new node;
    root->tag=1;
    root->next=NULL;
    root->down=NULL;
    int i=0;
    nestedlist(root,s,i);
    cout<<endl;
    root=root->next->down;
    i=0;
    print(root,i);
    getch();
}
