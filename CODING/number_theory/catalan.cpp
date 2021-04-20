#include<bits/stdc++.h>
#define max 10000
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

long long int catalian(int n)
{
	return binomial(2*n,n)/(n+1);
}

int main()
{
	int n=10;
	for(int i=0;i<n;i++)
	{
		cout<<catalian(i)<<" ";
	}
	cout<<endl;
	return 0;
}
