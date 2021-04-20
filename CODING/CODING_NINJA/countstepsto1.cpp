// Given a positive integer n, find the minimum number of steps s, 
// that takes n to 1. 
// You can perform any one of the following 3 steps.

// 1.) Subtract 1 from it. (n= n - ­1) ,
// 2.) If its divisible by 2, divide by 2.( if n%2==0, then n= n/2 ) ,
// 3.) If its divisible by 3, divide by 3. (if n%3 == 0, then n = n / 3 ). 

// Input format :
// Line 1 : A single integer i.e. n

#include<bits/stdc++.h>
using namespace std;

int mi=INT_MAX;
void countstepsto1(int n,int cnt)                  
{
    if(n<=1)
    {
        if(cnt<mi)
        mi=cnt;
        return;
    }
    countstepsto1(n-1,cnt+1);
    
    if(n%2==0)
    countstepsto1(n/2,cnt+1);
    
    if(n%3==0)
    countstepsto1(n/3,cnt+1);
}
///////////////////////////////////////////////////
int dpcountstepsto1(int n)
{
    int arr[n+1]={0};
    arr[0]=0;
    arr[1]=0;
    for(int i=2;i<=n;i++)                         
    {
        int a=INT_MAX;
        int b=INT_MAX;
        int c=INT_MAX;
        a=arr[i-1]+1;
        if(i%2==0)
        b=arr[i/2]+1;
        if(i%3==0)
        c=arr[i/3]+1;
        arr[i]=min(c,min(a,b));
    }
    return arr[n];
}


int main()
{
    int n=50;
    countstepsto1(n,0);
    cout<<dpcountstepsto1(n)<<endl;
    cout<<mi<<endl;
}