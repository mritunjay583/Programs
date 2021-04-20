// Given an integer n, break it into smaller numbers such that their summation is equal to n.
//  Print all such combinations in different lines.
// Note : [1, 2, 1] and [1,1, 2] are same, so print the particular sequence with increasing order.
//  Order of different combinations doesn't matter.

////////////////////////////////////////
//the problem is same sas coin change//
//////////////////////////////////////
#include<bits/stdc++.h>

using namespace std;

vector<int> v;
void breakNumberHelper(int n,int arr[],int index)
{
    if(n<0 || index<=0)
    {
        return;
    }
    if(n==0)
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }
    v.push_back(arr[1]);
    breakNumberHelper(n-arr[1],arr,index);
    v.pop_back();
    breakNumberHelper(n,arr+1,index-1);
    // return;
}


void breakNumber(int n)
{
    int arr[n+1];
    for(int i=0;i<=n;i++)
    {
        arr[i]=i;
    }
    breakNumberHelper(n,arr,n);
}
int main()
{
    int n=5;
    breakNumber(n);
}