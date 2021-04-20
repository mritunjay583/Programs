// https://practice.geeksforgeeks.org/problems/number-of-coins/0

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int money,n;
	    cin>>money>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    vector<long long int> dp(money+1,INT_MAX);
	    dp[0]=0;
	    for(int i=0;i<=money;i++){
	        for(int j=0;j<n;j++){
	            if(a[j]<=i){
	                dp[i]=min(dp[i],1+dp[i-a[j]]);
	            }
	        }
	    }
	    if(dp[money]==INT_MAX)
	        cout<<"-1"<<endl;
	    else cout<<dp[money]<<endl;
	}
	return 0;
}