// https://practice.geeksforgeeks.org/problems/coin-change/0

// Coin Change

// Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins. The order of coins doesn’t matter. For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.

// Input:
// The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'M' denoting the size of array. The second line contains M space-separated integers A1, A2, ..., AN denoting the elements of the array. The third line contains an integer 'N' denoting the cents.

// Output:
// Print number of possible ways to make change for N cents.

// Constraints:
// 1 ≤ T ≤ 50
// 1 ≤ N ≤ 300
// 1 ≤ A[i] ≤ 300

// Example:
// Input:
// 2
// 3
// 1 2 3
// 4
// 4
// 2 5 3 6
// 10

// Output:
// 4
// 5

// Explanation:
// Testcase 1: The possiblities are as such: {1, 1, 1, 1}, {1, 1, 2}, {1, 3}, {2, 2}.

//solve it later
#include<iostream>
using namespace std;

int ways2(int *a,int n,int m)
{
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[m+1];
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=0;
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 && j==0)
                dp[i][j]=1;
            else if(j==0)
                dp[i][j]=1;
            else if(i==0)
                dp[i][j]=0;
            else 
            {
                int x=0,y=0;
                if(j<=a[i])
                    x=dp[i][j-a[i]];

            }
            
            
        }
    }
}


int ways(int *a,int m,int itr,int **dp)
{
    
    if(m==0)
        return 1;
        
    if(itr<0)
    
        return 0;
        
    if(itr>=0 && m<0)
        return 0;
    if(dp[itr][m]!=-1)
        return dp[itr][m];

    int consider= ways(a,m-a[itr],itr,dp); // consider a[itr] in denomination
    int notConsider =ways(a,m,itr-1,dp);   // not considerring a[itr] in denomination
    dp[itr][m]=consider + notConsider;
    return dp[itr][m];
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)cin>>a[i];
	    int m;
	    cin>>m;
	    int **dp=new int*[n+1];

        // creating dp array to memoize
	    for(int i=0;i<=n;i++)
	    {
	        dp[i]=new int[m+1];
	        for(int j=0;j<=m;j++)
	        {
	            dp[i][j]=-1;
	        }
	    }
	    int res=ways(a,m,n-1,dp);
	    
	    
	    cout<<res<<endl;
	}
	return 0;
}