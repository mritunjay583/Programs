#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int** a = new int*[n];
    for(int i=0;i<n;i++)
    {
        a[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<n;j++)
            {
                cout<<a[j][i]<<" ";
            }
        }
        else{
            for(int j=n-1;j>=0;j--)
            {
                cout<<a[j][i]<<" ";
            }
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        delete a[i];
    }
    delete []a;
}