#include<bits/stdc++.h>

using namespace std;

int f(int x)    // monotonic increaing function
{
    return x*x-10*x-20;
}

int binarySearch(int low,int high)
{
    int res;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(f(mid)==0)
        {
            return mid;
        }
        if(f(mid)>0)
        {
            high=mid-1;
            res=mid;
        }
        else if(f(mid)<0)
        {
            low=mid+1;
        }
    }
    return res;
}

int findPoint()
{
    //  first finding range where 0 < f(x) <= 0 
    int i=1;
    while(f(i)<=0)
    {
        i*=2;
    }

    int low=i/2;
    int high=i;
    int res=binarySearch(low,high);
    return res;
}

int main()
{
    int point=findPoint();
    cout<<"f(x)=3*x-100 will be positive first time at "<<point<<endl;
}