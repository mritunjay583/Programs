#include <bits/stdc++.h>
#define ma 1000000007
using namespace std;

long long power(long long a, long long b, long long m)
{
    if (b == 0)
        return 1;
    if (a == 0)
        return 0;
    long long temp = 1;
    while (b)
    {
        if (b & 1)
        {
            temp = ((temp % m) * (a % m)) % m;
        }
        b >>= 1;
        a = ((a % m) * (a % m)) % m;
    }
    return temp;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        long long y = power(b, c, ma - 1);
        long long x = power(a, y, ma);
        cout << x << endl;
    }
    return 0;
}