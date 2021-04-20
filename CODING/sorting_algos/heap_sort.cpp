#include<bits/stdc++.h>

using namespace std;

void printarr(int arr[],int size){

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

void build_heap(int arr[],int bound){

    for(int k=bound/2;k>=0;k--){
        int j=k;
        int a=j,b=j;
        int flag;
        int temp;
        while((2*j+1 <= bound)|| (2*j+2 <= bound)){
            
            flag=0;
            if(2*j+1<=bound){
                if(arr[j]<arr[2*j+1]){
                    a=2*j+1;
                    flag=1;
                }
            }
            if(2*j+2<=bound){
                if(arr[j]<arr[2*j+2]){
                    b=2*j+2;
                    flag=1;
                }
            }
            if(!flag){
                break;
            }
            if(arr[a]>arr[b]){
                temp=a;
            }
            else{
                temp=b;
            }
            swap(arr[j],arr[temp]);
            j=temp;
        }
    }
}

void heap_sort(int arr[],int size){
    for(int i=size-1;i>=1;i--){
        build_heap(arr,i);     //building max heap 
        swap(arr[0],arr[i]);   // extraction purpose
    }    
}



int main()
{
    int arr[]={5,3,6,2,7,9,0,1,45,7,5,34,76,543,34,65,43,534,100};
    int size=sizeof(arr)/sizeof(arr[0]);
    printarr(arr,size);
    heap_sort(arr,size);
    printarr(arr,size);

}