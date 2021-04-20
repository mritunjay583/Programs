#include<bits/stdc++.h>

using namespace std;

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    int t=lower_bound(arr,arr+size,20)-arr;
    cout<<t<<endl;
}