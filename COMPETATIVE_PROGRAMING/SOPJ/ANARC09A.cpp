// https://www.spoj.com/problems/ANARC09A/

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k = 1;
    while (true)
    {
        string s;
        cin >> s;
        if (s[0] == '-')
        {
            break;
        }
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '{')
            {
                st.push(s[i]);
            }
            else
            {
                if (st.size() > 0 && st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        int l = 0;
        int r = 0;
        while (st.size() > 0)
        {
            if (st.top() == '{')
                l++;
            else
                r++;
            st.pop();
        }
        int cnt = 0;
        cnt += r / 2;
        cnt += l / 2;
        if (r % 2 != 0)
            cnt += 2;
        cout << k << ". " << cnt << endl;
        k++;
    }
    return 0;
}