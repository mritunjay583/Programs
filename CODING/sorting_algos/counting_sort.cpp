#include<bits/stdc++.h>

using namespace std;

void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void counting_sort(int arr[],int size){
    
    
}



int main()
{
    int arr[]={5,1,2,9,3,4,1,7,8,3,4,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    printarr(arr,size);
    counting_sort(arr,size);
    printarr(arr,size);
    
}