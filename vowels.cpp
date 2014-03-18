//COUNT VOWELS

#include<iostream>
#include<string>
using namespace std;

int countvowels(string);

main()
{
    string *S;
    int T;
    cin>>T;
    S=new string [T];
    for(int i=0;i<T;i++)
    cin>>S[i];
    for(int i=0;i<T;i++)
    cout<<countvowels(S[i])<<endl;
}

int countvowels(string S)
{
    int count=0;
    for(int i=0;i<S.length();i++)
    {
        if(S[i]=='a'||S[i]=='e'||S[i]=='i'||S[i]=='o'||S[i]=='u')
        count++;
    }
    return count;
}
