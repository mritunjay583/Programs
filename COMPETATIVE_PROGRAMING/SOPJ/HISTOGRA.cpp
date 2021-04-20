// https://www.spoj.com/problems/HISTOGRA/
#include <bits/stdc++.h>
using namespace std;
void nextleftsmaller(long long int a[], int n, long long int left[])
{
    left[0] = 0;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (st.size() > 0 && a[st.top()] >= a[i])
        {
            st.pop();
        }
        int x = st.size() == 0 ? 0 : st.top() + 1;
        left[i] = x;
        st.push(i);
    }
}
void nextrightsmaller(long long int a[], int n, long long int right[])
{
    right[n - 1] = n - 1;
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.size() > 0 && a[st.top()] >= a[i])
        {
            st.pop();
        }
        int x = st.size() == 0 ? n - 1 : st.top() - 1;
        right[i] = x;
        st.push(i);
    }
}

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        long long int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long long int left[n];
        long long int right[n];
        nextleftsmaller(a, n, left);
        nextrightsmaller(a, n, right);
        long long int mx = 0;
        for (int i = 0; i < n; i++)
        {
            mx = max(mx, (right[i] - left[i] + 1) * a[i]);
        }
        cout << mx << endl;
    }
    return 0;
}