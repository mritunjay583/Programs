#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back

int32_t main()
{
    int n, i, cur, q, l, r, x;
    stack<int> stk;
    cin >> n;
    vector<int> a(n), v[n], nge(n);
    for (i = 0; i < n; ++i)
        cin >> a[i];
    for (i = 0; i < n; ++i)
    {
        while (!stk.empty() && a[stk.top()] < a[i])
            nge[stk.top()] = i, stk.pop();
        stk.push(i);
    }
    while (!stk.empty())
        nge[stk.top()] = -1, stk.pop();
        
    for(auto x:nge)
    cout<<x<<" ";
    cout<<"\n";
 
    for (i = 0; i < n; ++i)
    {
        cur = i;
        while (cur != -1 && nge[cur] < n)
            v[i].pb(cur), cur = nge[cur];
        v[i].pb(n);
    }
    cout<<"\n";
    for(i=0;i<n;++i)
    {
        cout<<i<<": ";
        for(auto x:v[i])
        cout<<x<<" ";
        cout<<"\n";
    }
    // cin >> q;
    // for (; q; --q)
    // {
    //     cin >> l >> r;
    //     cout<<"["<<l<<" , "<<r<<"]"<<" : "; 
    //     x = upper_bound(all(v[l]), r) - v[l].begin();
    //     cout << x << "\n";
    // }
    return 0;
}