// https://www.geeksforgeeks.org/find-the-maximum-repeating-number-in-ok-time/

// Given an array of size n, the array contains numbers in range 
// from 0 to k-1 where k is a positive integer and k <= n. 
// Find the maximum repeating number in this array. For example, 
// let k be 10 the given array be 
// arr[] = {1, 2, 2, 2, 0, 2, 0, 2, 3, 8, 0, 9, 2, 3}, 
// the maximum repeating number would be 2. Expected time complexity 
// is O(n) and extra space allowed is O(1). 
// Modifications to array are allowed.
#include<bits/stdc++.h>

using namespace std;


// O(n) time and O(1) extra space approach

void max_repeating_number(int a[],int n,int k)
{
    for(int i=0;i<n;i++)
    {
        a[a[i]%k]+=k;
    }
    int max_val=max_element(a,a+n)-a;
    cout<<max_val<<endl;
}

int main()
{
    int a[]={1, 2, 2, 2, 0, 2, 0, 2, 3, 8, 0, 9, 2, 3};
    int n=sizeof(a)/sizeof(a[0]);
    int k=10;
    max_repeating_number(a,n,k);
}