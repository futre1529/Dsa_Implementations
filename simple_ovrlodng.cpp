#include<iostream>
using namespace std;
#include<conio.h>
#include<math.h>
float area(float a,float b,float c)
{
      float s,ar;
      s=(a+b+c)/2;
      ar=sqrt(s*(s-a)*(s-b)*(s-c));
      return ar;
      }
      float area(float a,float b)
      {
            float ar;
            ar=a*b;
            return ar;
            }
      float area(float a)
      {
            float ar;
            ar= a*a;
            return ar;
            }
main()
{int choice,s1,s2,s3;
float ar;
do{
     cout<<"\nchoice main menu\n";
cout<<"1.triangle\n";
cout<<"2.rectangle\n";
cout<<"3.square\n";
cout<<"enter choice (1-4)\n";
cin>>choice;
cout<<"\n";
switch(choice)
{
              case 1:
                   cout<<"enter 3 sides\n";
                   cin>>s1>>s2>>s3;
                   ar = area(s1,s2,s3);
                   cout<<"the area is"<<ar<<"\n";
                   break;
              case 2:
                   cout<<"enter 2 sides\n";
                   cin>>s1>>s2;
                   ar=area(s1,s2);
                   cout<<"the area is" <<ar<<"\n";
                   break;
              case 3:
                   cout<<"enter a side\n";
                   cin>>s1;
                   ar=area(s1);
                   cout<<"the area is"<<ar<<"\n";
                   break;
              case 4:break;
              default :
                   cout<<"wrong entry\n";
                   cout<<"enter again";
                   
                   };
                   }while(choice>0&&choice<4);
                   getch();
                   }                                        
