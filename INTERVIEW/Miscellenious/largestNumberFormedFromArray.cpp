// https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array/0

#include<iostream>
#include<bits/stdc++.h>
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
	    
	    sort(a,a+n,[](int a,int b)->bool{
	        string x=to_string(a);
	        string y=to_string(b);
	        string xy=x+y;
	        string yx=y+x;
	        return  xy>yx?1:0;
	    });
	    for(int i=0;i<n;i++)cout<<a[i];cout<<endl;
	}
	return 0;
}

//sample input
// 2
// 5
// 3 30 34 5 9
// 4
// 54 546 548 60