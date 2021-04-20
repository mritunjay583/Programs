#include<bits/stdc++.h>

using namespace std;

void print(int arr[],int size)
{    
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void insertion_sort(int arr[],int size)
{
    for(int i=1;i<size;i++)
    {
        int j=i-1;
        int temp=arr[i];
        while(j>=0 && arr[j]>arr[j+1])
        {
            swap(arr[j],arr[j+1]);
            j--;
        }
        arr[j+1]=temp;
    }
}


int main()
{
    int arr[]={2,1,5,4,3,8,7,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    print(arr,size);
    insertion_sort(arr,size);
    print(arr,size);
}