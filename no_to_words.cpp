#include<iostream>
using namespace std;
#include<conio.h>


void others(int *a,int s,int l);
void digits(int a);
void hundreds(int d[],int l);
void tdigits(int a,int b);
int main()
{
    int *a,b,i;
    cout<<"\nEnter a maximum of 6 digits ";
    cout<<"\nEnter the number of digits :";
    cin>>b;
    a=new int[b];
    cout<<"\nEnter the digits one by one(press space after each digit) :";
    for(i=0;i<b;i++)
            cin>>a[i];
    cout<<"\nThe number ";
    for(i=0;i<b;i++)
                    cout<<a[i];
    cout<<" in words is :";
    others(a,0,b);
    getch();
}

void others(int *a,int s,int l)
{
     int d[3],i,c,j;
     if(l>3&&s==0)
     {
          c=l-3;
          for(i=0;i<c;i++)
                          d[i]=a[i];
          hundreds(d,c);
          cout<<" thousand ";
          others(a,s+c,l);
          
     }
     else
     {
         for(i=s,j=0;i<l;i++,j++)
                                 d[j]=a[i];
         hundreds(d,l-s);
          
     }
}
void hundreds(int d[],int l)
{  
     switch(l)
     {
              case 1:
                   digits(d[l-1]);       
                   break;
              case 2:
                   tdigits(d[l-1],d[l]);
                   if(d[l-1]!=1)
                                digits(d[l]); 
                   break;
              case 3:
                   digits(d[0]);
                   cout<<" hundred ";
                   hundreds(d,l-1);
                   break;
     }
}
void digits(int a)
{
     switch(a)
     {
              case 1:cout<<" one ";break;
              case 2:cout<<" two ";break;
              case 3:cout<<" three ";break;
              case 4:cout<<" four ";break;
              case 5:cout<<" five ";break;
              case 6:cout<<" six ";break;
              case 7:cout<<" seven ";break;
              case 8:cout<<" eight ";break;
              case 9:cout<<" nine ";break;
     }
}
void tdigits(int a,int b)
{
     switch(a)
     {
              case 0:return;
              case 1:
                   switch(b)
                   {
                            case 0:cout<<" ten ";break;
                            case 1:cout<<" eleven ";break;
                            case 2:cout<<" twelve ";break;
                            case 3:cout<<" thirteen ";break;
                            case 4:cout<<" fourteen ";break;
                            case 5:cout<<" fiteen ";break;
                            case 6:cout<<" sixteen ";break;
                            case 7:cout<<" seventeen ";break;
                            case 8:cout<<" eighteen ";break;
                            case 9:cout<<" nineten ";break;
                   }
                   break;
              case 2:
                   cout<<" twenty ";break;
              case 3:
                   cout<<" thirty ";break;
              case 4:
                   cout<<" fourty ";break;
              case 5:
                   cout<<" fifty ";break;
              case 6:
                   cout<<" sixty ";break;
              case 7:
                   cout<<" seventy ";break;
              case 8:
                   cout<<" eighty ";break;
              case 9:
                   cout<<" ninety ";break;
     }
}                   
                                               
