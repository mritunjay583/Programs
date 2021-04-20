// https://www.interviewbit.com/problems/min-jumps-array/
// https://www.youtube.com/watch?v=vBdo7wtwlXs
#include<bits/stdc++.h>

using namespace std;


//O(n) of complexity
int jump_2(vector<int> &A) {
    if(A[0]==0){
        if(A.size()==1)
            return 0;
        else
            return -1;
    }
    int ladder=A[0];
    int stairs=A[0];
    int jump=1;
    for(int i=1;i<A.size();i++){
        if(i==A.size()-1)
            return jump;
        if(A[i]+i>ladder)
            ladder=A[i]+i;
        stairs--;
        if(stairs==0){
            jump++;
            stairs=ladder-i;
            ladder=ladder-i;
            if(ladder<=0)
                return -1;
        }
    }
    return jump;
}


//O(n*2) solution
int jump(vector<int> &A) {
    //base case
    if(A[0]==0){
        if(A.size()==1)
            return 0;
        else
            return -1;
    }
    vector<int> dp(A.size(),INT_MAX);
    dp[0]=0;
    for(int i=1;i<A.size();i++){
        for(int j=i-1;j>=0;j--){
            if(A[j]==0) continue;
            if(A[j]+j>=i){  
                dp[i]=min(dp[i],dp[j]);
            }
        }
        dp[i]++;
    }
    return dp[A.size()-1]==INT_MAX?-1:dp[A.size()-1];
}


int main(){
    vector<int> v{2,3,1,1,4};
    cout<<jump(v)<<endl;
}