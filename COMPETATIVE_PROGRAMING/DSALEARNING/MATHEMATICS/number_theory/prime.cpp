#include<bits/stdc++.h>

using namespace std;

bool isPrime(int num)
{
    if(num<=3)
    return true;
    for(int i=2;i*i<=num;i++)// complexity is
    {                       // O(sqrt(num))
        if(num%i==0)
        return false;
    }
    return true;
}
int main()
{
    int range=10000;
    cout<<"primes less than "<<range<<endl;
    for(int i=2;i<=range;i++)
    {
        if(isPrime(i))
        cout<<i<<" ";
    }
    cout<<endl;
}