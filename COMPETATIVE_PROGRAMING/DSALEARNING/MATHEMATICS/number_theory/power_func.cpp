#include<bits/stdc++.h>
using namespace std;

long long int itr_power(int x,int n)
{
    long long int res=1;
    while(n>0)
    {
        if(n&1)
            res*=x;
        x=x*x;
        n>>=1;
    }
    return res;
}
long long int power(int x,int n)
{
    if(n==0)
        return 1;
    if(x==0)
        return 0;
    long long int temp=power(x,n/2);
    if(n%2==0)
        return temp*temp;
    else
        return x*temp*temp;
        // you can also do return x*power(x,n-1);
        // complexity will be same
}

int main()
{
    int x=16;
    int n=6;
    long long int res=power(x,n);
    cout<<res<<endl;
    cout<<itr_power(x,n)<<endl;
}