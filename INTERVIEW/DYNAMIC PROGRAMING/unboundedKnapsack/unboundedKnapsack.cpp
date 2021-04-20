#include<bits/stdc++.h>

using namespace std;


///most optimized
////////////////////////////////////////////////////////////////////////////////////////////
int unbounded_knapsack_4(int val[],int wt[],int W,int n){
    int dp[W+1]={0};
    dp[0]=0;
    for(int i=1;i<=W;i++){
        for(int j=0;j<n;j++){
            if(wt[j]<=i)
                dp[i]=max(dp[i],dp[i-wt[j]]+val[j]);
        }
    }
    return dp[W];
}

/////////////////////////////////////////////////////////////////////////////////////////////
int unbounded_knapsack_3(int val[],int wt[],int W,int n){
    int **dp=new int*[n+1];
        for(int i=0;i<=n;i++){
            dp[i]=new int[W+1];
            for(int j=0;j<=W;j++){
                if(i==0 || j==0)
                dp[i][j]=0;
            }
        }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
             if(wt[i-1]>j){
                 dp[i][j]=dp[i-1][j];
             }
             else{
                 dp[i][j]=max(val[i-1]+dp[i]/*dp[i-1] for 01 knapsack*/[j-wt[i-1]],
                             dp[i-1][j]);
             }
        }
    }
    return dp[n][W];
}

////////////////////////////////////////////////////////////////////////////////////////
int _helper(int val[],int wt[],int W,int i,int **dp){
    //you have to take excat weight not less than W is required, then
        // if(W<0) return INT_MIN;
        // if(i<=0) return INT_MIN;
        // if(W==0) return 0;
    if(W <= 0){
        return 0;
    }
    if(i<=0){
        return 0;
    }
    if(dp[i][W]!=-1)return dp[i][W];

    if(wt[i-1]>W){
        return dp[i][W]=_helper(val,wt,W,i-1,dp);
    }
    return dp[i][W]=max(val[i-1]+_helper(val,wt,W-wt[i-1],i,dp),_helper(val,wt,W,i-1,dp));
}

int unbounded_knapsack_2(int val[],int wt[],int W,int n){
    int **dp=new int*[n+1];
        for(int i=0;i<=n;i++){
            dp[i]=new int[W+1];
            for(int j=0;j<=W;j++){
                dp[i][j]=-1;
            }
        }
    return _helper(val,wt,W,n,dp);
}

//////////////////////////////////////////////////////////////////////////////////////
int unbounded_knapsack(int val[],int wt[],int W,int i){
    if(W <= 0){
        return 0;
    }
    if(i<0){
        return 0;
    }
    if(wt[i]>W){
        return unbounded_knapsack(val,wt,W,i-1);
    }
    int x=val[i]+unbounded_knapsack(val,wt,W-wt[i],i);   
    int y=unbounded_knapsack(val,wt,W,i-1);
    return max(x,y);
}
////////////////////////////////////////////////////////////////////////////////////////

int main(){
    int val[]={10, 40, 50, 70};
    int wt[]={1, 3, 4, 5};
    int W=8;
    int n=sizeof(val)/sizeof(val[0]);

    int res1=unbounded_knapsack(val,wt,W,n-1);
    int res2=unbounded_knapsack_2(val,wt,W,n);
    int res3=unbounded_knapsack_3(val,wt,W,n);
    int res4=unbounded_knapsack_4(val,wt,W,n);
    cout<<res1<<endl;
    cout<<res2<<endl;
    cout<<res3<<endl;
    cout<<res4<<endl;
}