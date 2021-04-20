// https://www.spoj.com/problems/MMASS/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    unordered_map<char, int> ma;
    ma['C'] = 12;
    ma['H'] = 1;
    ma['O'] = 16;
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(-1);
        }
        else if (ma.count(s[i]) > 0)
        {
            st.push(ma[s[i]]);
        }
        else if (s[i] >= '2' && s[i] <= '9')
        {
            int x = st.top();
            st.pop();
            st.push(x * (s[i] - '0'));
        }
        else if (s[i] == ')')
        {
            int y = 0;
            while (st.top() != -1)
            {
                y += st.top();
                st.pop();
            }
            st.pop();
            st.push(y);
        }
    }
    int res = 0;
    while (st.size() > 0)
    {
        res += st.top();
        st.pop();
    }
    cout << res << endl;
    return 0;
}