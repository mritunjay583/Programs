#include <bits/stdc++.h>
using namespace std;

const int m = 1e9 + 7;
int main()
{
    int n, x;
    cin >> n >> x;
    int c[n];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    vector<long long int> dp(x + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i - c[j - 1] >= 0)
            {
                dp[i] = min(dp[i], 1 + dp[i - c[j - 1]]);
            }
        }
    }
    if (dp[x] == INT_MAX)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << dp[x] << endl;
    }
}