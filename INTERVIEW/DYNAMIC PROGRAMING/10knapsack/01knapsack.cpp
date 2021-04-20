#include<bits/stdc++.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////

int dp_knapsack(int price[],int weight[],int capacity,int n){
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[capacity+1];
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=capacity;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else{
                if(weight[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=max(price[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
                }
            }
        }
    }
    return dp[n][capacity];
}

///////////////////////////////////////////////////////////////////////////////

int knapsack(int price[],int weight[],int cur_capacity,int index,int **dp){
    
    
    if(index < 0 || cur_capacity <=0){
        return 0;
    }

    if(dp[index][cur_capacity]!=-1){
        return dp[index][cur_capacity];
    }
    if(weight[index]>cur_capacity){
        dp[index][cur_capacity]=knapsack(price,weight,cur_capacity,index-1,dp);
        return dp[index][cur_capacity];
    }
    int x=price[index] + knapsack(price,weight,cur_capacity-weight[index],index-1,dp);
    int y=knapsack(price,weight,cur_capacity,index-1,dp);
    dp[index][cur_capacity]=max(x,y);
    return dp[index][cur_capacity];
}

int memoize_knapsack(int price[],int weight[],int max_weight,int index){
    int **dp=new int*[index+1];
    for(int i=0;i<index+1;i++){
        dp[i]=new int[max_weight+1];
        for(int j=0;j<max_weight+1;j++){
            dp[i][j]=-1;
        }
    }
    return knapsack(price,weight,max_weight,index,dp);
}

///////////////////////////////////////////////////////////////////////////////////
int rec_knapsack(int price[],int weight[],int cur_capacity,int index){
    
    
    if(index < 0 || cur_capacity <=0){
        return 0;
    }

    if(weight[index]>cur_capacity){
        return rec_knapsack(price,weight,cur_capacity,index-1);
    }
    int x=price[index] + rec_knapsack(price,weight,cur_capacity-weight[index],index-1);
    int y=rec_knapsack(price,weight,cur_capacity,index-1);
    return max(x,y);
}
////////////////////////////////////////////////////////////////////////////////////

int main(){
    int price[]={1,2,3};
    int weight[]{4,5,1};
    int max_weight=4;
    int n=sizeof(price)/sizeof(price[0]);

    int res1=rec_knapsack(price,weight,max_weight,n-1);
    int res2=memoize_knapsack(price,weight,max_weight,n-1);
    int res3=dp_knapsack(price,weight,max_weight,n);
    cout<<res1<<endl;
    cout<<res2<<endl;
    cout<<res3<<endl;
}