// https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x/0
#include<bits/stdc++.h>

using namespace std;


int b1(int a[],int i,int j,int x){
    int low=i;
    int high=j;
    int res=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(a[mid]==x){
            res=mid;
            high=mid-1;   // here is the main variation
        }
        else if(a[mid]>x){
            high=mid-1;
        }
        else low=mid+1;
    }
    return res;
}
int b2(int a[],int i,int j,int x){
    int low=i;
    int high=j;
    int res=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(a[mid]==x){
            res=mid;
            low=mid+1;   // here is the main variation
        }
        else if(a[mid]>x){
            high=mid-1;
        }
        else low=mid+1;
    }
    return res;
}

int main(){
    int a[]={1,3,5,5,5,5,67,123,125};
    int n=sizeof(a)/sizeof(a[0]);
    int x=5;
    int first_occurance=b1(a,0,n-1,x);
    int second_occurance=b2(a,0,n-1,x);
    if(first_occurance==-1 || second_occurance==-1){
        cout<<"-1"<<endl;
    }else
    cout<<first_occurance<<" "<<second_occurance<<endl;
}