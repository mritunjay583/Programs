#include<bits/stdc++.h>

using namespace std;

void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int partition(int arr[],int start,int end){
    int i=start-1;
    int j=start;
    int pivot_index=end;
    while(j<end){
        if(arr[j]<arr[pivot_index]){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    swap(arr[i+1],arr[pivot_index]);
    return i+1;
}


void quick_sort_util(int arr[],int start,int end){
    
    if(start<end){
    
    
    int pivot=partition(arr,start,end);
    quick_sort_util(arr,start,pivot-1);
    quick_sort_util(arr,pivot+1,end);
    
    }
}
void quick_sort(int arr[],int size){
    quick_sort_util(arr,0,size-1);
}

int  main()
{
    int arr[]={5,1,2,9,3,8,7,6,2,1,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<size<<endl;
    printarr(arr,size);
    quick_sort(arr,size);
    printarr(arr,size); 
}