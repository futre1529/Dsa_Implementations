#include<iostream>
using namespace std;
#include<conio.h>

struct bnode
{
 	   char data;
	   int tag;
	   bnode *lchild;
	   bnode *rchild;
};

bnode *gettree(bnode *l,char ldr[],char dlr[],int i,int s)
{
 	  int flag=0,j=0;
	  if(i<s)
	  {
	   		 if(l==NULL)
			 {
			  			l=new bnode;
						l->data=dlr[i];
						l->lchild=l->rchild=NULL;
						l->tag=1;
			 }
			 while(ldr[j]!=dlr[i])
			 {
			  				if(ldr[j]==dlr[i+1])
												{flag=1;break;}
							j++;
			 }
