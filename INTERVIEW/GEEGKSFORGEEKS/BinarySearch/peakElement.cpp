// https://www.geeksforgeeks.org/find-a-peak-in-a-given-array/
#include<bits/stdc++.h>

using namespace std;

int peakElement(int arr[], int n)
{
    if(n==0)return arr[0];
   int low=0;
   int high=n-1;
   while(low<=high){
       int mid=low+(high-low)/2;
       if(mid==0 && arr[mid]>arr[mid+1]){
           return mid;
       }
       else if(mid==n-1 && arr[mid]>arr[mid-1]){
           return mid;
       }else if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
           return mid;
       }else if(arr[mid]<arr[mid+1]){
           low=mid+1;
       }else{
           high=mid-1;
       }
   }
}
int main(){
    int arr[]={5, 10, 20, 15};
    int n=sizeof(arr)/sizeof(arr[0]);
    int index_of_peak_element=peakElement(arr,n);
    cout<<arr[index_of_peak_element]<<endl;
}