#include<bits/stdc++.h>

using namespace std;
int rbound(int arr[],int size,int target)
{
    int low=0;
    int high=size-1;
    int res;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]<=target)
        {
            res=mid;
            low=mid+1;
        }
        else if(arr[mid]>target)
        {
            high=mid-1;
        }
    }
    return res;
}

int lbound(int arr[],int size,int target)
{
    int low=0;
    int high=size-1;
    int res;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]>=target)
        {
            res=mid;
            high=mid-1;
        }
        else if(arr[mid]<target)
        {
            low=mid+1;
        }
    }
    return res;
}

int main()
{
    int arr[]={0,0,0,0,0,0,0,1,1,1,1,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k=1;
    int arr_index_less_than_1=lbound(arr,size,k);
    int arr_index_greater_than_1=rbound(arr,size,k);
    cout<<arr_index_less_than_1<<endl;
    cout<<arr_index_greater_than_1<<endl;
    cout<<"number of "<<k<<"s is : "<<arr_index_greater_than_1-arr_index_less_than_1+1<<endl;

}

/// this code if failing if k is not in array
// i have to fix it but i will fix it later