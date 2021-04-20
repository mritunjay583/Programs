#include<bits/stdc++.h>

using namespace std;

int maxLen(int A[],int n,int k)
{
    unordered_map<int,int> ma;
    int len=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        if((sum%k+k)%k==0)
            len=i+1;
        if(ma.count((sum%k+k)%k)>0)
        {
            len=max(len,i-(ma[(sum%k+k)%k]));
        }
        if(ma.count((sum%k+k)%k)==0)
            ma[(sum%k+k)%k]=i;
    }
	        
    return len;
}


int main()
{
    int a[]={-2,2,-5,12,-11,-1,7};
    int k=3;  // ans -> {5,1,-1,2}
    int size=sizeof(a)/sizeof(a[0]);
    cout<<maxLen(a,size,k)<<endl;
}
