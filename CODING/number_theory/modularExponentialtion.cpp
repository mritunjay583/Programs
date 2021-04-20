//Evaluating (x^y)%p

#include<bits/stdc++.h>

using namespace std;

long long int modularexp(long long int x,long long int y,long long int p)
{
	long long int res=1;
	x=x%p;
	while(y)
	{
		if(y&1)
			res=(res*x)%p;
		y>>=1;
		x=(x*x)%p;
	}
	return res;
}

int main()
{
	cout<<modularexp(2,13123123,1000007);
}

