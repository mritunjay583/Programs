#include<bits/stdc++.h>

using namespace std;

///program to make maxHeap

void helper(int a[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && a[largest]<a[left])  //if left child is greater
        largest=left;
    if(right<n && a[largest]<a[right])  //if right child is greater
        largest=right;
    if(largest!=i){
        swap(a[largest],a[i]);   //swap parent with smallest child
        helper(a,n,i);  //call hipify for swapped child
    }
}

void buildHeap(int a[],int n){
    for(int i=n/2-1;i>=0;i--){ //start hipification form last-1 level
        helper(a,n,i);
    }
}
void heapSort(int a[],int n){
    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        helper(a,i,0);
    }
}
int main(){
    int a[]={5,1,7,3,9,10,4};
    int n=sizeof(a)/sizeof(a[0]);
    buildHeap(a,n);
    heapSort(a,n);
    for(auto x:a)cout<<x<<" ";cout<<endl;
}

