
// this is called quick left rotation 
// time O(1)
// space O(2*n)
// used when multiple queries of left rotation comes
#include<bits/stdc++.h>

using namespace std;
int count_rotation(int a[],int n,int d)
{
    int t[2*n]={0};
    for(int i=0;i<2*n;i++)
    {
        t[i]=a[i%n];
    }
    int start=d%n;
    for(int i=start;i<start+n;i++)
    {
        cout<<t[i]<<" ";
    }
}

int main()
{
    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    int d=1;
    count_rotation(a,n,d);
}