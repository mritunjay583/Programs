// https://www.geeksforgeeks.org/find-the-first-missing-number/


//Given a ||sorted|| array of n distinct integers 
// where each integer is in the range from 0 to m-1 and m > n.
//  Find the smallest number that is missing from the array
#include<bits/stdc++.h>

using namespace std;



//This method doesn’t work 
// if there are duplicate elements in the array
int smallest_missing_number(int a[],int n,int m)
{
    int low=0;
    int high=n-1;
    while(low<high)
    {
        int mid=(low+high)/2;
        if(mid==a[mid])
        {
            low=mid+1;
        }
        else if(mid<a[mid])
        {
            high=mid-1;
        }
    }
    return low;
}

int main()
{
    int a[]={0, 1, 2, 6, 9};   //0<=a[i]<<m-1
    int m=10;
    int n=sizeof(a)/sizeof(a[0]);
    int id=smallest_missing_number(a,n,m);
    cout<<id<<endl;
}