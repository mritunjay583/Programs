// https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/

#include<bits/stdc++.h>
using namespace std;


int minimum_coin_1(int coins[],int v,int n){
    if(v==0){
        return 0;
    }
    int res=INT_MAX;
    for(int i=0;i<n;i++){
        if(coins[i]<=v){
            int sub_res=minimum_coin_1(coins,v-coins[i],n);
            if(sub_res!=INT_MAX && sub_res + 1<res){
                res=sub_res+1;
            }
        }
    }
    return res;
}
//////////////////////////////////////////////////////////////////////////////////////////////
int minimum_coin_2(int coins[],int v,int n){
    int dp[v+1]; // dp table to store minimmum number of coin for ith V cents
    dp[0]=0; // when there is no cent then minimmum number of coin will be zero
    for(int i=1;i<=v;i++){
        dp[i]=INT_MAX; //inilitially infinte coins are required for ith V cents
    }
    
    for(int i=1;i<=v;i++){ // making query for ith V cents
        for(int j=0;j<n;j++){ // looping through all the coins available
            if(coins[j]<=i){ // make change if value of jth coin is less than ith V cents
                int res=dp[i-coins[j]];
                if(res!=INT_MAX && res+1<dp[i]){
                    dp[i]=res+1;
                }
            }
        }
    }
    if(dp[v]!=INT_MAX)
        return dp[v];
    else 
        return -1; // if not posssible then answer return -1
}
///////////////////////////////////////////////////////////////////////////////////////////////
int main()
 {
	int coins[]={9, 6, 5, 1}; // available coins
    int n=sizeof(coins)/sizeof(coins[0]);
    int v=11; // requeired denomination
    int res1=minimum_coin_1(coins,v,n);
    int res2=minimum_coin_2(coins,v,n);
    cout<<res2<<endl;
    cout<<res1<<endl;
	return 0;
}