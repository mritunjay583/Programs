#include<bits/stdc++.h>

using namespace std;

void print(int arr[],int size)
{    
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int find_pivot(int arr[],int low,int high)
{
    int i=low-1;
    int j=low;
    int p=high;
    while(j<=high)
    {
        if(arr[j]<arr[p])
        {
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    swap(arr[i+1],arr[p]);
    return i+1;
    // int i=low;
    // int j=low+1;
    // int p=arr[low];
    // while(j<=high){
    //     if(arr[j]<p){
    //         swap(arr[i++],arr[j++]);
    //     }else{
    //         j++;
    //     }
    // }
    // swap(arr[i],p);
    // return i;
}

void quick_sort(int arr[],int low,int high)
{
    if(low>high)
    return;
    int pivot=find_pivot(arr,low,high);
    quick_sort(arr,low,pivot-1);
    quick_sort(arr,pivot+1,high);

}


int main()
{
    int arr[]={0,0,5,2,0,-1,-1,5,-5};
    int size=sizeof(arr)/sizeof(arr[0]);
    print(arr,size);
    quick_sort(arr,0,size-1);
    print(arr,size);
}