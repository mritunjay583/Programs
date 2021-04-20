#include<bits/stdc++.h>
using namespace std;

int maxSub(int a[],int n){
    int i=0;
    int j=0;
    int mxSum=INT_MIN;
    int sum=a[j++];
    while(j<2*n){
        if(a[j]<sum+a[j]){
            sum+=a[j];
        }else{
            sum=a[j];
        }
        if(j-i>=n){
            sum=sum-a[i];
            i++;
        }
        cout<<sum<<" ";
        mxSum=max(mxSum,sum);
        j++;
    }
    cout<<endl;
    return sum;
}
int main()
{
    int a[]={8,-8,9,-9,10,-11,12};
    int n=sizeof(a)/sizeof(a[0]);
    int b[2*n];
    for(int i=0;i<2*n;i++)
    {
        b[i]=a[i%n];
        cout<<b[i]<<" ";
    }
    cout<<endl;
    int res=maxSub(b,n);
    cout<<res<<endl;
}