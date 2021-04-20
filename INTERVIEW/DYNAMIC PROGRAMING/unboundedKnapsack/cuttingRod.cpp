//problems releated 
//minimum coin change
//maximum coin change
//rod cutting
//maximum ribbon cut
//stair case if order is not importants
//all these problms can be done with slight modifications


// https://practice.geeksforgeeks.org/problems/cutted-segments/0
#include<bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////
int cut(int a[],int n){
    vector<int> dp(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            if(a[j]<=i){
                if(i-a[j]==0){
                    dp[i]=max(dp[i],1);
                }else if(dp[i-a[j]]!=0){ // if dp[i-a[j]]==0 then that rod length of i is not valid for given
                                        //cutting length so in this case dp[i-a[j]]=0 
                    dp[i]=max(dp[i],dp[i-a[j]]+1);
                }
            }
        }
    }
    return dp[n];
}
//////////////////////////////////////////////////////////////////////////////////
//this approach can be used to find minimum coin change or maximum coin change
int cut(int n,int a[],int i,vector<vector<int> > &dp){
    
    if(n==0){ //if no part of rod is left then it should be one of the cutting combination
        return 0;
    }
    if(n<0 || i<=0){ // if there is still part of rod left then that combination of cut is invalid
        return INT_MIN;
    }

    if(dp[i][n]!=-1)return dp[i][n]; //memoization
    
    if(a[i-1]>n){ //if current cut if greater than lenth of remaining rod length then recur for next cut
        return dp[i][n]=cut(n,a,i-1,dp);
    }
    //select the current cut or not select current cut and take maximum of both the case
    return dp[i][n]=max(1+cut(n-a[i-1],a,i,dp),cut(n,a,i-1,dp)); 
    
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[3];
	    for(int i=0;i<3;i++)
	        cin>>a[i];

	   vector<vector<int> > dp(4,vector<int>(n+1,-1)); // dp table for memoization
	   int res=cut(n,a,3,dp);
	   cout<<res<<endl;
	}
	return 0;
}

// input sample

// 2
// 4
// 2 1 1
// 5
// 5 3 2