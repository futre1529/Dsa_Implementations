#include<iostream>
using namespace std;


int* merge(int*A,int na,int* B,int nb)
{
    int nc=na+nb;
    int *C=new int [nc];
    int pa,pb,pc;
    pa=pb=pc=0;

    while(pa<na&&pb<nb)
    {
        if(A[pa]<=B[pb])
        C[pc++]=A[pa++];
        else
        C[pc++]=B[pb++];
    }

    while(pa<na)
    C[pc++]=A[pa++];

    while(pb<nb)
    C[pc++]=B[pb++];

    return C;
}
int* merge_sort(int* A,int n)
{
    if(n==1)
    return A;
    else
    return merge(merge_sort(A,n/2),n/2,merge_sort(&A[n/2],n-n/2),n-n/2);
}

void output(int* A,int n)
{
    cout<<"The Array is..."<<endl;
    for(int i=0;i<n;++i)
    cout<<A[i]<<",";
    cout<<"\b."<<endl;
}

int main()
{
        int Num[10]={10,33,31,8,2,11,4,3,1,5};
        int n=10;
        output(Num,n);
        int *NewNum=merge_sort(Num,n);
        output(NewNum,n);
}
