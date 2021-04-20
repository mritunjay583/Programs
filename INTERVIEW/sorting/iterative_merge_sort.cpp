#include<bits/stdc++.h>

using namespace std;

void print(int arr[],int size)
{    
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void itr_merge_sort(int arr[],int size)
{
    int left=0;
    int right=size-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        
    }
}

int main()
{
    int arr[]={2,1,5,4,3,8,7,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    print(arr,size);
    itr_merge_sort(arr,size);
    print(arr,size);
}