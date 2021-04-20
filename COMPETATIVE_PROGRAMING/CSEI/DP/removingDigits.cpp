#include <bits/stdc++.h>
using namespace std;

int dp[1000004];
int sol(int n)
{
    // cout<<n<<endl;
    if (n == 0)
    {
        return 0;
    }
    if (n / 10 == 0)
    {
        return 1;
    }
    if (dp[n] != -1)
        return dp[n];
    int mi = INT_MAX;
    int y = n;
    while (y != 0)
    {
        int x = y % 10;
        if (x != 0)
            mi = min(mi, 1 + sol(n - x));
        y = y / 10;
    }
    return dp[n] = mi;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << sol(n);
    return 0;
}