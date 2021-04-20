#include<bits/stdc++.h>

using namespace std;

//space O(1) and time O(1)
//this problem is similar to climbing stair but it case when str[i] becomes 0 messed
int numDecodings2(string A){
    if(A.size()<1 || A[0]=='0') return 0;
    
    int first=1;
    int second=1;
    int third=1;

    for(int i=2;i<=A.size();i++){
        if(A[i]=='0')
            third=0;
        else 
            third=second;
        if((A[i-2]=='1') || (A[i-2]=='2' && A[i-1] < '7'))
            third+=first;
        
        first=second;
        second=first;
    }
    return third;
    
}
int numDecodings(string A) {
    vector<int> dp(A.size()+1,0);
    dp[0]=1;
    dp[1]=1;
    if(A[0]=='0')   return 0;
    const int mod=1000000007;
    for(int i=2;i<=A.size();i++){
        if(A[i-1]=='0')
            dp[i]=0;
        else if(A[i-1]>'0')
            dp[i]=dp[i-1];
        if((A[i-2]=='1') || (A[i-2]=='2' && A[i-1] < '7'))
            dp[i]=(dp[i]%mod + dp[i-2]%mod)%mod; 
    }
    return dp[A.size()%mod];
}

int main(){
    string str="50";
    cout<<numDecodings(str)<<endl;
}
