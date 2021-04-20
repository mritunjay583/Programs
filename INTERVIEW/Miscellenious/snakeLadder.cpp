// https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem/0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        unordered_map<int, int> ma;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            ma[a] = b;
        }
        queue<array<int, 2>> q;
        q.push({1, 0});
        int res = 0;
        while (q.size() > 0)
        {
            array<int, 2> t = q.front();
            q.pop();
            if (t[0] == 30)
            {
                res = t[1];
                break;
            }
            for (int i = t[0]; i <= 6 + t[0]; i++)
            {
                if (ma.count(i) > 0)
                {
                    if (ma[i] > i)  //choosing only ladder
                    {
                        q.push({ma[i], t[1] + 1});
                    }
                }
                else
                {
                    q.push({i, t[1] + 1});
                }
            }
        }
        cout << res << endl;
    }
}