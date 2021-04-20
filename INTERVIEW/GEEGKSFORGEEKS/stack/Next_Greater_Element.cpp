#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	    long long int a[]={4,2,5,1,5};
        int n=sizeof(a)/sizeof(a[0]);
	    long long int b[n];
	    b[n-1]=-1;
	    stack<long long int> st;
	    st.push(a[n-1]);
	    for(int i=n-2;i>=0;i--)
	    {  
	        while(st.empty()==false && st.top()<a[i])
	            st.pop();
	       b[i]=st.empty()?-1:st.top();
	       st.push(a[i]);
	    }
	    for(int i=0;i<n;i++)cout<<b[i]<<" ";cout<<endl;

	return 0;
}