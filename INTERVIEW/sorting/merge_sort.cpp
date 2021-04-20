#include<bits/stdc++.h>

using namespace std;

void print(int arr[],int size)
{    
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void merge(int arr[],int left,int mid,int right)
{
    // print(arr,right-left+1);
    int size=right-left+1;
    // cout<<size<<endl;
    int temp[size]={0};
    int i=left;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=right)
    {
        if(arr[i]>arr[j])
        {
            temp[k++]=arr[j++];
        }
        else
        {
            temp[k++]=arr[i++];
        }
    }
    while(i<=mid)
    temp[k++]=arr[i++];
    while(j<=right)
    temp[k++]=arr[j++];
    for(int l=left;l<=right;l++)
    {
        arr[l]=temp[l-left];
    }
}

void merge_sort(int arr[],int low,int high)
{
    if(low==high)
    return;
    int mid=(low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
}


int main()
{
    int arr[]={2,1,5,4,3,8,7,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    print(arr,size);
    merge_sort(arr,0,size-1);
    print(arr,size);
}

