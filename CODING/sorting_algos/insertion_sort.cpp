#include<bits/stdc++.h>

using namespace std;

void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void insertion_sort(int arr[],int size){
    for(int i=1;i<size;i++){
        int t=arr[i];                       
        int j=i-1;
        while(t<arr[j] && j>=0){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=t;
    }
}

int  main()
{
    int arr[]={5,1,2,9,3,4,1,7,8,3,4,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    printarr(arr,size);
    insertion_sort(arr,size);
    printarr(arr,size);
     
}