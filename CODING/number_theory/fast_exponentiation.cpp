#include<bits/stdc++.h>

using namespace std;

//iterative algorithm

long long int itrpowerof(long long int x,long long int y)
{
	long long int res=1;
	while(y)
	{
		if(y&1)
		res*=x;
		y>>=1;
		x*=x;
	}
	return res;
}

//recursive algorithm

long long int repowerof(long long int x,long long int y)
{
	if(y==0)
	return 1;
	long long int temp=repowerof(x,y/2);
	
	if(y%2==0)
	return temp*temp;
	else
	return x*temp*temp;
}

int main()
{
	cout<<itrpowerof(2,10);
}
