// https://codeforces.com/contest/5/problem/C
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int mx = 0;
    int cnt = 1;
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push(i);
        else
        {
            st.pop();
            if (st.size() > 0)
            {
                if (mx < i - st.top())
                {
                    mx = i - st.top();
                    cnt = 1;
                }
                else if (mx == i - st.top())
                {
                    cnt++;
                }
            }
            else
            {
                st.push(i);
            }
        }
    }
    cout << mx << " " << cnt << endl;
    return 0;
}