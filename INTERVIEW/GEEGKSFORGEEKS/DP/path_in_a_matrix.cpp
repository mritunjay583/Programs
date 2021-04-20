// https://practice.geeksforgeeks.org/problems/path-in-matrix/0
// Given a N X N  
// matrix Matrix[N][N] of positive integers. 
//  There are only three possible moves from a cell 
//  Matrix[r][c].

// 1. Matrix[r+1][c]

// 2. Matrix[r+1][c-1]

// 3. Matrix[r+1][c+1]

// Starting from any column in row 0, 
// return the largest sum of any of the paths up to 
// row N-1.

// Example:

// Input:
// 2
// 348 391 618 193

// Output:
// 1009

#include<iostream>
using namespace std;

int cal(int **mat,int i,int j,int n,int **dp)
{
    if(i>=n || j>=n || i<0 || j<0 )
        return 0;
        
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j]=mat[i][j]+max(max(cal(mat,i+1,j,n,dp),cal(mat,i+1,j-1,n,dp))
                        ,cal(mat,i+1,j+1,n,dp));
    
    return dp[i][j];
}
int main()
 {
        int n;
        cin>>n;
        int **mat=new int*[n];
        int **dp=new int*[n];
        for(int i=0;i<n;i++)
        {
            mat[i]=new int[n];
            dp[i]=new int[n];
            for(int j=0;j<n;j++)
            {
                cin>>mat[i][j];
                dp[i][j]=-1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int k=0;k<n;k++)
                for(int j=0;j<n;j++)
                    dp[k][j]=-1;
            ans=max(ans,cal(mat,0,i,n,dp));
        }
        cout<<ans<<endl;
        return 0;
}