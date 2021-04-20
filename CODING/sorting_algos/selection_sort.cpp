#include<bits/stdc++.h>

using namespace std;

void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void selection_sort(int arr[],int size){
    int k=0;
    for(int i=size-1;i>=1;i--){
        k=0;
        for(int j=1;j<=i;j++){
            if(arr[k]<arr[j]){
                k=j;
            }
        }
        swap(arr[k],arr[i]);
    }
}

int  main()
{
    int arr[]={5,1,2,9,3,4,1,7,8,3,4,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    printarr(arr,size);
    selection_sort(arr,size);
    printarr(arr,size);
     
}