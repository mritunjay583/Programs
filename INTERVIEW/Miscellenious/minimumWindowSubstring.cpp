#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t)
{
    if (s.size() == 0 || t.size() == 0)
        return "";

    unordered_map<char, int> m;

    for (int i = 0; i < t.size(); i++)
    {
        m[t[i]]++;
    }

    int len = INT_MAX, st = 0;

    int l = 0, r = 0;
    int n = s.size();

    int count = t.size();

    while (r < n)
    {
        m[s[r]]--;

        if (m[s[r]] >= 0)
            count--;

        r++;

        while (count == 0)
        {
            if (len > (r - l))
            {
                len = r - l;
                st = l;
            }

            m[s[l]]++;

            if (m[s[l]] > 0)
            {
                count++;
            }

            l++;
        }
    }

    if (len == INT_MAX)
        return "";
    else
        return s.substr(st, len);
}