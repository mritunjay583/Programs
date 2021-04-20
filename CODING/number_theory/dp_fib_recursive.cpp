#include<bits/stdc++.h>

using namespace std;
#define max 10000
long long int fib[max]={0};
long long int fibo(int n)
{
	if(n==0)
	{
		fib[n]=1;
	}
	if(n==1)
	{
		fib[n]=1;
	}
	
	if(fib[n])
	{
		return fib[n];
	}
	fib[n]=fibo(n-1)+fibo(n-2);
	return fib[n];
}
int main()
{
	int i;
	for(i=0;i<92;i++)
	{
		printf("%20lld\n",fibo(i));
	}
}
