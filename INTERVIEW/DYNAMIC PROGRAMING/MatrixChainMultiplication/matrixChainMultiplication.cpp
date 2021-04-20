// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication/0
#include<bits/stdc++.h>
using namespace std;



/////////////////////////////////////////////////////////////////////////////////
int matrix_chain_multi_util(int mat[],int i,int j,int **dp){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int res=INT_MAX;
    for(int k=i;k<j;k++){
        int sub_res=matrix_chain_multi_util(mat,i,k,dp)+
                matrix_chain_multi_util(mat,k+1,j,dp)+
                mat[i-1]*mat[k]*mat[j];
        res=min(res,sub_res);
    }
    return dp[i][j]=res;
}

////time O(n^3) space O(n^2) 
int matrix_chain_multi(int mat[],int n){
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[n+1];
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }

    return matrix_chain_multi_util(mat,1,n-1,dp);

}
/////////////////////////////////////////////////////////////////////////////////////
int main()
 {
    int mat[]={1,2,3,4,5};
    int n=sizeof(mat)/sizeof(mat[0]);
    int res=matrix_chain_multi(mat,n);
    cout<<res<<endl;
	return 0;
}