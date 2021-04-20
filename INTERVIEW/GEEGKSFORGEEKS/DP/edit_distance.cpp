#include<bits/stdc++.h>
using namespace std;



int edit_distance_2(string s,string t)
{
    int dp[2][t.size()+1];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<=t.size();j++)
            dp[i][j]=0;
    }
    for(int i=0;i<=t.size();i++)
        dp[0][i]=i;
    int f;
    for(int i=1;i<=s.size();i++)
    {
        f=i&1;
        for(int j=0;j<=t.size();j++)
        {
            if(j==0)
                dp[f][j]=i;
            else if(s[i-1]==t[j-1])
                dp[f][j]=dp[1-f][j-1];
            else if(s[i-1]!=t[j-1])
                dp[f][j]=1+min(min(dp[1-f][j],dp[f][j-1]),dp[1-f][j-1]);
        }
    }
    return dp[f][t.size()];
}

//time (m*n)
//space (m*n)

int edit_distance_1(string s,string t)
{
    int dp[s.size()+1][t.size()+1];
    dp[0][0]=0;
    for(int i=0;i<=s.size();i++)
    {
        for(int j=0;j<=t.size();j++)
        {
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(s[i-1]==t[j-1])
                dp[i][j]=dp[i-1][j-1];
            else if(s[i-1]!=t[j-1])
            {
                dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
            }
        }
    }
    return dp[s.size()][t.size()];
}

int main()
{
    string s1 = "AGGTAB"; 
    string s2 = "GXTXAYB";
    int res=edit_distance_1(s1,s2);
    int res=edit_distance_2(s1,s2);
}
