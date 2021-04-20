#include<bits/stdc++.h>

using namespace std;

void print(int arr[],int size)
{    
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void nr_bubble_sort(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void r_bubble_sort(int arr[],int size)
{
    if(size==0)
    return;
    for(int i=0;i<size-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }
    }
    r_bubble_sort(arr,size-1);
}

int main()
{
    int arr[]={8,4,7,1,6,2,34,6,7,84,345,64,21,12};
    int size=sizeof(arr)/sizeof(arr[0]);
    print(arr,size);
    // nr_bubble_sort(arr,size);
    r_bubble_sort(arr,size);
    print(arr,size);
}