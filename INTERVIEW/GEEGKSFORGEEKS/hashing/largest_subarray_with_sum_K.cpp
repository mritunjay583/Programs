// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int maxLen(int A[],int n,int k)
{
    unordered_map<int,int> ma;
    int sum=0;
    int mx=0;
    for(int i=0;i<n;i++)
    {           

        sum+=A[i];  
        if(sum==k)    
            mx=max(mx,i+1);
        else if(ma.count(sum-k)>0)  
            mx=max(mx,i-ma[sum-k]); 
        if(ma.count(sum)==0)
            ma[sum]=i;  /// it should not 
                        // be updated so that it can give 
                        //largest subarray
    }
    return mx;
}


int main()
{
    int a[]={1,2,3,-3,-2,-1,4,1,0,1};
    int k=3;  // ans -> {5,1,-1,2}
    int size=sizeof(a)/sizeof(a[0]);
    cout<<maxLen(a,size,k)<<endl;
}
