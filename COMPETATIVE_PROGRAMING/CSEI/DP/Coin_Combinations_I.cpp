#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int dp[1000004];

long long sol(int c[], int n, int x)
{
    if (x == 0)
    {
        return 1;
    }
    if (x < 0)
    {
        return 0;
    }
    if (dp[x] != -1)
        return dp[x];
    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt = ((cnt % mod) + (sol(c, n, x - c[i]))) % mod;
    }
    return dp[x] = cnt;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, x;
    cin >> n >> x;
    int c[n];
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    cout << sol(c, n, x);
    return 0;
}