//solution is in O(r) complexity

#include<bits/stdc++.h>

using namespace std;

long long int binomial(int n,int r)
{
	long long res=1;
	r>=n-r?n-r:r;
	for(int i=0;i<r;i++)
	{
		res*=n-i;
		res/=i+1;
	}
   return res;
}

int main()
{
	int n=4;
	for(int i=0;i<=n;i++)cout<<binomial(n,i)<<" ";cout<<endl;
}