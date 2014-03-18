#include<iostream>
using namespace std;
#include<stdio.h>
#include<conio.h>
struct bnode{
       struct bnode *child[5];
       int count;
       int value[5];
       };
       typedef struct bnode node;

node * root=NULL;
void insert(int val);
int put(int,node*,int *,node**);
void fillnode(int ,node *,node*,int);
int search(int,node *,int *);
void insert(int val)
{
     int i,flag;
     node * c,*n;
     flag=put(val,root,&i,&c);
     if(flag)
     {
                n=new node;
                n->count=1;//setting count 1
                n->value[1]=i;//setting node's value to i
                n->child[0]=root;//setting o th child to root
                n->child[1]=c;//setting first child to null/(Split case)
     }
}
int put(int value,node * n,int * p,node ** c)
{
    int l;//storing the position
    if(n==NULL)//checking if n is NULL
    {
               *p=value;//setting value
               *c=NULL;//setting child to NULL
               return 1;
    }
    else{
         if(search(value,n,&l))//if search return 1 ie is successful
          {printf("\nDuplicate value not allowed\n");
           }
         if(put(value,n->child[l],p,c))
          {
                if(n->count<4)
                {
                              fillnode(*p,*c,n,l);
                              return 0;
                }
         }return 0;


}}
void fillnode(int val,node * c,node * n,int k)
{
     int i;
     for(i=n->count;i>k;i--)
     {
          n->value[i+1]=n->value[i];//shifting down
          n->child[i+1]=n->child[i];

     }
     n->value[k+1]=val;//setting value
     n->child[k+1]=c;//setting child
     n->count++;//setting count
}
int search(int val,node* n,int *pos)
{
    if(val<n->value[1])
    {*pos=0;return 0;//value cant exist if smaller than first value
    }
     else
     {
      *pos=n->count;
      while((val<n->value[*pos])&& *pos>1)
      {
       (*pos)--;
      }
      if(val==n->value[*pos])//successful search
      return 1;
      else return 0;
     }
}
void display(node * root)
{
     int i;
     if(root!=NULL)
     {
                   for(i=1;i<root->count;i++)
                   {
                      display(root->child[i-1]);
                      printf("%d\t",root->value[i]);
                   }
                   display(root->child[i-1]);
     }
}
//int main()
//{
//    int ch=1,value;
//    do{
//        printf("\n\t\t\t\tMenu\n1)Insert2)Delete3)Display0)Exit\n");
//        printf("Enter choice please\n");
//        scanf("%d",&ch);
//        switch(ch)
//        {
//                  case 0:return;
//                  case 1:printf("\nEnter value to insert");scanf("%d",&value);insert(value);display(root);break;
//                  case 3:display(root);break;
//        }
//        printf("\nDo you want to continue\n1/0");
//        scanf("%d",&ch);
//}while(ch!=0);
//    getch();
//    return 0;
//}
int main()
{
int i=0;
for(i=1;i<=14;i++)
insert(i*i);
cout<<"displaying the root";
//display(root);
cout<<root->child[0]->value[0];
getch();
return 0;
}
