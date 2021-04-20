#include <bits/stdc++.h>
using namespace std;

const int m = 1e9 + 7;
long long dp[1000002];

long long sol(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    if (dp[n] != -1)
        return dp[n];
    int cnt = 0;
    for (int i = 1; i <= 6; i++)
    {
        cnt = ((cnt % m) + (sol(n - i) % m)) % m;
    }
    return dp[n] = cnt;
}

int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << sol(n) << endl;
    return 0;
}