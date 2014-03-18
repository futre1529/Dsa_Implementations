  #include<iostream>
  using namespace std;
          #include<conio.h>
          #include<stdio.h>
          #include<stdlib.h>

          struct node
          {
               int data;
               node *left;
               node *right;
          };

          node *tree=NULL;
          node *insert(node *tree,int ele,int &count);

          void preorder(node *tree);
          void inorder(node *tree);
          void postorder(node *tree);
        
          int main()
          {
               int ch,ele,count;
               do
               {
               count=1;
                    cout<<"\n\t\a\a1----INSERT A NODE IN A BINARY TREE.\a\a";
                    cout<<"\n\t\a\a2----PRE-ORDER TRAVERSAL.\a\a";
                    cout<<"\n\t\a\a3----IN-ORDER TRAVERSAL.\a\a";
                    cout<<"\n\t\a\a4----POST-ORDER TRAVERSAL.\a\a";
                    cout<<"\n\t\a\a5----EXIT.\a\a";
                    cout<<"\n\t\a\aENTER CHOICE::\a\a";
                    cin>>ch;
                    switch(ch)
                    {
                         case 1:
                         cout<<"\n\t\a\aENTER THE ELEMENT::\a\a";
                         cin>>ele;
                         tree=insert(tree,ele,count);
                         break;

                         case 2:
                         cout<<"\n\t\a\a****PRE-ORDER TRAVERSAL OF A TREE****\a\a";
                         preorder(tree);
                         break;

                         case 3:
                         cout<<"\n\t\a\a****IN-ORDER TRAVERSAL OF A TREE****\a\a";
                         inorder(tree);
                         break;

                         case 4:
                         cout<<"\n\t\a\a****POST-ORDER TRAVERSAL OF A TREE****\a\a";
                         postorder(tree);
                         break;

                         case 5:
                         exit(0);
                    }
               }while(ch!=5);
          }

          node *insert(node *tree,int ele,int &count)
          {
               if(tree==NULL)
               {
                    tree=new node;
                    tree->left=tree->right=NULL;
                    tree->data=ele;
                    count++;
               }
               else
               if(count%2==0)
               tree->left=insert(tree->left,ele,count);
               else
               tree->right=insert(tree->right,ele,count);
               return(tree);
          }

          void preorder(node *tree)
          {
               if(tree!=NULL)
               {
                    cout<<tree->data;
                    preorder(tree->left);
                    preorder(tree->right);
                    getch();
               }
          }

          void inorder(node *tree)
          {
               if(tree!=NULL)
               {
                    inorder(tree->left);
                    cout<<tree->data;
                    inorder(tree->right);
                    getch();
               }
          }

          void postorder(node *tree)
          {
               if(tree!=NULL)
               {
                    postorder(tree->left);
                    postorder(tree->right);
                    cout<<tree->data;
                    getch();
               }
          }
