// https://www.geeksforgeeks.org/wildcard-pattern-matching/

#include<bits/stdc++.h>

using namespace std;

int bottomUpisMatch(const string A, const string B) {
    vector<vector<bool> > dp(A.size()+1,vector<bool> (B.size()+1,false));
    
    dp[0][0]=true;
    for(int i=1;i<=B.size();i++){
        if(B[i-1]=='*'){
            dp[0][i]=dp[0][i-1];
        }
    }
    for(int i=1;i<=A.size();i++){
        for(int j=1;j<=B.size();j++){
            if(B[j-1]=='*'){
                dp[i][j]=dp[i-1][j] || dp[i][j-1];
            }else if((A[i-1]==B[j-1]) || B[j-1]=='?'){
                dp[i][j]=dp[i-1][j-1];
            }else dp[i][j]=false;
        }
    }
    return dp[A.size()][B.size()];
}

int solve(const string &A,const string &B,int i,int  j,vector<vector<bool> > &dp){
    if(i==0 && j==0){
        return true;
    }
    if(i==0){
        if(B[j-1]=='*')
            return solve(A,B,i,j-1,dp);
        else
            return false;
    }
    if(j==0)
        return false;
        
    if(dp[i][j]==false){
        return false;
    }
    
    if(B[j-1]=='*'){
        return dp[i][j]=solve(A,B,i-1,j,dp) || solve(A,B,i,j-1,dp);
    }else if(B[j-1]=='?'){
        return dp[i][j]=solve(A,B,i-1,j-1,dp);
    }else{
        if(A[i-1]==B[j-1]){
            return dp[i][j]=solve(A,B,i-1,j-1,dp);
        }else{
            return dp[i][j]=false;
        }
    }
    
}

int isMatch(const string A, const string B) {
    
    vector<vector<bool> > dp(A.size()+1,vector<bool>(B.size()+1,true));
    return solve(A,B,A.size(),B.size(),dp);
}

int main(){
    string A="ab";
    string B="?*";
    cout<<isMatch(A,B);
}
