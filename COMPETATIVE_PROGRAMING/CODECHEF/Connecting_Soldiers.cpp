// https://www.codechef.com/problems/NOKIA
// https://discuss.codechef.com/t/nokia-editorial/314
#include <bits/stdc++.h>
using namespace std;

// void solve(vector<int> &v, int last, int sum, int &mi, int n, int m)
// {
//     if (last == n + 1)
//     {
//         if (m >= sum)
//             mi = min(mi, m - sum);
//         return;
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         if (v[i] == 0)
//         {
//             v[i] = last;
//             int j = i - 1;
//             int cnt = 0;
//             while (j >= 0 && v[j] == 0)
//             {
//                 j--;
//             }
//             cnt += i - j;
//             j = i + 1;
//             while (j < n + 2 && v[j] == 0)
//             {
//                 j++;
//             }
//             cnt += j - i;
//             solve(v, last + 1, sum + cnt, mi, n, m);
//             v[i] = 0;
//         }
//     }
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, m;
//         cin >> n >> m;
//         vector<int> v(n + 2, 0);
//         v[0] = -1;
//         v[n + 1] = -1;
//         int mi = INT_MAX;
//         solve(v, 1, 0, mi, n, m);
//         if (mi == INT_MAX)
//             cout << "-1" << endl;
//         else
//             cout << mi << endl;
//     }
//     return 0;
// }




long long int solve(long long int st, long long int en)
{
    if (st > en)
        return 0;
    long long int mid = (st + en) / 2;
    return (en - st + 2) + solve(st, mid - 1) + solve(mid + 1, en);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        long long int mi = 0;
        mi += solve(1, n);
        long long int mx = ((n + 1) * (n + 2)) / 2;
        mx--;
        if (mi > m)
            cout << "-1" << endl;
        else if (m > mx)
            cout << m - mx << endl;
        else
            cout << "0" << endl;
    }
    return 0;
}

// long long int mi=ceil(log(n+1)*(n+1));  //you can calcuate minimum required rope eaisy by this formulla