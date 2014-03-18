//trie program for binary numbers as input
#include<iostream>
#include<string>
using namespace std;

struct dnode
{
    string str;
};

struct tnode
{
    tnode *g[3];
    dnode *d[3];
    int tag[3];
};

void initialize(tnode *t)
{
    for(int i=0;i<3;i++)
    {
        t->g[i]=NULL;
        t->d[i]=NULL;
        t->tag[i]=0;
    }
}
void insert(tnode *t,string s,int &i)
{
    int x,flag=0;
    if(t==NULL)
    {
        t=new tnode;
        initialize(t);
    }
    if(i<s.length())
    {
        x=int(s[i]-'0')+1;
        cout<<x<<" "<<t->tag[x]<<"\t";
        if(t->tag[x]==0)
        {
            t->d[x]=new dnode;
            (t->d[x])->str=s;
            cout<<s;
            t->tag[x]=1;
            return;
        }
        else if(t->tag[x]==1)
        {
            string s1=(t->d[x])->str;
            if(i==s.length()-1){flag=1;goto l1;}
            while(s[i+1]==s1[i+1])
            {
                t->g[x]=new tnode;
                t->tag[x]=2;
                t=t->g[x];
				initialize(t);
                x=int(s[i+1]-'0')+1;
                i++;
                if(i==s.length()-1){flag=1;break;}
            }
            l1:t->g[x]=new tnode;
               t->tag[x]=2;
               t=t->g[x];
			   initialize(t);
            if(flag==0)
                x=int(s[i+1]-'0')+1;
            else x=0;
                t->d[x]=new dnode;
                (t->d[x])->str=s;
                t->tag[x]=1;
            x=int(s1[i+1]-'0')+1;
            t->d[x]=new dnode;
            (t->d[x])->str=s1;
            t->tag[x]=1;
        }
        else if(t->tag[x]==2)
        {
            t=t->g[x];
            cout<<" recurring ";
            insert(t,s,++i);
        }
    }
}
void print(tnode *h)
{
    for(int i=0;i<3;i++)
    {
        if(h->tag[i]==1)
            cout<<(h->d[i])->str<<"\n";
        else if(h->tag[i]==2)
            print(h->g[i]);
    }
}
tnode *search(tnode *l,string s,int &i)
{
	int j=int(s[i]-'0')+1;
	cout<<j<<"!"<<l->tag[j]<<"\n";
	if(l->tag[j]==1)
		return(l);
	else if(l->tag[j]==2)
	{cout<<"!!!!";return(search(l->g[j],s,++i));}
}
int fillcheck(tnode *l)
{
	int count=0;
	for(int i=0;i<3;i++)
		if(l->tag[i]==1)
			count++;
	return(count);
}
tnode *par(tnode *l,string s,int &i,int &k)
{
    if(i>0)
    {
        int j=int(s[k]-'0')+1;
        return(par(l->g[j],s,--i,++k));
    }
    else
        return(l);
}
void del(tnode *h,string s)
{
	int i=0,count;
	tnode *t=search(h,s,i);
	cout<<" @ "<<i<<" @ ";
	count=fillcheck(t);
	cout<<count;
	/*if(count==2)
	{
	    int k=0;
		tnode *p=par(h,s,i,k);
		for(i=0;i<3;i++)
			if((t->d[i])->str==s)
			{
				t->d[i]=NULL;
				t->tag[i]=0;
			}
        //cout<<"aila";
        for(i=0;i<3;i++)
            if(t->tag[i]==1)break;
        k=int(s[k]-'0')+1;
        p->d[k]=new dnode;
        (p->d[k])->str=s;
        p->g[k]=NULL;
	}*/
	else if(count==3)
	{
		cout<<"\n........\n"<<(t->d[2]->str)<<" !! ";
		cin>>count;
		for(i=0;i<3;i++)
			if((t->d[i])->str==s)
			{
				t->d[i]=NULL;
				t->tag[i]=0;
			}
	}
}
int main()
{
    tnode *h=new tnode,*t;
    initialize(h);
    string s;
    int i;
    while(1)
    {
        t=h;
        i=0;
        cout<<"\nEnter the binary code(enter 9 to exit) ";
        cin>>s;
        if(s[0]=='9')break;
        insert(t,s,i);
    }
    print(h);
	cout<<"\n"<<h->tag[1]<<"\n";
	cout<<"\nEnter the string u want to delete : ";
	cin>>s;
	del(h,s);
	cout<<"\nAfter deletion :\n";
	print(h);
}
