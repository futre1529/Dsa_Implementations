//7th type of node
#include<iostream>
using namespace std;

struct inode
{
    char name[20];
    char grade;
};
struct gnode
{
    int tag;
    union
    {
        char ch;
        inode *data;
    }info;
    gnode *parent;
    int noc;
    gnode **child;
};

gnode *create(gnode *l)
{
    if(l==NULL)
    {
        int op;
        l=new gnode;
        cout<<"\nDo u want to enter the character code or whole data(0/1) :";
        cin>>op;
        if(op==0)
        {
            char cd;
            cout<<"Enter the character code :";cin>>cd;
            (l->info).ch=cd;
            l->tag=0;
        }
        else
        {
            inode *id=new inode;
            cout<<"Enter the name :";cin>>id->name;
            cout<<"Enter your grade :";cin>>id->grade;
            (l->info).data=id;
            l->tag=1;
        }
        cout<<"Enter the no. of child :";cin>>l->noc;
        l->child=new gnode*[l->noc];
        op=0;
        while(op<l->noc)
            {l->child[op]=NULL;op++;}
    }
    int i=0;
    while(i<l->noc)
        {l->child[i]=create(l->child[i]);l->child[i]->parent=l;i++;}
    return(l);
}
void display(gnode *l)
{
    if(l!=NULL)
    {
        if(l->tag==0)
            cout<<(l->info).ch;
        else
        {
            cout<<((l->info).data)->name<<"-";
            cout<<((l->info).data)->grade;
        }
        cout<<endl;
        for(int i=0;i<l->noc;i++)
        {
            display(l->child[i]);
        }
    }
}
int maxim(int a,int b)
{
 	return(a>b?a:b);
}
int height(gnode *l)
{
    int m,i=0;
    if(l->noc==0)
        return(1);
    else if(l->noc==1)
        return(1+height(l->child[0]));
    else
    {
        while(i<l->noc-1)
            {m=(1+maxim(height(l->child[i]),height(l->child[i+1])));i++;}
        return(m);
    }
}
void printlevel(gnode *l,int level)
{
    if(level==1)
    {
        if(l->tag==0)
        cout<<(l->info).ch<<"  ";
        else
        {
            cout<<((l->info).data)->name<<"-";
            cout<<((l->info).data)->grade<<"  ";
        }
    }
    else
        for(int j=0;j<l->noc;)
            {printlevel(l->child[j],level-1);j++;}
}
void levelorder(gnode *l)
{
    int m=height(l),i=0,j;
    for(i=1;i<=m;i++)
    {
        printlevel(l,i);
        cout<<endl;
    }
}
int main()
{
    gnode *root=NULL;
    root=create(root);
    display(root);
    cout<<"\nDisplaying the height of the root :"<<height(root);
    cout<<"\n...Diplaying the level order version of tree...\n";
    levelorder(root);
}
