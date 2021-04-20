#include<bits/stdc++.h>

using namespace std;


// this approach is useful when you want to exponent a matrix;

void power(int x,int n,long long &res)
{
    if(n==0)
    {
        res=res*1;
        return;
    }
    power(x,n/2,res);  
    res*=res;
    if(n&1)
    {
        res*=x;
    } 
}


int main()
{
    int x=2;
    int n=5;
    long long res=1;
    power(x,n,res);
    cout<<res<<endl;
}