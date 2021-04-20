#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a[]={1,2,4,5,6};
    int size=sizeof(a)/sizeof(a[0]);
    int b[size+1]={0};
    
    //prior work

    b[0]=0;
    int i=0;
    
    while(i<size)
    {
        b[i+1]=b[i]+a[i];
        i++;
    }
    
    //printing array
    
    for(int i=0;i<size+1;i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
}