#include<bits/stdc++.h>
using namespace std;
#define max 1000
long long int mem[max][max]={0};  //memoize table
long long int binom(int n,int k)
{
	if(k>n)
	{
		return 0;
	}
	if(k>n-k)
	{
		k=n-k;
	}
	if(k==0||n==k)
	{
		mem[n][k]=1;
	}
	if(mem[n][k])
	{
		return mem[n][k];
	}
	else
		mem[n][k]=binom(n-1,k-1)+binom(n-1,k);
	return mem[n][k];
}
int main()
{
	cout<<binom(1,0);
	
}
