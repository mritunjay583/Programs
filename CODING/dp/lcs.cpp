#include<bits/stdc++.h>
using namespace std;


///////////////////////////////////////////////////////////////////////////
////////////DP APPROACH///////////////////////////////////////////////////
//////////Complexity - O(m*n)/////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
int DLCS(string s1,string s2)
{
    s1=" "+s1;
    s2=" "+s2;
    int dp[s1.size()][s2.size()];

    for(int i=0;i<s1.size();i++)
    {
        for(int j=0;j<s2.size()-1;j++)
        {
            dp[i][j]=0;
        }
    }

    for(int i=1;i<s1.size();i++)
    {
        for(int j=1;j<s2.size();j++)
        {
            if(s1[i]==s2[j])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
            
        }
    }
    
    return dp[s1.size()-1][s2.size()-1];
}

/////////////////////////////////////////////////////////////////////////
///////////NAIVE APPORACH////////////////////////////////////////////////
//////////Complexity - O(2^max(m,n))/////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

int LCS(string s1,string s2,int m,int n)
{
    if(m==0 || n==0)
    return 0;
    if(s1[m-1]==s2[n-1])
    {
        return 1+LCS(s1,s2,m-1,n-1);
    }
    else
    {
        return max(LCS(s1,s2,m-1,n),LCS(s1,s2,m,n-1));
    }
    
}


int main()
{
                
                
    string s1="axc";
    string s2="ahbgdc";
    int len1=DLCS(s1,s2);
    int len2=LCS(s1,s2,s1.size(),s2.size());
    cout<<len1<<endl;
    cout<<len2<<endl;
}