#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int dp[1001][1001];

long long sol(vector<vector<char>> &mat, int i, int j, int n)
{
    if (i < n && j < n)
    {
        if (mat[i][j] == '*')
        {
            return 0;
        }
    }
    if (i == n - 1 && j == n - 1)
    {
        return 1;
    }
    if (i >= n || j >= n)
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = (sol(mat, i + 1, j, n) % mod + sol(mat, i, j + 1, n) % mod) % mod;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> mat(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << sol(mat, 0, 0, n) << endl;
    return 0;
}