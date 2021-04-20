// https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game/0
#include<bits/stdc++.h>
using namespace std;
int solve(int a[],int i,int j,vector<vector<int> > &dp){
    if(i>j)
        return 0;
    if(i+1==j){
        return max(a[i],a[j]);
    }
    
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    return dp[i][j]=max(a[i]+min(solve(a,i+2,j,dp),solve(a,i+1,j-1,dp)),
                        a[j]+min(solve(a,i,j-2,dp),solve(a,i+1,j-1,dp)));
}
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        vector<vector<int> > dp(n+1,vector<int>(n+1,-1));
        int res=solve(a,0,n-1,dp);
        cout<<res<<endl;
    }
	return 0;
}