#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string S)
{

    int n = S.size();
    if (n < 2)
        return S;
    for (int i = 0; i < n - 1; i++)
    {
        if (S[i] == S[i + 1])
        {
            S.erase(i, 1);
            return removeDuplicates(S);
        }
    }
    return S;
}