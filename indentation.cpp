#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
main(){
ifstream a;
ofstream b;
int t=0;
char d;
a.open("input.txt");
b.open("output1.txt");

while(!a.eof()){
a>>d;
if(d=='>' || d==';'){
b<<d;
b<<'\n';}
else if(d=='{'){
b<<d;
t+=2;
b<<setw(t)<<endl;
if(a.peek()=='{'){

continue;}}
else if(a.peek()==';'){b<<d;
a>>d;
b<<d<<'\n';
b<<setw(t);

}
else
b<<d;
}
}
