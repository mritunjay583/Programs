#include <bits/stdc++.h>
#define MAX 1000001
#define mod 1000000007
using namespace std;

bool isComposite[MAX];
vector<int> primes;
void seive()
{
    for (int i = 2; i * i <= MAX; i++)
    {
        if (isComposite[i] == false)
        {
            primes.push_back(i);
            for (int j = i * i; j <= MAX; j += i)
            {
                isComposite[j] = true;
            }
        }
    }
}

int main()
{
    seive();
    long long n;
    cin >> n;
    unordered_map<int, int> ma;
    for (int i = primes.size() - 1; i >= 0 && n != 1; i--)
    {
        if (n % primes[i] == 0)
        {
            int cnt = 0;
            while (n != 1 && n % primes[i] == 0)
            {
                cnt++;
                n /= primes[i];
            }
            ma[primes[i]] = cnt;
        }
    }
    if (n != 1)
        ma[n] = 1;
    return 0;
}