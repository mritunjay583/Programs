// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int maxLen(int A[],int n)
{
    unordered_map<int,int> ma;
    ma[0]=-1; // initial condiition 
    int sum=0;
    int mx=0;
    for(int i=0;i<n;i++)
    {               
        sum+=A[i];  
        if(ma.count(sum)>0)  
            mx=max(mx,i-ma[sum]); 
        else ma[sum]=i;  /// it is in else becase it should not
                        // be updated so that it can give 
                        //largest subarray
    }
    return mx;
}


int main()
{
    int a[]={5,1,-1,2,-1,-1,1};
    int size=sizeof(a)/sizeof(a[0]);
    cout<<maxLen(a,size)<<endl;
}
