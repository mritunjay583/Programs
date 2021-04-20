// Replace every array
// element by multiplication of previous and next

// Given an array of integers, update every element with multiplication of 
//previous and next elements with following exceptions.
// a) First element is replaced by multiplication of first and second.
// b) Last element is replaced by multiplication of last and second last.
#include<bits/stdc++.h>

using namespace std;

void modify(long long int a[],int n)
{
    int mx_val=*max_element(a,a+n)+1;
    a[0]=(a[0]%mx_val)+((a[1]%mx_val)*(a[0]%mx_val))*mx_val;
    for(int i=1;i<n-1;i++)
    {
        a[i]=(a[i]%mx_val)+((a[i-1]%mx_val)*(a[i+1]%mx_val))*mx_val;
    }
    a[n-1]=(a[n-1]%mx_val)+((a[n-1]%mx_val)*(a[n-2]%mx_val))*mx_val;
    for(int i=0;i<n;i++)cout<<a[i]/mx_val<<" ";cout<<endl;
}

int  main()
{
    long long int a[]={2, 3, 4, 5, 6};
    int size=sizeof(a)/sizeof(a[0]);
    modify(a,size);
}