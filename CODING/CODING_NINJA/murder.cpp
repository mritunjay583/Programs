#include<bits/stdc++.h>

using namespace std;

int merge(int arr[],int start,int mid,int end){
    int i=start;
    int j=mid;
    int temp[end-start+1];
    int cnt=0;
    int k=0;
    while((i<=mid-1) && (j<=end)){
        if(arr[i]<arr[j]){
            cnt+=(end-j+1)*arr[i];  
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
        }
        
    }
    while(i<=mid-1){
        temp[k++]=arr[i++];
    }
    while(j<=end){
        temp[k++]=arr[j++];
    }
    for(int l=start,m=0;l<=end;){
        arr[l++]=temp[m++];
    }
    return cnt;
}

int mergesort_util(int arr[],int start,int end){
    int cnt=0;
    if(start<end){
        int mid=(start+end)/2;
        cnt+=mergesort_util(arr,start,mid);
        cnt+=mergesort_util(arr,mid+1,end);
        cnt+=merge(arr,start,mid+1,end);
        return cnt;
    }
    return cnt;
}
int less_sum_before_i(int arr[],int size)
{
    return mergesort_util(arr,0,size-1);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int res=less_sum_before_i(arr,n);
    cout<<res<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}