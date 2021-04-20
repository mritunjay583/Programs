#include<bits/stdc++.h>

using namespace std;

void triplet1(int arr[],int size,int target){
    sort(arr,arr+size);
    for(int i=0;i<size-2;i++){
        int l=i+1;
        int r=size-1;
        int new_target=target-arr[i];
        while(l<r){
            if((arr[l]+arr[r])==new_target){
                cout<<arr[i]<<" "<<arr[l]<<" "<<arr[r]<<endl;
                l++;
                r--;
            }
            else if((arr[l]+arr[r])>new_target){
                r--;
            }
            else{
                l++;
            }
            
        }
    }
}
int main()
{
    int arr[]={1,2,3,4,5,6,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    int target=12;
    triplet1(arr,size,target);
}