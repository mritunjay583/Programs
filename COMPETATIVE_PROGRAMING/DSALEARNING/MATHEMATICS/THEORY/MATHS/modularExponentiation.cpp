#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;


long long fast_exp(long long base,long long exp) {
    long long res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%MOD;
       base=(base*base)%MOD;
       exp/=2;
    }
    return res%MOD;
}
int main(){
    cout<<fast_exp(324,431243)<<endl;
}