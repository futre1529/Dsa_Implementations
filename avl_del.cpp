#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

struct avlnode
{  int data;
   avlnode *lc;
   avlnode *rc;
};

int max(int n1,int n2)
{if(n1>=n2)
    return(n1);
    else
    return(n2);
}

int height(avlnode *b)
{ int x,y;

if(b==NULL)
  return(-1);
  else
  {x=max(height(b->lc),height(b->rc))+1;
  return(x);
  }
}

avlnode* maxnode(avlnode *n1,avlnode *n2)
{if(height(n1)>height(n2))
  return n1;
  else
  return n2;
}

void rotate(avlnode *&b,int k)
{avlnode *k1=b;
  avlnode *k3=maxnode(b->lc,b->rc);
  avlnode *k2=maxnode(k3->lc,k3->rc);
  if(k>k1->data&&k<k3->data)
   { k1->rc=k2->lc;
     k3->lc=k2->rc;
     k2->lc=k1;
     k2->rc=k3;
     b=k2;
   }
  if(k>k1->data&&k>k3->data)
  { k1->rc=k3->lc;
    k3->lc=k1;
    b=k3;
  }
  if(k<k1->data&&k>k3->data)
  {  k1->lc=k2->rc;
    k3->rc=k2->lc;
    k2->rc=k1;
    k2->lc=k3;
    b=k2;
  }
  if(k<k1->data&&k<k3->data)
  { k1->lc=k3->rc;
     k3->rc=k1;
     b=k3;
  }
}

void insert(avlnode *&b,int k)
{  if(b==NULL)
    {b=new avlnode;
     b->data=k;
     b->lc=NULL;
     b->rc=NULL;
    }
  else if(k<b->data)
   { insert(b->lc,k);
      if(abs(height(b->lc)-height(b->rc))>1)
      rotate(b,k);
     }
  else
  {insert(b->rc,k);
    if(abs(height(b->lc)-height(b->rc))>1)
      rotate(b,k);

  }
}
void print(avlnode *b)
{if(b==NULL)  return;

print(b->lc);
   cout<<b->data;
   print(b->rc);
}

int main()
 {avlnode *a=NULL;
 int num;
 cout<<"enter the no and press -1 to exit";
 cin>>num;
 while(num!=-1)
 {insert(a,num);
  cin>>num;
  }
print(a);
}
