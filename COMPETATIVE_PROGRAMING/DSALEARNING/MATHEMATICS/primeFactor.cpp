#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int prime_factor[N + 5];
//prime_factor[x] = the largest prime factor of x

vector<pair<int, int>> prime_factors[N + 5];
// first = prime    |  second = exponenet
//ex: - 100 = {{2,2},{5,2}}    =>  pow(2,2)*pow(5,2) = 100

int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (prime_factor[i] != 0)
            continue;
        prime_factor[i] = i;
        for (int j = 2 * i; j <= n; j += i)
        {
            prime_factor[j] = i;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        int x = i;
        map<int, int> ma;
        while (x != 1)
        {
            ma[prime_factor[x]]++;
            x /= prime_factor[x];
        }
        for (auto t : ma)
        {
            prime_factors[i].push_back({t.first, t.second});
        }
    }
    
    for (int i = 2; i <= n; i++)
    {
        cout << i << " : ";
        for (auto t : prime_factors[i])
        {
            cout << "(" << t.first << "," << t.second << ") ";
        }
        cout << endl;
    }
}
