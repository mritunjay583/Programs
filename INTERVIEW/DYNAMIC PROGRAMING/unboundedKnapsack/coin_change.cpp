#include<bits/stdc++.h>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////
int coin_change_4(int coins[],int m,int n){
    int dp[m+1]={0};
    dp[0]=1;//if there is no money then chnage will be equal to 1 because of not giving change
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            if(coins[i]<=j){ 
                dp[j]=dp[j]+dp[j-coins[i]]; //main step to count
            }
        }
    }
    return dp[m];
}
///////////////////////////////////////////////////////////////////////////////////////////
int coin_change_3(int coins[],int m,int n){
    
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 && j==0){
                dp[i][j]=1;
            }
            else if(i==0){
                dp[i][j]=0;
            }else if(j==0){
                dp[i][j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(coins[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j] + dp[i][j-coins[i-1]];
            }
        }
    }
    return dp[n][m];
}

/////////////////////////////////////////////////////////////////////////////////////////

int _coin_change(int coins[],int m,int n,int **dp){
    if( n == 0 || m < 0){
        return 0;
    }
    if(m==0){
        return 1;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(coins[n-1]>m){
        dp[n][m]=_coin_change(coins,m,n-1,dp);
        return dp[n][m];
    }
    dp[n][m]=_coin_change(coins,m-coins[n-1],n,dp)+_coin_change(coins,m,n-1,dp);
    return dp[n][m];
}

int coin_change_2(int coins[],int m,int n){
    int **dp=new int*[n+1];
    for(int i=0;i<n+1;i++){
        dp[i]=new int[m+1];
        for(int j=0;j<m+1;j++){
            dp[i][j]=-1;
        }
    }
    int res=_coin_change(coins,m,n,dp);
}

////////////////////////////////////////////////////////////////////////////////////////

int main(){
    int coins[]={2, 5, 3, 6};
    int n=sizeof(coins)/sizeof(coins[0]);
    int m=10;
    int res2=coin_change_2(coins,m,n);
    int res3=coin_change_2(coins,m,n);
    cout<<res2<<endl;
    cout<<res3<<endl;
    
    
}