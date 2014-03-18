//Sorting Methods

#include<iostream>
using namespace std;

int* array(int);//done
void input(int*,int);//done
void output(int*,int);//done

int* bubble_sort(int*,int);//done
int* select_sort(int*,int);//done
int* insert_sort(int*,int);//done

int* shell_sort(int*,int);//done
int* merge_sort(int*,int);//done

int* heap_sort(int*,int);
int* quick_sort(int*,int);
int* radix_sort(int*,int);

int* heap(int*,int);//done
int* merge(int*,int,int*,int);//done

main()
{
        /*int n;
        cout<<"Enter n = ?\b";
        cin>>n;

        int *Num=array(n);
        input(Num,n);
        */
        int Num[10]={10,9,7,8,5,6,4,3,1,2};
        int n=10;
        output(Num,n);

        //int *NewNum=insert_sort(Num,n);
        //output(NewNum,n);
        merge_sort(Num,n);
        output(Num,n);
}

int* array(int n)
{
    int *A=new int [n];
    return A;
}

void input(int* A, int n)
{
    cout<<"Enter "<<n<<" data..."<<endl;
    for(int i=0;i<n;++i)
    cin>>A[i];
}

void output(int* A,int n)
{
    cout<<"The Array is..."<<endl;
    for(int i=0;i<n;++i)
    cout<<A[i]<<",";
    cout<<"\b."<<endl;
}

int* bubble_sort(int* A,int n)
{
    int i,j,T;
    for(i=0;i<n-1;++i)
    for(j=0;j<n-i-1;++j)
    if(A[j]>A[j+1])
    {
        T=A[j];
        A[j]=A[j+1];
        A[j+1]=T;
    }
    return A;
}

int* select_sort(int* A,int n)
{
    int i,j,pos,T;
    for(i=0;i<n-1;i++)
    {
        pos=i;

        for(j=i+1;j<n;j++)
        if(A[pos]>A[j])
        pos=j;

        T=A[i];
        A[i]=A[pos];
        A[pos]=T;
    }
    return A;
}

int* insert_sort(int* A,int n)
{
    int i,j,T;
    for(i=1;i<n;i++)
    {
        T=A[i];

        for(j=i;j>0&&T<A[j-1];j--)
        A[j]=A[j-1];

        A[j]=T;
    }
    return A;
}

int* heap(int* A,int n)
{
    int i,j,p,T;
    for(i=1;i<n;i++)
    {
        cout<<"*";
        p=(i-1)/2;
        cout<<A[i];
        for(j=i;j>0;p=(p-1)/2)
        {
            cout<<'$';
            if(A[j]<A[p])
            {
                cout<<"@";
                T=A[j];
                A[j]=A[p];
                A[p]=T;
                j=p;
            }
            else
            break;
        }
    }
    return A;
}

int* shell_sort(int* A,int n)
{
    int i,j,g,T;
    for(g=n/2;g>0;g/=2)
    {
        for(i=g;i<n;i++)
        {
            T=A[i];

            for(j=i;j>=g&&T<A[j-g];j-=g)
            A[j]=A[j-g];

            A[j]=T;
        }
    }
    return A;
}

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
