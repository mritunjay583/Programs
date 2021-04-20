#include<bits/stdc++.h>

using namespace std;
int x,y,d;
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
int extendedexu(int a,int b)
{
    if(b==0)
    {
        d=a;
        x=1;
        y=0;
    }
    else
    {
        extendedexu(b,a%b);
        int temp=x;
        x=y;
        y=temp-(a/b)*y;
    }
    
}
int main()
{
    // cout<<gcd(309,21);

    extendedexu(21,309);
    cout<<x<<"  "<<y<<"  "<<d;

}