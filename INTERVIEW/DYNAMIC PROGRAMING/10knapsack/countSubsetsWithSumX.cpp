
#include<bits/stdc++.h>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////
int count_subsets_3(int a[],int n,int sum){
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[sum+1];
        for(int j=0;j<=sum;j++){
            if(i==0 && j==0){
                dp[i][j]=1;
            }
            else if(i==0){
                dp[i][j]=0;
            }
            else if(j==0){
                dp[i][j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(a[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j] + dp[i-1][j-a[i-1]];
            }
            
        }
    }
    return dp[n][sum];
}

/////////////////////////////////////////////////////////////////////////////////////

int _helper(int a[],int i,int sum,int **dp){
    if(sum < 0){
        return 0;
    }

    if(sum==0){
        return 1;
    }

    if(i < 0){
        return 0;
    }
    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }

    dp[i][sum]=_helper(a,i-1,sum-a[i],dp) + _helper(a,i-1,sum,dp);
    return dp[i][sum];
}
int count_subsets_2(int a[],int n,int sum){

    int **dp=new int*[n];
    for(int i=0;i<=n;i++){
        dp[i]=new int[sum+1];
        for(int j=0;j<=sum;j++){
            dp[i][j]=-1;
        }
    }

    return _helper(a,n-1,sum,dp);
    
}

/////////////////////////////////////////////////////////////////////////////////////

int count_subsets_1(int a[],int i,int sum){
    if(sum < 0){
        return 0;
    }
    if(sum==0){
        return 1;
    }

    if(i < 0){
        return 0;
    }

    return count_subsets_1(a,i-1,sum-a[i]) + count_subsets_1(a,i-1,sum);
}
int main(){
    int a[]={3, 3, 3, 12, 5, 2};
    int n=sizeof(a)/sizeof(a[0]);
    int sum=6;

    int res1=count_subsets_1(a,n-1,sum);
    int res2=count_subsets_2(a,n,sum);
    int res3=count_subsets_3(a,n,sum);
    cout<<res1<<endl;
    cout<<res2<<endl;
    cout<<res3<<endl;
}