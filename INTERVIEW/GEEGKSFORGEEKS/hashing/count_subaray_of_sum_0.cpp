#include<bits/stdc++.h>
using namespace std;

int CountallSubarray(int arr[],int size)
{
    unordered_map<int,int> ma;
    int sum=0;
    int cnt=0;
    for(int i=0;i<size;i++)
    {
        sum+=arr[i];
        if(sum==0)
            cnt+=1;
        if(ma.count(sum)>0)
        {
            cnt+=ma[sum];
        }
        ma[sum]++;
    }
    return cnt;
}

int main()
{
    int arr[]={0,0,5,5,0,0};
    int size=sizeof(arr)/sizeof(arr[0]);
    int res=CountallSubarray(arr,size);
    cout<<res<<endl;
}