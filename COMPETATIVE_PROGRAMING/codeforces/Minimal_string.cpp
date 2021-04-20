// http://codeforces.com/contest/797/problem/C

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

void solve(string s)
{
    bool a[s.size()];
    stack<char> st;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        while (st.size() > 0 && st.top() >= s[i])
        {
            st.pop();
        }
        bool y = st.size() == 0 ? false : true;
        a[i] = y;
        st.push(s[i]);
    }
    stack<char> temp;
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (a[i] == true)
        {
            temp.push(s[i]);
        }
        else
        {
            res += s[i];
        }
    }
    while (temp.size() > 0)
    {
        res += temp.top();
        temp.pop();
    }
    cout << res << endl;
}

int main()
{
    string s;
    cin >> s;
    solve(s);
    return 0;
}