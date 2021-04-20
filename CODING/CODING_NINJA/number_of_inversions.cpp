#include<bits/stdc++.h>
using namespace std;

void printarr(long long arr[],long long size){
    for(long long i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int merge(long long arr[],long long start,long long mid,long long end){
    long long k=0;
    long long a[end-start+1];
    long long i=start,j=mid;
    long long cnt=0;
    while((i<=mid-1) && (j<=end)){    
        if(arr[i]<=arr[j]){
            a[k++]=arr[i++];
        }
        else{
            a[k++]=arr[j++];
            cnt+=(mid-i);
            
        }
    }
    while(i<=mid-1){
        a[k++]=arr[i++];
    }
    while(j<=end){
        a[k++]=arr[j++];
    }
    for(long long x=start,y=0;x<=end;){
        arr[x++]=a[y++];
    }
    return cnt;
}

int merge_sort_util(long long arr[],long long start,long long end){
    
    long long cnt=0;
    if(end>start){
    long long mid=start+(end-start)/2;
    cnt+=merge_sort_util(arr,start,mid);
    cnt+=merge_sort_util(arr,mid+1,end); 
    cnt+=merge(arr,start,mid+1,end);
    }
    return cnt;
}

int inversion_count(long long arr[],long long size){
     return merge_sort_util(arr,0,size-1);
}

int main()
{
    // int arr[]={2,1,5,6,4};
    // int size=sizeof(arr)/sizeof(arr[0]);
    long long size;
    cin>>size;
    long long arr[size];
    for(long long  i=0;i<size;i++){
        cin>>arr[i];
    }
    printarr(arr,size);
    cout<<inversion_count(arr,size)<<endl;
    printarr(arr,size);
}