#include<iostream>
using namespace std;

void create(int ar[],int j,int k,int d)
{
    int i=j;
    ar[i]=k;
    j=(j-1)/d;
    if(k<ar[j])
    {
        while(k<ar[j]&&j>=0)
        {
            ar[i]=ar[j];
            ar[j]=k;
            i=(i-1)/d;
            j=(j-1)/d;
        }
    }
}
void del(int ar[],int &j,int d)
{
    if(j>=0)
    {
        int i=0,k=0,l,p=0,b;
        cout<<ar[0]<<" ";
        ar[0]=ar[j];
        j-=1;
        int m=ar[0];
        if(d*i+1<=j)
        {
            l=ar[d*i+1];b=2;
            for(k=d*i+b;b<=d&&k<=j;b++,k++)
                if(ar[k]<l)l=ar[k];
        }
        else l=9999;
        while(ar[i]>l)
        {
            b=1;
            for(k=d*i+b;b<=d&&k<=j;k++)
                if(ar[k]==l)i=k;
            ar[p]=ar[i];
            ar[i]=m;
            if(d*i+1<=j)
            {
                l=ar[d*i+1];b=2;
                for(k=d*i+b;b<=d&&k<=j;k++,b++)
                    if(ar[k]<l)l=ar[k];
            }
            else l=9999;
            p=i;
        }
        del(ar,j,d);
    }
}

int main()
{
    int ar[20],num,j=0,k,d;
    cout<<"\nEnter the d-value of the d-heap :";
    cin>>d;
    cout<<"\nStart entering the data for heap sort(0 to exit):";
    cin>>num;
    ar[0]=num;
    while(1)
    {
        cin>>num;
        if(num==0)
            break;
        j++;
        create(ar,j,num,d);
    }
    cout<<"\nThe elements of the list are :";
    for(k=0;k<=j;k++)cout<<ar[k]<<" ";
    cout<<"\nDsiplaying the elements after heap sort :";
    del(ar,j,d);
}
