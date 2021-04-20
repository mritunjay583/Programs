// https://practice.geeksforgeeks.org/problems/two-numbers-with-sum-closest-to-zero/0
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> \t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);

        int l = 0, h = n - 1;
        int asum = 0, mx = INT_MAX;

        while (l < h)
        {
            asum = a[l] + a[h];
            if (abs(asum) < abs(mx))
                mx = asum;
            else if (asum < 0)
                l++;
            else
                h--;
        }
        cout << mx << endl;
    }
}