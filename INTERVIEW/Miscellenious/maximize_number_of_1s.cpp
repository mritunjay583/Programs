// https://practice.geeksforgeeks.org/problems/maximize-number-of-1s/0
#include<iostream>
using namespace std;
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

    // solution to this problem
	    int cnt=0;
	    int left=0;
	    int right=0;
	    int ans=0;

	    while(right<n){
	        if(cnt<=m){
	            if(a[right]==0)
	                cnt++;
	            right++;
	        }
	        if(cnt>m){
	            if(a[left]==0)
	                cnt--;
	            left++;
	        }
	        if((ans<(right-left)) && cnt<=m){
	            ans=right-left;
	        }
	    }
	    cout<<ans<<endl;
	    
	}
	return 0;
}


//sample input
//// 1
// 11
// 1 0 0 1 1 0 1 0 1 1 1
// 2
