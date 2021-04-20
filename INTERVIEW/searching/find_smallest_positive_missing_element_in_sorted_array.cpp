#include<bits/stdc++.h>

using namespace std;

int find_num(int arr[],int low,int high)
{
    if(low>high)
    return low;
    int mid=(low+high)/2;
    // if(mid==arr[mid]) then move to right subarray
    if(mid==arr[mid])
    return find_num(arr,mid+1,high);
    else //else move to right subaary
    return find_num(arr,low,mid-1);
}

int main()
{
    int arr[]={0,1,2,3,4,5,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    int smallest_missing_number=find_num(arr,0,size-1);
    cout<<smallest_missing_number<<endl;
}