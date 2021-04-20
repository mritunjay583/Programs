// http://codeforces.com/problemset/problem/281/D#

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    unsigned int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    stack<unsigned int> st;
    unsigned int mx = 0;
    for (int i = 0; i < n; i++)
    {
        while (st.size() > 0)
        {
            mx = max(mx, st.top() ^ a[i]);
            if (st.top() < a[i])
                st.pop();
            else
                break;
        }
        st.push(a[i]);
    }
    cout << mx << endl;
    return 0;
}