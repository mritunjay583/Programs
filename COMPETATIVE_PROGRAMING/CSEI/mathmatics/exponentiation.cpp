#include <bits/stdc++.h>
#define m 1000000007
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        long long a, b;
        cin >> a >> b;
        long long temp = 1;
        if (a == 0 && b == 0)
        {
            cout << "1" << endl;
            continue;
        }
        if (a == 0)
        {
            cout << "0" << endl;
            continue;
        }
        if (b == 0)
        {
            cout << "1" << endl;
            continue;
        }
        while (b)
        {
            if (b & 1)
                temp = ((temp % m) * (a % m)) % m;
            b >>= 1;
            a = ((a % m) * (a % m)) % m;
        }
        cout << temp << endl;
    }
    return 0;
}