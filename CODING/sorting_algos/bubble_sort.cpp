#include<bits/stdc++.h>

using namespace std;

void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubble_sort2(int arr[],int size){
    int i=size-1;
    while(i>0){
        int t=0;
        for(int j=0;j<=i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                t=j;
            }
        }
        i=t-1;
    }
}
void bubble_sort1(int arr[],int size){
    for(int i=size-1;i>=1;i--){
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int  main()
{
    int arr[]={5,1,2,9,3,4,1,7,8,3,4,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    printarr(arr,size);
    bubble_sort2(arr,size);
    printarr(arr,size);
     
}