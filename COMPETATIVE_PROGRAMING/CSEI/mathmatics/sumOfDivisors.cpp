#include <bits/stdc++.h>
#define MAX 1000001
#define mod 1000000007
using namespace std;


int main() {
	long long n;
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		sum=((sum %mod)+ ((i%mod)*((n/i)%mod)))%mod;
	}
	cout<<sum<<endl;
	return 0;
}