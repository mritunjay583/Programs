#include<bits/stdc++.h>
#define max 10000000

using namespace std;

long long int primes[max]={0}; //tempory array to store primes

///seive algorithm to generate prime list
void seive()
{
	for(long long int i=2;i*i<max;i++)
	{
		for(long long int j=i;i*j<max;j++)
		{
			primes[i*j]=1;
		}
	}
}

//function to find factors
map<long long int,long long int> findFactor(long long int n,vector<long long int> prime)
{
	map<long long int,long long int> m;
	long long int pf=prime[0];
	long long int i=0;
	while(pf*pf<=n)
	{
		while(n%pf==0)
		{
			m[pf]++; 
			n=n/pf;
		}
		pf=prime[++i];
	}
	if(n!=1)
	{
		if(n%pf==0)
		m[pf]++;
		else
		m[n]++;
	}
	return m;
}

int main()
{
	//geneating primes
	seive();
	
	vector<long long int> prime;
	
	map<long long int,long long int> factors;  // map to store factors
	
	//storing generated primes in prime vector 
	
	for(int i=2;i<max;i++)
	{
		if(!primes[i])
		{
			prime.push_back(i);
		}
	}
	
	//input
	
	long long int number=34235235234324;
	
	//calling findFactor function
	
	factors=findFactor(number,prime);
	
	map<long long int,long long int> :: iterator i;
	for(i=factors.begin();i!=factors.end();i++)
	{
		cout<<i->first<<" -> "<<i->second<<endl;
	}
}
