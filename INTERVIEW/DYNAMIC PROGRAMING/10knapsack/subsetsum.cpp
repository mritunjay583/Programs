#include<bits/stdc++.h>

using namespace std;


///////////////////////////////////////////////////////////////////////////
///dynamic programing approach////////////////////////////////////////////
bool dp_is_possible(int a[],int n,int sum){

        bool **dp=new bool*[n+1];
        for(int i=0;i<=n;i++){
            dp[i]=new bool[sum+1];
            for(int j=0;j<=sum;j++){
                //if sum==0 and no item will be selected
                if(i==0 && j==0)
                    dp[i][j]=true;
                else if(i==0 || j==0)
                    dp[i][j]=false;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(a[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j-a[i-1]] || dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
}


////////////////////////////////////////////////
//simple brute force solution//////////////////
bool is_possible(int a[],int i,int sum){
    
    if(sum < 0 ){
        return false;
    }

    if(sum==0){
        return true;
    }
    
    if( i < 0 ){
        return false;
    }
    
    return is_possible(a,i-1,sum-a[i]) || is_possible(a,i-1,sum); 
}
int main(){
    int a[]={3, 34, 4, 12, 5, 2};
    int n=sizeof(a)/sizeof(a[0]);
    int sum=12;
    
    cout<<is_possible(a,n-1,sum)<<endl;
    cout<<dp_is_possible(a,n,sum)<<endl;
}