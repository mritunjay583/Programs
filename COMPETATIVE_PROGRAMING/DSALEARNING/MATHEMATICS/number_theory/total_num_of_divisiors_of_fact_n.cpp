#include<bits/stdc++.h>
#define MAX 100000
using namespace std;

bool isPrime[MAX];

void seive()
{
    for(int i=0;i<MAX;i++)isPrime[i]=true;

    isPrime[0]=isPrime[1]=false;

    for(int i=2;i*i<=MAX;i++)
    {
        if(isPrime[i]==true)
        {
            for(int j=i*i;j<=MAX;j+=i)
            {
                isPrime[j]=false;
            }
        }
    }
    return;
}


void divisors_of_n(int num)
{
    cout<<"divisors of "<<num<<endl;
    cout<<"divisors -> exponent"<<endl;
    unordered_map<int,int> ma;
    int i=2;
    while(num!=1)
    {
        int cnt=0;
        while(num%i==0)
        {
            cnt++;
            num/=i;
        }
        if(cnt>0)
            ma[i]=cnt;
        i++;
    }
    for(auto x:ma)cout<<x.first<<" -> "<<x.second<<endl;
}


void divisors_of_fact_n(int num)
{
    cout<<"divisors of "<<num<<"!"<<endl;
    cout<<"divisor -> exponent"<<endl;
    for(int i=2;i<=num;i++)
    {
        if(isPrime[i]==true)
        {
            int cnt=0;
            int j=i;
            while(j<=num)
            {
                cnt+=num/j;
                j*=i;
            }
            cout<<i<<" -> "<<cnt<<endl;
        }
    }
}


int main()
{
    seive();
    int num=32;
    divisors_of_n(num);
    divisors_of_fact_n(num);
}