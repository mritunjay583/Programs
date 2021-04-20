// you can only take 1,2 3 steps to complete the stair case

#include<bits/stdc++.h>
#define maxi 8
using namespace std;


//////////////////////////////////////////////////////////////////////
// BOTTOM UP DP  /////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

int dp_stair_case(int n)  // you can eaisy extend to 4, 5 and so on
{
    int dp[n+1]={0};
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[n];
}

//////////////////////////////////////////////////////////////////////
///// RECURSIVE SOLUTION //////////////////
//////////////////////////////////////////////////////////////////////
int stair_case(int n)
{
    if(n==0 || n==1)
    return 1;
    if(n==2)
    return 2;
    return stair_case(n-1)+stair_case(n-2)+stair_case(n-3);
    
}

////////////////////////////////////////////////////////////////////
//////RECURCISE WITH MEMOIZATION / TOP TO BOTTOM DP ////////////////
////////////////////////////////////////////////////////////////////

int dp[maxi+1]={0};
int top_dp_stair_case(int n)
{
    if(n<2)
    {
        dp[n]=1;
        return dp[n];
    }
    if(n==2)
    {
        dp[n]=2;
        return dp[n];
    }

    if(dp[n])
    {
        return dp[n];
    }
    return stair_case(n-1)+stair_case(n-2)+stair_case(n-3);
}


int main()
{

    // int result=stair_case(maxi);
    // cout<<result<<endl;
    cout<<dp_stair_case(maxi)<<endl;
    cout<<stair_case(maxi)<<endl;
    cout<<top_dp_stair_case(maxi)<<endl;
}