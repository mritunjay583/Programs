#include<bits/stdc++.h>
using namespace std;


int lcs(string s1,string s2,string s3)
{
    int dp[s1.size()+1][s2.size()+1][s3.size()+1]={0};
    for(int i=0;i<=s1.size();i++)
	        for(int j=0;j<=s2.size();j++)
	            for(int k=0;k<=s3.size();k++)
	                    dp[i][j][k]=0;
	dp[0][0][0]=0;
    for(int i=0;i<=s1.size();i++)
    {
        for(int j=0;j<=s2.size();j++)
        {
            for(int k=0;k<=s3.size();k++)
            {
                if(i==0 || j==0 || k==0)
                    dp[i][j][k]=0;
                else if((s1[i-1]==s2[j-1]) && (s3[k-1]==s1[i-1]))
                    dp[i][j][k]=1+dp[i-1][j-1][k-1];
                else
                    dp[i][j][k]=max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
            }
        }
    }
    return dp[s1.size()][s2.size()][s3.size()];
    
}
int main()
{
    string s1 = "geeks"; 
    string s2 = "geeksfor";
    string s3 = "geeksforgeeks";

    int res=lcs(s1,s2,s3);
        cout<<res<<endl;
}
