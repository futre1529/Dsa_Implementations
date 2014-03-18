//student record or any general record
#include<iostream>
using namespace std;
#include<fstream>

class person
{
    public:
    char last[20];
    char first[20];
    char adr[20];
    char state[20];
    public:
    void writing(ofstream &ofile,person &p)
    {
        ofile.write((char*)&p,sizeof(p));
    }

    void reading(ifstream &ifile,person &p)
    {
        ifile.read((char*)&p,sizeof(p));
    }
};
int main()
{
    person p;
    ofstream ofile;
    ofile.open("try.cpp",ios::binary);
    char ch='y';
    while(ch=='y')
    {
        cout<<"Enter ur last name :";cin>>p.last;
        cout<<"Enter ur first name :";cin>>p.first;
        cout<<"Enter ur address :";cin>>p.adr;
        cout<<"Enter ur state :";cin>>p.state;
        p.writing(ofile,p);
        cout<<"Do u want to eneter more record :(y/n)";
        cin>>ch;
    }
    ofile.close();
    ifstream ifile;
    ifile.open("try.cpp");
    ifile.read((char*)&p,sizeof(p));
    while(ifile)
    {
        cout<<p.first<<" "<<p.last<<" addres is "<<p.adr<<" and state is "<<p.state<<endl;
        ifile.read((char*)&p,sizeof(p));
    }
    ifile.close();
}
