#include<bits/stdc++.h>
#include<limits.h>

using namespace std;

double divide(double x,double y)
{
    if(y==0)
    return INT_MAX; // return infinnity

    int sign=(x*y<0)?-1:1; // storing sign for final result

    x=abs(x);
    y=abs(y);
    
    double precesion=0.001;  // precision of out result

    double low=0,high=INT_MAX; // high =INT_MAX to handle 
                                // y<1
    while(1)
    {
        double mid=low+(high-low)/2;
        if(abs(y*mid-x)<=precesion)  // you cannot just equate to
        {                           //doubles 
            return sign*mid;
        }
        if(y*mid<x)
        {
            low=mid; // you cannot do mid+1 otherwise you will
        }              // loose precesion 
        else
        {              // same reason as low 
            high=mid;
        }
    }
}

int main()
{
    double res=divide(22,7);
    cout<<res;
    cout<<endl;
}