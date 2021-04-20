#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a[]={5,3,9,11,0,2,6};
    int size=sizeof(a)/sizeof(a[0]);
    int max1=INT_MIN;
    int max2=INT_MIN;
    int max3=INT_MIN;
    for(int i=0;i<size;i++)
    {
        if(max1<a[i])
        {
            max3=max2;
            max2=max1;
            max1=a[i];
            
        }
        else if(max2<a[i] && a[i]<max1)
        {
            max3=max2;
            max2=a[i];
        }
        else max3=a[i];
    }
    cout<<max1<<" "<<max2<<" "<<max3<<endl;
}