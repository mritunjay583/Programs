#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

int isPrime[MAX];
unordered_map<int, long long> factors;
void seive()
{
    for (int i = 2; i < MAX; i++)
    {
        if (isPrime[i] != 0)
            continue;
        isPrime[i] = i;
        for (int j = 2 * i; j < MAX; j += i)
        {
            isPrime[j] = i;
        }
    }
    for (int i = 2; i < MAX; i++)
    {
        int x = i;
        map<int, int> ma;
        while (x != 1)
        {
            ma[isPrime[x]]++;
            x /= isPrime[x];
        }
        long long res = 1;
        for (auto x : ma)
        {
            res *= (x.second + 1);
        }
        factors[i] = res;
    }
}
int main()
{
    int n;
    cin >> n;
    seive();
    while (n--)
    {
        int x;
        cin >> x;
        if (x == 1)
            cout << x << endl;
        else
            cout << factors[x] << endl;
    }
    return 0;
}