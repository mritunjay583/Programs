#include<bits/stdc++.h>

using namespace std;

int binarySearch(int a[],int n){
    int low=0;
    int high=n-1;
    int mid;
    while(low<=high){
        mid=low+(high-low)/2;
        int x=(mid+1)%n;
        int y=(mid+n-1)%n;
        if(a[mid]<a[x] && a[mid]<a[y]){
            return mid;
        }
        else if(a[mid]<a[high]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return mid;
}

int main(){
    int a[]={7,8,9,10,11,12,0,1,2,3,4,5,6};
    int n=sizeof(a)/sizeof(a[0]);
    int number_of_rotations_in_array=binarySearch(a,n);
    cout<<number_of_rotations_in_array<<endl;
}