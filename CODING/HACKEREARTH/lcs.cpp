#include<bits/stdc++.h>
using namespace std;

int lcsHelper(string s1,int i,string s2,int j,vector<vector<int>> &dp)
{
    if(i==0 || j==0)
    {
        dp[i][j]=0;
        return dp[i][j];
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(s1[i-1]==s2[j-1])
    {
        dp[i][j]=1+lcsHelper(s1,i-1,s2,j-1,dp);
    }
    else
    {
        dp[i][j]=max(lcsHelper(s1,i-1,s2,j,dp),lcsHelper(s1,i,s2,j-1,dp));
    }
    return dp[i][j];
}

int lcs(string s1,string s2)
{
    
    vector<vector<int> > dp(s1.size()+1,vector<int> (s2.size()+1,-1));
    return lcsHelper(s1,s1.size(),s2,s2.size(),dp);
}

int main()
{
    string s1="AGGTAB";
    string s2="GXTXAYB";
    cout<<lcs(s1,s2);
}