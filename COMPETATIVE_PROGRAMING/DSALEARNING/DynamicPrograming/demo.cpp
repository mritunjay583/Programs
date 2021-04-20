#include <bits/stdc++.h>
using namespace std;

int dp[100][55][1400];
int solution(int prev, int l, int sum, unordered_map<int, char> &ma)
{
    if (l == 0)
    {
        if (sum == 0)
        {
            return 1;
        }
        return 0;
    }

    if (l < 0 || sum < 0 || prev >52)
    {
        return 0;
    }

    if (dp[prev][l][sum] != -1) return dp[prev][l][sum];

    return dp[prev][l][sum] = solution(prev + 1, l, sum, ma) + solution(prev + 1, l - 1, sum - (prev+1), ma);
}
int main()
{
    unordered_map<int, char> ma;
    for (char x = 'a'; x <= 'z'; x++)
    {
        ma[x - 'a' + 1] = x;
    }
    for (int y = 'A'; y <= 'Z'; y++)
    {
        ma[y - 'A' + 27] = y;
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int l, s;
        cin >> l >> s;
        long long x = (l * (l + 1)) / 2;
        if (s > 1378 || l > 52 || x > (long long)s)
        {
            cout << "0" << endl;
            continue;
        }
        memset(dp, -1, sizeof(dp));
        cout << solution(0, l, s, ma);
        cout << endl;
    }
    return 0;
}
