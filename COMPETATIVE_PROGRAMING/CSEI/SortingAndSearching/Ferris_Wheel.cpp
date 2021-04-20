#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    int cnt = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
        sum += a[i];
        if (sum > x)
        {
            cnt++;
            sum = a[i];
        }
    }
    cout << cnt;
    return 0;
}