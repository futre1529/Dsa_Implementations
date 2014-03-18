#include<iostream>
using namespace std;

struct csnode
{
	int sno;
	int cno;
	csnode *cnext;
	csnode *snext;
};

void construct(csnode *cnode[],csnode *snode[],int n,int m)//snode is student node and cnode is subject code node
{
	int i,num;
	for(i=0;i<3;i++)
	{
		snode[i]=new csnode;
		snode[i]->sno=i;
		snode[i]->cno=0;
		snode[i]->cnext=NULL;
		snode[i]->snext=snode[i];
		csnode *t=snode[i];
		cout<<"\nStart entering your subject codes ";
		while(1)
		{
			cin>>num;
			if(num==0)
				break;
			csnode *temp=new csnode;
			temp->sno=i;temp->cno=num;
			temp->snext=t;temp->cnext=NULL;
			snode[i]->snext=temp;
			snode[i]=snode[i]->snext;
			cout<<"@"<<snode[i]->cno;
		}
		snode[i]->snext=t;
		snode[i]=t;
	}
	int j;
	for(i=0;i<n;i++)
	{
		cnode[i]=new csnode;
		cnode[i]->sno=0;cnode[i]->cno=i;
		cnode[i]->snext=NULL;
		cnode[i]->cnext=cnode[i];
		csnode *t=cnode[i];
		j=0;
		while(j<3)
		{
			if(snode[j]->snext->cno<=(i+1))
				snode[j]=snode[j]->snext;
			if(snode[j]->cno==(i+1))
			{
				cnode[i]->cnext=snode[j];
				snode[j]->cnext=t;
				cnode[i]=cnode[i]->cnext;
				cout<<cnode[i]->cno;
			}
			else
				cout<<" ";
			j++;
		}
		cout<<endl;
		cnode[i]->cnext=t;
		cnode[i]=t;
	}
}

int main()
{
	csnode *cnode[4];csnode *snode[5];
	construct(cnode,snode,4,5);
	return(0);
}
