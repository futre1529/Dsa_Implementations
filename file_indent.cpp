#include<iostream>
using namespace std;
#include<fstream>
#include<conio.h>

void indentation()
{
     char ch;
     ifstream ifile;
     int value=1,i;
     ifile.open("trying.cpp");
     ofstream ofile;
     ofile.open("program.txt");
     ifile.seekg(0);
     while(ifile)
     {
				 i=0;
	         	 ifile.get(ch);ofile.put(ch);
                 if(ch=='>'||ch==')')
                 {
                             ifile.get(ch);
                             if(ch==';'){ofile.put(ch);ifile.get(ch);}
                             if(ch!='\n')
                             {
                                         ifile>>ch;            
                                         ofile.put('\n');
                             }
			     			if(ch=='{'||ch=='\n')
							{
							ofile.put(ch);ofile.put('\n');ifile.get(ch);
							if(ch!='\n'){ifile>>ch;value++;
							while(i<value){ofile.put('\t');i++;}
							ofile.put(ch);continue;}
							value++;ofile.put('\t');
							continue;
							}
                             ofile.put(ch);
                 }
                 else if(ch==';')
                 {
                      ifile.get(ch);
                      if(ch==' ')
                      {
                            ifile>>ch;          
                            ofile.put('\n');if(ch=='}')goto l1;while(i<value){ofile.put('\t');i++;}
                      }
		      else if(isalnum(ch))
		      {ofile.put('\n');
			while(i<value-1){ofile.put('\t');i++;}ofile.put(ch);}
		      else if(ch=='}')
			{l1:while(i<value){ofile.put('\t');i++;}value--;continue;}
		      else
                      {
			ifile>>ch;
			if(ch=='#'){ofile<<"\n"<<ch;continue;}
			ofile.put('\n');while(i<value-1){ofile.put('\t');i++;}ofile.put(ch);
		      }
                 }
     }
     ofile.close();
     ifile.close();
     ifstream ifile1;
     ifile1.open("program.txt");
     while(ifile1)
     {
                   ifile1.get(ch);
                   cout<<ch;
     }
     ifile.close();
}

int main()
{
    indentation();
    getch();
}
