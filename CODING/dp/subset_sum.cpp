#include<bits/stdc++.h>

using namespace std;


int subset_sum(int a[],int i,int sum)
{
    if(i<0)
    return 0;
    if(sum==0)
    return 1;
    return subset_sum(a,i-1,sum-a[i-1])+subset_sum(a,i-1,sum);
}


int main()
{
    int arr[]={1,2,3,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=7;
    int  res=subset_sum(arr,n,sum);
    cout<<res<<endl;
}