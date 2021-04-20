// https://www.spoj.com/problems/STPAR/
#include <bits/stdc++.h>
using namespace std;
bool solve(int a[], int n)
{
    stack<int> st;
    int last = 0;
    for (int i = 0; i < n;)
    {
        if (a[i] == last + 1)
        {
            last = a[i];
            i++;
            continue;
        }
        if (st.size() > 0 && st.top() == last + 1)
        {
            last = st.top();
            st.pop();
        }
        else
        {
            st.push(a[i]);
            i++;
        }
    }
    while (st.size() > 0)
    {
        if (st.top() == last + 1)
        {
            last = st.top();
        }
        else
        {
            return false;
        }
        st.pop();
    }
    if (last == n)
        return true;
    else
        return false;
}
int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        if (solve(a, n))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    return 0;
}