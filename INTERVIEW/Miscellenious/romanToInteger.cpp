#include <bits/stdc++.h>
using namespace std;
int romanToint(string s)
{
    if (s.size() == 0)
        return 0;
    unordered_map<char, int> ma;
    ma['I'] = 1;
    ma['V'] = 5;
    ma['X'] = 10;
    ma['L'] = 50;
    ma['C'] = 100;
    ma['D'] = 500;
    ma['M'] = 1000;
    if (s.size() == 1)
    {
        return ma[s[0]];
    }
    int i;
    int sum = 0;
    for (i = 0; i < s.size() - 1; i++)
    {
        if (ma[s[i]] >= ma[s[i + 1]])
        {
            sum += ma[s[i]];
        }
        else
        {
            sum -= ma[s[i]];
        }
    }
    if (i == s.size() - 1)
        sum += ma[s[i]];
    return sum;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int res = romanToint(s);
        cout << res << endl;
    }
    return 0;
}