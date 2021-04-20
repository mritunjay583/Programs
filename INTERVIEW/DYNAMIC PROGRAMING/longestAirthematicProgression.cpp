// https://www.interviewbit.com/problems/longest-arithmetic-progression/
// https://www.youtube.com/watch?v=Lm38EAoDc7c
#include<bits/stdc++.h>

using namespace std;

int solve(const vector<int> &A) {
    if(A.size()<=2)
        return A.size();
    
    int mx=2;
    vector<unordered_map<int,int> > dp(A.size());
    for(int i=0;i<A.size();i++){
        for(int j=i+1;j<A.size();j++){
            int diff=A[j]-A[i];
            if(dp[i].count(diff)>0){
                dp[j][diff]=dp[i][diff]+1;
            }else{
                dp[j][diff]=2;
            }
        
            mx=max(mx,dp[j][diff]);
        }
    }
    return mx;
}

int main(){
    vector<int> v{9, 4, 7, 2, 10};
    cout<<solve(v)<<endl;
}
