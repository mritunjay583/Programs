// https://codeforces.com/contest/343/problem/B
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '-')
        {
            int f = 0;
            while (st.size() > 0 && st.top() == '-')
            {
                f = 1;
                st.pop();
            }
            if (f == 0)
                st.push(s[i]);
        }
        else if (s[i] == '+')
        {
            int f = 0;
            while (st.size() > 0 && st.top() == '+')
            {
                f = 1;
                st.pop();
            }
            if (f == 0)
                st.push(s[i]);
        }
    }
    if (st.size() == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}