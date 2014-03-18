#include<iostream>
using namespace std;

main()
{
      int *p, v = 0;
      p = &v;
      *p = 42;
      cout<<v<<*p<<endl;
      system("pause");
}
