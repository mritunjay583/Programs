#include<bits/stdc++.h>
using namespace std;
int getbig(int **c,int n)
{
    c[0][0]=500;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

int main()
{
    int n;
    cin>>n;
    int **c=new int*[n];
    for(int i=0;i<n;i++)
    {
        c[i]=new int[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            c[i][j]=rand()%100;
        }
    }
    getbig(c,n);
    for(int i=0;i<n;i++)
    delete[] c[i];

    delete[] c;
}