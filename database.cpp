#include<iostream>
using namespace std;
#include<fstream>
#include<cstring>
#include<conio.h>

class student
{
      public:
             int roll;
             char name[20];
             void readdata();
             void writedata();
             void input();
             void disp();
};

int main()
{
     student s;
     cout<<"\nGenerating student database "<<endl;
     int i;
     la:cout<<"1.write______2.read______3.exit ";
     cin>>i;
     switch(i)
     {
              case 2:s.readdata();break;
              case 1:s.writedata();break;
              case 3:return 0;
     }
     goto la;
     getch();
}
void student::input()
{
     cout<<"\nName :";cin>>name;
     cout<<"Roll :";cin>>roll;
}
void student::disp()
{
     cout<<"\nName :"<<name<<endl;
     cout<<"Roll :"<<roll;
}
void student::readdata()
{
     student s;
     ifstream ifile;
     ifile.open("st.dat");
     while(ifile.read((char *)&s,sizeof(s)))
     {
     s.disp();
     cout<<endl;
     }
     ifile.close();
}
void student::writedata()
{
     student s;
     ofstream ofile;
     ofile.open("st.dat",ios::app);
     s.input();
     ofile.write((char*)&s,sizeof(s));
     ofile.close();
}
     
     
