#include<bits/stdc++.h>
using namespace std;

/*

 ABCDGH
 AEDFHR

*/

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

//// this function is very important to find lcs

void print(vector<vector<int> > &dp,string s1)
{
    string str="";
    int i=s1.size();
    int j=s1.size();
    while(i>0 && j>0)
    {
        if(dp[i][j]==dp[i-1][j-1]+1)
        {
            str=s1[i-1]+str;
            i--;
            j--;
            
        }
        else if(dp[i][j]==dp[i-1][j])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout<<str<<endl;
}

int lcs(string s1,string s2)
{
    
    vector<vector<int> > dp(s1.size()+1,vector<int> (s2.size()+1,-1));
    int res=lcsHelper(s1,s1.size(),s2,s2.size(),dp);
    //printting the subsequence 
    print(dp,s1);
    return res;
}

int main()
{
    string s1="BBABCBCAB";
    string s2=s1;
    reverse(s2.begin(),s2.end());
    cout<<lcs(s1,s2);
}