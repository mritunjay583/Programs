#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
    int n, x;
    cin >> n >> x;
    int c[n];
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    vector<long long> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (c[i] <= j)
                dp[j] = (dp[j] % mod + dp[j - c[i]] % mod) % mod;
        }
    }
    cout << dp[x] << endl;
    return 0;
}