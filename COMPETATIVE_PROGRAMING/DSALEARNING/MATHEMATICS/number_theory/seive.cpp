#include<bits/stdc++.h>
#define mx 1000001
using namespace std;

bool isPrime[mx];// boolean aray to store staus

void seive()
{
    for(int i=0;i<mx;i++)
    {
        isPrime[i]=true;
    }
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=mx;i++)
    {
        if(isPrime[i]==true)
        {
            for(int j=i*i;j<=mx;j+=i)
            {
                isPrime[j]=false;
            }
        }
    }
}

int main()
{
    seive();
    int n=1000;
    int cnt=0;
    for(int i=2;i<=n;i++)
    {
        if(isPrime[i])
            cnt++;
    }
    cout<<"total primes less than " <<n<<" = "<<cnt<<endl;
}