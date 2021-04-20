#include<bits/stdc++.h>
using namespace std;




//time O(n*m)
//space O(n)
int LCS_3(string s1,string s2)
{
    vector<int> dp[2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<s2.size()+1;j++)
            dp[i].push_back(0);
    }

    int f=1;
    for(int i=1;i<s1.size()+1;i++)
    {
        f=i&1;
        for(int j=1;j<s2.size()+1;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[f][j]=1+dp[1-f][j-1];
            else
                dp[f][j]=max(dp[1-f][j],dp[f][j-1]);
        }
    }
    return dp[f][s2.size()];
}


//bottom up approach
// time O(n*m)
//space O(n*m)
int LCS_2(string s1,string s2)
{
    vector<int> dp[s1.size()+1];
    for(int i=0;i<s1.size()+1;i++)
    {
        for(int j=0;j<s2.size()+1;j++)
        {
            dp[i].push_back(0);
        }
    }

    dp[0][0]=0;
    for(int i=1;i<s1.size()+1;i++)
    {
        for(int j=1;j<s2.size()+1;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    //printting lcs
    cout<<"LCS of "<<s1<<" and "<<s2<<" : ";
    int i=s1.size();
    int j=s2.size();
    string res="";
    while(i>=1 && j>=1)
    {
        if(s1[i-1]==s2[j-1])
        {
            res+=s1[i-1];
            i=i-1;
            j=j-1;
            
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i=i-1;    
        }
        else
        {
            j=j-1; 
        }
        
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
    return dp[s1.size()][s2.size()];
}

int LCS_1_util(string s1,string s2,int i,int j,vector<int> dp[])
{
    if(i<0 || j<0)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    int ans;
    if(s1[i]==s2[j])
        ans=1+LCS_1_util(s1,s2,i-1,j-1,dp);
    else
        ans=max(LCS_1_util(s1,s2,i-1,j,dp),LCS_1_util(s1,s2,i,j-1,dp));
    
    dp[i][j]=ans;
    
    return dp[i][j];
}

// time O(m*n)
//space O(m,n)
//top down approach
int LCS_1(string s1,string s2)
{
    vector<int> dp[s1.size()];
    for(int i=0;i<s1.size();i++)
    {
        for(int j=0;j<s2.size();j++)
        {
            dp[i].push_back(-1);
        }
    }
    return LCS_1_util(s1,s2,s1.size()-1,s2.size()-1,dp);
}

int main()
{
    string s1 = "AGGTAB"; 
    string s2 = "GXTXAYB";
    int res1=LCS_1(s1,s2);
    int res2=LCS_2(s1,s2); // printing simultaneously
    int res3=LCS_3(s1,s2);
    cout<<res1<<endl;
    cout<<res2<<endl;
    cout<<res3<<endl;
}
