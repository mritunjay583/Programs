// https://www.spoj.com/problems/ONP/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<char> op;
        stack<string> va;
        unordered_map<char, int> ma;
        ma['('] = 0;
        ma['+'] = 1;
        ma['-'] = 2;
        ma['*'] = 3;
        ma['/'] = 4;
        ma['^'] = 5;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                string t = "";
                t += s[i];
                va.push(t);
                op.push(s[i]);
            }
            else if (s[i] >= 'a' && s[i] <= 'z')
            {
                string t = "";
                t += s[i];
                va.push(t);
            }
            else if (ma.count(s[i]) > 0)
            {
                if (op.size() > 0)
                {
                    if (ma[op.top()] > ma[s[i]])
                    {
                        string x = "", y = "", z = "";
                        x += va.top();
                        va.pop();
                        y += va.top();
                        va.pop();
                        z += op.top();
                        op.pop();
                        va.push(x + y + z);
                    }
                    else
                    {
                        op.push(s[i]);
                    }
                }
                else
                {
                    op.push(s[i]);
                }
            }
            else if (s[i] == ')')
            {
                string x = "", y = "", z = "";
                x += va.top();
                va.pop();
                y += va.top();
                va.pop();
                z += op.top();
                op.pop();
                va.pop();
                op.pop();
                va.push(y + x + z);
            }
        }
        cout << va.top() << endl;
    }
    return 0;
}