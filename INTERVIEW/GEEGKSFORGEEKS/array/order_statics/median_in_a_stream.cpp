//time O(nlogn)
//space O(n)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int median=0;
    int cnt=0;
	int n;
	cin>>n;
	priority_queue<int> pqmax;
	priority_queue<int,vector<int>,greater<int>> pqmin;
	while(n--)
	{
	    cnt++;
	    int x;
	    cin>>x;
	    if(pqmax.size()==pqmin.size())
	    {
	        if(x<median)
	        {
	            pqmax.push(x);
	            median=pqmax.top();
	        }
	        else
	        {
	            pqmin.push(x);
	            median=pqmin.top();
	        }
	    }
	    else if(pqmax.size()>pqmin.size())
	    {
	        if(x<median)
	        {
	            int t=pqmax.top();pqmax.pop();
	            pqmin.push(t);
	            pqmax.push(x);
	        }
	        else
	        {
	            pqmin.push(x);
	        }
	        median=(pqmax.top()+pqmin.top())/2;
	    }
	    else if(pqmax.size()<pqmin.size())
	    {
	        if(x>median)
	        {
	            int t=pqmin.top();pqmin.pop();
	            pqmax.push(t);
	            pqmin.push(x);
	        }
	        else
	        {
	            pqmax.push(x);
	        }
	        median=(pqmax.top()+pqmin.top())/2;
	    }
	    cout<<"median : "<<median<<endl;
	}
	return 0;
}