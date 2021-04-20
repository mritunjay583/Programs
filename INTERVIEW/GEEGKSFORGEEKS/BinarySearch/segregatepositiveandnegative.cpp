#include<bits/stdc++.h>

using namespace std;

int segregate(int a[],int n){
    int j=0;
    for(int i=0;i<n;i++){
        if(a[i]<=0){
            swap(a[i],a[j]);
            j++;
        }
    }
    return j;
}

int main(){
    int a[]={4,1,5,-1,2,-5,-6,-1,10};
    int n=sizeof(a)/sizeof(a[0]);
    int id=segregate(a,n);
    cout<<id<<endl;
    for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;
}