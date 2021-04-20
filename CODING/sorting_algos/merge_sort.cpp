#include<bits/stdc++.h>

using namespace std;

void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(int arr[],int start,int mid,int end){
    int i=start;
    int k=0;
    int j=mid+1;
    int a[end-start+1];
    while(i<=mid && j<=end){
        if(arr[i]<arr[j]){
            a[k++]=arr[i++];
        }
        else{
            a[k++]=arr[j++];
        }
    }
    while(i<=mid){
        a[k++]=arr[i++];
    }
    while(j<=end){
        a[k++]=arr[j++];
    }
    for(int t=start,b=0;t<=end;){
        arr[t++]=a[b++];
    }
    

}

void merge_sort_util(int arr[],int start,int end){
    if(start>=end){
        return ;
    }
    int mid=start+(end-start)/2;
    merge_sort_util(arr,start,mid);
    merge_sort_util(arr,mid+1,end);
    merge(arr,start,mid,end);
}
void merge_sort(int arr[],int size){
    merge_sort_util(arr,0,size-1);
}
int  main()
{
    int arr[]={5,1,2,9,3,4,1,7,8,3,4,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    printarr(arr,size);
    merge_sort(arr,size);
    printarr(arr,size); 
}