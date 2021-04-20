#include<bits/stdc++.h>

using namespace std;
#define max 10000
long long int fib[max]={0};
long long int fibo(int n)
{
	if(n==0)
	{
		return 0;
	}
	if(n==1 || n==2)
	{
		return (fib[n]=1);
	}
	
	if(fib[n])
	{
		return fib[n];
	}
	int k=(n&1)?(n+1)/2:n/2;
	
	fib[n]=(n&1)?(fibo(k)*fibo(k)+fibo(k-1)*fibo(k-1)):((2*fibo(k-1)+fibo(k))*fibo(k));

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
